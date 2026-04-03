/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:37:52 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/03 19:38:22 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h> // for INT_MAX

// 1. Find the node with the cheapest total cost
t_stack_node	*get_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	int				cheapest_value;
	int				current_cost;

	if (!stack)
		return (NULL);
	cheapest_value = INT_MAX;
	while (stack)
	{
		// To get absolute value without math.h, we check if < 0
		int cost_a = stack->cost_a < 0 ? stack->cost_a * -1 : stack->cost_a;
		int cost_b = stack->cost_b < 0 ? stack->cost_b * -1 : stack->cost_b;
		current_cost = cost_a + cost_b;

		if (current_cost < cheapest_value)
		{
			cheapest_value = current_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

void	execute_rotations(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(a, b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(a, b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	execute_rotations(a, b, cheapest_node);

	while (cheapest_node->cost_a > 0)
	{
		ra(a);
		cheapest_node->cost_a--;
	}
	while (cheapest_node->cost_a < 0)
	{
		rra(a);
		cheapest_node->cost_a++;
	}

	while (cheapest_node->cost_b > 0)
	{
		rb(b);
		cheapest_node->cost_b--;
	}
	while (cheapest_node->cost_b < 0)
	{
		rrb(b);
		cheapest_node->cost_b++;
	}

	pb(b, a);
}
