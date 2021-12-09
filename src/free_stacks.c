/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 12:53:56 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:19 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *stacks, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		free(stacks[0].nums[i].binary);
		i++;
	}
	free(stacks[0].nums);
	free(stacks[1].nums);
	free(stacks);
}
