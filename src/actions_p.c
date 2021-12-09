/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:48:54 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:22 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_action2(t_stack *s1, t_stack *s2)
{
	t_elem	tmp1;
	t_elem	tmp2;
	int		i;

	i = s2->size - 2;
	tmp1 = s2->nums[i + 1];
	while (i >= 0)
	{
		tmp2 = s2->nums[i];
		s2->nums[i] = tmp1;
		tmp1 = tmp2;
		i--;
	}
	s1->size++;
	s2->size--;
}

static void	p_action(t_stack *s1, t_stack *s2)
{
	t_elem	tmp1;
	t_elem	tmp2;
	int		i;
	int		size;

	i = 0;
	size = s1->size;
	tmp1 = s2->nums[0];
	while (i <= size)
	{
		if (i == s1->size)
			s1->nums[i] = tmp1;
		else
		{
			tmp2 = s1->nums[i];
			s1->nums[i] = tmp1;
			tmp1 = tmp2;
		}
		i++;
	}
	p_action2(s1, s2);
}

void	p_check(t_stack *stack, t_action action)
{
	if (action == A)
	{
		p_action(&stack[0], &stack[1]);
		ft_putstr_fd("pa\n", 1);
	}
	if (action == B)
	{
		p_action(&stack[1], &stack[0]);
		ft_putstr_fd("pb\n", 1);
	}
}
