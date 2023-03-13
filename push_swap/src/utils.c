/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:59:14 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 13:06:45 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack stack)
{
	t_data	elem;

	ft_printf("size = %d", stack.size);
	if (stack.top == 0)
	{
		ft_printf(" stack is empty\n");
		return ;
	}
	elem = *stack.top;
	ft_printf(", top = %d\n", elem.value);
	while (elem.next != 0)
	{
		ft_printf("%d ", elem.value);
		ft_printf("%d\n", elem.index);
		elem = *elem.next;
	}
	ft_printf("%d ", elem.value);
	ft_printf("%d\n", elem.index);
}

t_data	*get_last(t_stack *stack)
{
	t_data	*last;

	last = stack->top;
	while (last->next != 0)
		last = last->next;
	return (last);
}

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

int	is_stack_contains(t_stack *stack, int num)
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
