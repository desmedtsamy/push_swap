/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:59:50 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 13:00:19 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_data	*last;

	last = stack->top;
	while (last->next != 0)
		last = last->next;
	last->next = stack->top;
	stack->top = stack->top->next;
	last->next->next = 0;
}

void	ra(t_stack *a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rb(t_stack *b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
