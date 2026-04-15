/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 20:26:48 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/15 22:08:56 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		write(1, "rr\n", 3);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		write(1, "rrr\n", 4);
}

void	ss(t_stack_node **a, t_stack_node **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}