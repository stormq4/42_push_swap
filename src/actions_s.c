/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions_s.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:25:51 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:21 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	s_action(t_stack *s)
{
	t_elem	tmp;

	tmp = s->nums[0];
	s->nums[0] = s->nums[1];
	s->nums[1] = tmp;
}

void	s_check(t_stack *stack, t_action action)
{
	if (action == A || action == S)
	{
		s_action(&stack[0]);
		if (action == A)
			ft_putstr_fd("sa\n", 1);
	}
	if (action == B || action == S)
	{
		s_action(&stack[1]);
		if (action == B)
			ft_putstr_fd("sb\n", 1);
	}
	if (action == S)
		ft_putstr_fd("ss\n", 1);
}
