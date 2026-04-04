/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 20:27:18 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 20:27:21 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	calculate_total_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_val(cost_a) > abs_val(cost_b))
			return (abs_val(cost_a));
		return (abs_val(cost_b));
	}
	return (abs_val(cost_a) + abs_val(cost_b));
}

void	calculate_cost_b_to_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->cost_b = b->index;
		if (b->index > len_b / 2)
			b->cost_b = (len_b - b->index) * -1;
		b->cost_a = b->target_node->index;
		if (b->target_node->index > len_a / 2)
			b->cost_a = (len_a - b->target_node->index) * -1;
		b = b->next;
	}
}

void	set_current_position(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}
