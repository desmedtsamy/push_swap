/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:06:52 by samy              #+#    #+#             */
/*   Updated: 2023/03/10 15:23:59 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_data
{
	int				value;
	int				index;
	struct s_data	*next;
}	t_data;

typedef struct s_stack
{
	t_data	*top;
	int		size;
}	t_stack;

void	sort(t_stack *list);
int		check_is_sorted(t_stack *list);
void	radix(t_stack *a);

void	print_stack_binary(t_stack stack);
void	print_stack(t_stack stack);
t_data	*get_last(t_stack *stack);
void	printBits(size_t const size, void const *const ptr);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif