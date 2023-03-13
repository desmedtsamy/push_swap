/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:00:54 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 13:01:30 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_data	*penultimate;
	t_data	*last;

	if (stack->size < 2)
		return ;
	penultimate = stack->top;
	while (penultimate->next->next != 0)
		penultimate = penultimate->next;
	last = penultimate->next;
	last->next = stack->top;
	stack->top = last;
	penultimate->next = 0;
}

void	rra(t_stack *a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
