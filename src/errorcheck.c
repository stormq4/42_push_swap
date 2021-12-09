/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errorcheck.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/25 09:59:18 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:19 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
		error_message();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_message();
		i++;
	}
}

void	check_malloc(void *ptr)
{
	if (!ptr)
		exit(1);
}
