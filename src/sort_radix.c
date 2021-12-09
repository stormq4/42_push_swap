/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_radix.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 10:31:35 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:16 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_stack *stacks)
{
	int	size;
	int	i;

	i = 0;
	if (stacks[1].size)
		return (FALSE);
	size = stacks[0].size;
	while (i < size)
	{
		if (stacks[0].nums[i].order != i + 1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	push_back(size_t count, t_stack *stacks)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		p_check(stacks, A);
		i++;
	}
}

int	pw_radix_sort(t_stack *stacks, int size, int j)
{
	int		i;
	size_t	push_count;

	i = 0;
	push_count = 0;
	while (i < size)
	{
		if (sort_check(stacks))
			return (push_count);
		if (stacks[0].nums[0].binary[j] == '0')
		{
			p_check(stacks, B);
			push_count++;
		}
		else
			r_check(stacks, A);
		i++;
	}
	return (push_count);
}

void	pw_radix(int l_index, t_stack *stacks)
{
	int		j;
	size_t	push_count;
	int		size;

	j = 31;
	while (j >= l_index)
	{
		size = (int)stacks[0].size;
		push_count = pw_radix_sort(stacks, size, j);
		push_back(push_count, stacks);
		j--;
	}
}
