/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions_r.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:26:07 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:22 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_action(t_stack *s)
{
	t_elem	tmp1;
	t_elem	tmp2;
	int		size;

	tmp1 = s->nums[0];
	size = s->size;
	while (size--)
	{
		tmp2 = s->nums[size];
		s->nums[size] = tmp1;
		tmp1 = tmp2;
	}
}

void	r_check(t_stack *stack, t_action action)
{
	if (action == A || action == S)
	{
		r_action(&stack[0]);
		if (action == A)
			ft_putstr_fd("ra\n", 1);
	}
	if (action == B || action == S)
	{
		r_action(&stack[1]);
		if (action == B)
			ft_putstr_fd("rb\n", 1);
	}
	if (action == S)
		ft_putstr_fd("rr\n", 1);
}
