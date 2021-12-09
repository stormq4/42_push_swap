/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 14:25:39 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/09 13:42:18 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "../libft/libft.h"
#include <stdio.h>
# include <stdlib.h>
# define TRUE 1
# define FALSE 0

typedef struct s_elem
{
	int		num;
	int		order;
	char	*binary;
}	t_elem;

typedef struct s_stack
{
	t_elem	*nums;
	int		size;
}	t_stack;

typedef enum e_action
{
	A,
	B,
	S
}	t_action;

void	s_check(t_stack *stack, t_action action);
void	r_check(t_stack *stack, t_action action);
void	rr_check(t_stack *stack, t_action action);
void	p_check(t_stack *stack, t_action action);
void	check_malloc(void *ptr);
void	check_number(char *str);
void	error_message(void);
char	*nr_tobinary_int(int nr);
void	ps_order(t_stack *stack);
void	fill_binary_order(t_stack	*stack);
void	pw_sort(t_stack *stacks);
void	pw_radix(int l_index, t_stack *stacks);
int		sort_check(t_stack *stack);
void	sort_twotofive(t_stack *stacks);
void	free_stacks(t_stack *stacks, int argc);
void	psw_tester(t_stack	*stacks);

#endif
