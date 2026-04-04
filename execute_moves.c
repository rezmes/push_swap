/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:55:50 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 20:48:55 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	int				cheapest_value;
	int				current_cost;

	if (!stack)
		return (NULL);
	cheapest_value = INT_MAX;
	cheapest_node = stack;
	while (stack)
	{
		current_cost = calculate_total_cost(stack->cost_a, stack->cost_b);
		if (current_cost < cheapest_value)
		{
			cheapest_value = current_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

void	execute_rotations(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
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

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*b);
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
	pa(a, b);
}
