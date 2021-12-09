/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:25:17 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:53:38 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_fill(int argc, char **argv, t_stack *stacks)
{
	int		i;
	t_elem	*a;
	t_elem	*b;

	i = 1;
	a = malloc((argc - 1) * sizeof(t_elem));
	check_malloc(a);
	b = malloc((argc - 1) * sizeof(t_elem));
	check_malloc(b);
	while (i < argc)
	{
		check_number(argv[i]);
		a[i - 1].num = ft_atoi(argv[i]);
		i++;
	}
	stacks[0].nums = a;
	stacks[0].size = (size_t)argc - 1;
	stacks[1].nums = b;
	stacks[1].size = 0;
}

int	main(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		check_number(argv[1]);
		ft_atoi(argv[1]);
		return (0);
	}
	stacks = malloc(sizeof(t_stack) * 2);
	check_malloc(stacks);
	stack_fill(argc, argv, stacks);
	fill_binary_order(&stacks[0]);
	pw_sort(stacks);
	free_stacks(stacks, argc);
	// system("leaks push_swap");
	return (0);
}
