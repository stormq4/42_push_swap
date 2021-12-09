/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_hardcode.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 11:24:07 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:55:58 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_low(t_stack stacks)
{
	int	i;
	int	low;

	low = stacks.nums[0].order;
	i = 0;
	while (i < 3)
	{
		if (low > stacks.nums[i].order)
			low = stacks.nums[i].order;
		i++;
	}
	return (low);
}

static void	sort_three(t_stack *stacks)
{
	int	low;

	low = find_low(stacks[0]);
	if (stacks[0].nums[0].order == low && stacks[0].nums[1].order == low + 2)
	{
		s_check(stacks, A);
		r_check(stacks, A);
	}
	else if (stacks[0].nums[0].order == low + 1)
	{
		if (stacks[0].nums[1].order == low)
			s_check(stacks, A);
		else
			rr_check(stacks, A);
	}
	else if (stacks[0].nums[0].order == low + 2)
	{
		if (stacks[0].nums[1].order == low + 1)
		{
			s_check(stacks, A);
			rr_check(stacks, A);
		}	
		else
			r_check(stacks, A);
	}
}

static void	sort_four(t_stack *stacks)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (i++ < 4)
	{
		if (stacks[0].nums[0].order <= 2)
		{
			p_check(stacks, B);
			count++;
		}
		else
			r_check(stacks, A);
		if (count == 2)
			break ;
	}
	if (stacks[0].nums[0].order == 4 && stacks[1].nums[0].order == 1)
		s_check(stacks, S);
	else if (stacks[0].nums[0].order == 4 && stacks[1].nums[0].order != 1)
		s_check(stacks, A);
	else if (stacks[0].nums[0].order == 3 && stacks[1].nums[0].order == 1)
		s_check(stacks, B);
	p_check(stacks, A);
	p_check(stacks, A);
}

static void	sort_five(t_stack *stacks)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < 5)
	{
		if (stacks[0].nums[0].order <= 2)
		{
			p_check(stacks, B);
			count++;
		}
		else
			r_check(stacks, A);
		if (count == 2)
			break ;
		i++;
	}
	sort_three(stacks);
	if (stacks[1].nums[0].order == 1)
		r_check(stacks, B);
	p_check(stacks, A);
	p_check(stacks, A);
}

void	sort_twotofive(t_stack *stacks)
{
	int	size;

	size = stacks[0].size;
	if (sort_check(stacks))
		return ;
	if (size == 2)
	{
		if (stacks[0].nums[0].order > stacks[0].nums[1].order)
			s_check(&stacks[0], A);
	}
	else if (size == 3)
		sort_three(stacks);
	else if (size == 4)
		sort_four(stacks);
	else if (size == 5)
		sort_five(stacks);
}
