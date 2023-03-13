/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:06:52 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 16:16:38 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

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

void	quit(int is_normal, t_stack *stack);
void	args_to_stack(t_stack *stack, char **num_str);
void	sort(t_stack *list);
void	radix(t_stack *stack_a, t_stack *stack_b);

int		is_number(char *str);
int		is_stack_contains(t_stack *stack, int num);
void	print_stack(t_stack stack);

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