/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 17:15:37 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:14 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_largest_index2(t_stack *stacks, int large, int size)
{
	int		i;
	int		j;

	j = 0;
	while (j < size)
	{
		if (stacks->nums[j].order == large)
			break ;
		j++;
	}
	i = 0;
	while (i < 32)
	{
		if (stacks->nums[j].binary[i] == '1')
			return (i);
		i++;
	}
	return (-1);
}

static int	find_largest_index(t_stack *stacks)
{
	int	size;
	int	i;
	int	large;

	large = 0;
	size = stacks->size;
	i = 0;
	while (i < size)
	{
		if (stacks->nums[i].order > large)
			large = stacks->nums[i].order;
		i++;
	}
	return (find_largest_index2(stacks, large, size));
}

void	pw_sort(t_stack *stacks)
{
	int	l_index;

	if (stacks[0].size >= 2 && stacks[0].size <= 5)
		sort_twotofive(stacks);
	else
	{
		l_index = find_largest_index(&stacks[0]);
		pw_radix(l_index, stacks);
	}
}
