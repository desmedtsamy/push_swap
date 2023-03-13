/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:07:41 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 15:42:09 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	convert_number(const char *str, t_stack *stack)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (!str)
		quit(NO, stack);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		if (sign * res < INT_MIN || sign * res > INT_MAX)
			quit(NO, stack);
	}
	if (str[i])
		quit(NO, stack);
	return (sign * res);
}

static int	set_index(t_stack *a)
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

static void	add_data(t_stack *stack, int num)
{
	t_data	*last;

	if (!stack->top)
	{
		stack->top = malloc(sizeof(t_data));
		stack->top->value = num;
		stack->top->next = 0;
		return ;
	}
	last = stack->top;
	while (last->next != 0)
		last = last->next;
	last->next = malloc(sizeof(t_data));
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
			quit(NO, stack);
		num = convert_number(num_str[i], stack);
		if (!is_stack_contains(stack, num))
		{
			add_data(stack, num);
			stack->size ++;
		}
		else
			quit(NO, stack);
	}
	set_index(stack);
	return ;
}
