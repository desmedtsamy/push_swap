/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:59:14 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 12:16:43 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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
