/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:02:21 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 15:40:13 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *list)
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

static void	sort_three(t_stack *list)
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

static void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	int		min_pos;

	while (stack_a->top->index != 0)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	int		min_pos;
	int		i;

	i = 0;
	while (i < 2)
	{
		while (stack_a->top->index != 0 && stack_a->top->index != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a);
	if (is_sorted(stack_b))
		rb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort(t_stack *stack_a)
{
	t_stack	stack_b;

	stack_b.size = 0;
	stack_b.top = 0;
	if (stack_a->size <= 1)
		return ;
	else if (is_sorted(stack_a))
		return ;
	else if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, &stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, &stack_b);
	else
		radix(stack_a, &stack_b);
}
