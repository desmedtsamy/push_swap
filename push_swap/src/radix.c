/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:21:09 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 15:36:27 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max_bits;

	max_bits = 0;
	while (((stack->size - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;

	max_bits = get_max_bits(stack_a);
	size = stack_a->size;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((stack_a->top->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (stack_b->size)
			pa(stack_a, stack_b);
	}
}
