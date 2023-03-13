/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samy <samy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:46:56 by samy              #+#    #+#             */
/*   Updated: 2023/03/13 15:46:11 by samy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(int is_normal, t_stack *stack)
{
	t_data	*elem;
	t_data	*next;

	if (!is_normal)
	{
		ft_putstr_color_fd(COLOR_RED, "Error\n", 2);
	}
	if (stack)
	{
		elem = stack->top;
		while (elem)
		{
			next = elem->next;
			free(elem);
			elem = next;
		}
	}
	exit(!is_normal);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	stack;
	char	**list;

	if (argc < 2)
	{
		ft_putstr_color_fd(COLOR_RED, "Usage : ./push_swap \"42 19 -42\" ", 2);
		ft_putstr_color_fd(COLOR_RED, "or ./push_swap 42 19 -42\n", 2);
		return (1);
	}
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (list == NULL)
		{
			ft_putstr_color_fd(COLOR_RED, "Erreur d'allocation de mémoire\n", 2);
			return (1);
		}
	}
	else
		list = &argv[1];
	args_to_stack (&stack, list);
	sort(&stack);
	quit(YES, &stack);
}
