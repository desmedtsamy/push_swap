/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:58:58 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 12:59:29 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *first_stack, t_stack *second_stack)
{
	t_data	*temp;

	if (first_stack->top == 0)
		return ;
	temp = first_stack->top;
	first_stack->top = temp->next;
	if (second_stack->top)
		temp->next = second_stack->top;
	else
		temp->next = 0;
	second_stack->top = temp;
	(first_stack->size)--;
	(second_stack->size)++;
}

void	pa(t_stack *a, t_stack *b)
{
	ft_printf("pa\n");
	push(b, a);
}

void	pb(t_stack *a, t_stack *b)
{
	ft_printf("pb\n");
	push(a, b);
}
