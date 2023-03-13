/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:02:21 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 12:16:09 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_sorted(t_stack *list)
{
	t_data	*elem;

	elem = list->top;
	while (elem->next)
	{
		if (elem->value > elem->next->value)
			return (0);
		elem = elem->next;
	}
	return (1);
}

void	sort_three(t_stack *list)
{
	int	first;
	int	second;
	int	third;

	first = list->top->value;
	second = list->top->next->value;
	third = list->top->next->next->value;
	if (first < second && first < third && second > third)
	{
		sa(list);
		ra(list);
	}
	else if (first > second && first < third && second < third)
		sa(list);
	else if (first < second && first > third && second > third)
		rra(list);
	else if (first > second && first > third && second < third)
		ra(list);
	else if (first > second && first > third && second > third)
	{
		sa(list);
		rra(list);
	}
}

void	sort_five(t_stack *stack_a)
{
	t_stack	stack_b;
	int		min;
	int		min_pos;
	int		i;

	stack_b.size = 0;
	stack_b.top = 0;
	i = 0;
	while (i < 2)
	{
		while (stack_a->top->index != 0 && stack_a->top->index != 1)
			ra(stack_a);
		pb(stack_a, &stack_b);
		i++;
	}
	sort_three(stack_a);
	if (check_is_sorted(&stack_b))
		rb(&stack_b);
	pa(stack_a, &stack_b);
	pa(stack_a, &stack_b);
}

void	sort(t_stack *list)
{
	if (list->size <= 1)
		return ;
	if (check_is_sorted(list))
		return ;
	if (list->size == 2)
	{
		sa(list);
		return ;
	}
	if (list->size == 3)
	{
		sort_three(list);
		return ;
	}
	if (list->size == 5)
		sort_five(list);
	else
		radix(list);
}
