/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:46:56 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 12:16:57 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	is_number(char *str)
{
	if (*str == '-')
		if (!*(++str))
			return (0);
	while (*str)
	{
		if ((*str >= '0' && *str <= '9'))
			str++;
		else
			return (0);
	}
	return (1);
}

int is_stack_contains(t_stack *stack, int num)
{
	t_data	*elem;

	if (stack->size == 0)
		return (0);

	elem = stack->top;
	while (elem)
	{
		if (elem->value == num)
			return (1);
		elem = elem->next;	
	}
	return (0);
}

void	add_data(t_stack *stack, int num)
{
	t_data	*last;

	if (!stack->top)
	{
		stack->top = malloc(sizeof(t_stack));
		stack->top->value = num;
		stack->top->next = 0;
		return ;
	}
	last = stack->top;
	while (last->next != 0)
		last = last->next;
	last->next = malloc(sizeof(t_stack));
	last->next->value = num;
	last->next->next = 0;
	return ;
}

void	args_to_stack(t_stack *stack, char **num_str)
{
	int	i;
	int	num;

	stack->top = 0;
	stack->size = 0;
	i = -1;
	while (num_str[++i] != NULL)
	{
		if (!is_number(num_str[i]))
		{
			ft_putstr_color_fd(COLOR_RED, "Error\n", 2);
			//faut free
			exit (1);
		}
		num = ft_atoi(num_str[i]);
		if (num >= INT_MIN && num <= INT_MAX && !is_stack_contains(stack, num)) // faut fix ca aussi
		{
			add_data(stack, num);
			stack->size ++;
		}
		else
		{
			ft_putstr_color_fd(COLOR_RED, "Error\n", 2);
			//faut free
			exit (1);
		}
	}
	return ;
}

int	bigest_number(t_stack *stack)
{
	int	number;
	t_data			*elem;

	elem = stack->top;
	number = elem->value;
	while (elem->next != 0)
	{
		ft_printf("faux RA\n");
		elem = elem->next;
		if (elem->value > number)
			number = elem->value;
	}	
	return (number);
}

void	negatif(t_stack *a, t_stack *b, int nb)
{
	int	i;

	i = a->size;
	while (nb)
	{
		if (a->top->value < 0)
		{
			nb--;	
			pb(a,b);
		}
		else
			ra(a);
	}
	while (b->size)
		pa(a,b);		
}

int	set_index(t_stack *a)
{
	unsigned int	add;
	t_data			*current;
	t_data			*temp;
	int				i;
	int				j;

	i = 0;
	current = a->top;
	while (i++ < a->size)
	{
		j = 0;
		temp = a->top;
		while (j++ < a->size)
		{
			if (temp->value < current->value)
				current->index++;
			temp = temp->next;
		}
		if (i < a->size)
			current = current->next;
	}
	return (0);
}

int	biggest_index(t_stack *a)
{
	int		biggest;	
	t_data	*current;

	biggest = a->top->index;
	current = a->top;

	while (current->next)
		current = current->next;
		if (current->index > biggest)
			biggest = current->index;
	return biggest;
}

void	radix(t_stack *a)
{
	t_stack b;
	int	size;
	int	index;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	b.size = 0;
	b.top = 0;
	
	index = a->size;
		max_bits = 0;
		while (((index - 1) >> max_bits) != 0)
			max_bits++;	
	size = a->size;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = a->top->index;
			if (((num >> i) & 1) == 1)
				ra(a);
			else
				pb(a, &b);
		}
		while (b.size)
			pa(a, &b);
	}
}


int	main(int argc, char *argv[])
{
	int		i;
	t_stack	a;
	char	**list;

	if (argc < 2)
	{
		ft_putstr_color_fd(COLOR_RED, "Usage : ./push_swap \"42 19 -42\" ", 2);
		ft_putstr_color_fd(COLOR_RED, "or ./push_swap 42 19 -42\n", 2);
		return (1);
	}
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (list == NULL)
		{
			ft_putstr_color_fd(COLOR_RED, "Erreur d'allocation de mémoire\n", 2);
			return (1);
		}
	}
	else
		list = &argv[1];
	args_to_stack (&a, list);
	set_index(&a);
	sort(&a);
	return (0);
}
 