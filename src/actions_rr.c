/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions_rr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:25:43 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:21 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_action(t_stack *s)
{
	t_elem	tmp1;
	t_elem	tmp2;
	int		size;
	int		i;

	size = s->size;
	tmp1 = s->nums[size - 1];
	i = 0;
	while (i < size)
	{
		tmp2 = s->nums[i];
		s->nums[i] = tmp1;
		tmp1 = tmp2;
		i++;
	}
}

void	rr_check(t_stack *stack, t_action action)
{
	if (action == A || action == S)
	{
		rr_action(&stack[0]);
		if (action == A)
			ft_putstr_fd("rra\n", 1);
	}
	if (action == B || action == S)
	{
		rr_action(&stack[1]);
		if (action == B)
			ft_putstr_fd("rrb\n", 1);
	}
	if (action == S)
		ft_putstr_fd("rrr\n", 1);
}
