/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:58:04 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 12:58:36 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_data	*old_top;
	t_data	*new_top;

	if (stack->size <= 1)
		return ;
	old_top = stack->top;
	new_top = old_top->next;
	old_top->next = new_top->next;
	new_top->next = old_top;
	stack->top = new_top;
}

void	sa(t_stack *a)
{
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_stack *b)
{
	ft_printf("sb\n");
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
