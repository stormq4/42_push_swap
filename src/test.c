/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/24 15:55:53 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:11 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	psw_tester(t_stack	*stacks)
{
	int	i;

	i = 0;
	while (i < stacks[0].size)
	{
		printf("a index %i : nr %d 	:	", i, stacks[0].nums[i].num);
		printf("binary %s	", stacks[0].nums[i].binary);
		printf("order %i\n", stacks[0].nums[i].order);
		i++;
	}
	i = 0;
	printf("\n");
	while (i < stacks[1].size)
	{
		printf("b index %i : nr %d 	:	", i, stacks[1].nums[i].num);
		printf("binary %s	", stacks[1].nums[i].binary);
		printf("order %i\n", stacks[1].nums[i].order);
		i++;
	}
	printf("\n");
}
