/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   binary.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 09:34:14 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:20 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static size_t	find_min(t_stack *stack)
{
	size_t		i;
	size_t		size;
	long long	low;

	size = stack->size;
	low = LONG_MAX;
	i = 0;
	while (i < size)
	{
		if (stack->nums[i].num == low)
			error_message();
		if (stack->nums[i].num < low && !stack->nums[i].order)
			low = stack->nums[i].num;
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (low == stack->nums[i].num)
			return (i);
		i++;
	}
	return (-1);
}

void	ps_order(t_stack *stack)
{
	int	i;
	int	j;
	int	size;
	int	order;

	size = stack->size;
	i = 0;
	order = 0;
	while (i < size)
	{
		stack->nums[i].order = order;
		i++;
	}
	j = 0;
	while (j < size)
	{
		i = find_min(stack);
		j++;
		order++;
		stack->nums[i].order = order;
	}
}

char	*nr_tobinary_int(int nr)
{
	int		bin_size;
	int		bin_val;
	char	*str;
	int		i;

	bin_size = 31;
	str = malloc(sizeof(char) * (bin_size + 2));
	check_malloc(str);
	i = 0;
	while (bin_size >= 0)
	{
		bin_val = nr >> bin_size;
		if (bin_val & 1)
			str[i] = '1';
		else
			str[i] = '0';
		i++;
		bin_size--;
	}
	str[i] = 0;
	return (str);
}

void	fill_binary_order(t_stack *stack)
{
	int	i;
	int	size;

	size = stack->size;
	ps_order(&stack[0]);
	i = 0;
	while (i < size)
	{
		stack->nums[i].binary = nr_tobinary_int(stack->nums[i].order);
		i++;
	}
}
