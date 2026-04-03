/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:06:48 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/03 20:07:03 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack_node	*get_target_in_a(t_stack_node *stack_a, int b_value)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_value;

	current_a = stack_a;
	target_node = NULL;
	best_match_value = LONG_MAX;
	while (current_a)
	{
		if (current_a->value > b_value && current_a->value < best_match_value)
		{
			best_match_value = current_a->value;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	if (best_match_value == LONG_MAX)
		target_node = find_smallest(stack_a);
	return (target_node);
}

void	set_current_position(t_stack_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	calculate_cost_a_to_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int				len_a;
	int				len_b;
	t_stack_node	*current_a;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	current_a = stack_a;

	while (current_a)
	{
		current_a->cost_a = current_a->index;
		if (current_a->index > len_a / 2)
			current_a->cost_a = (len_a - current_a->index) * -1; // Negative means use 'rra'

		current_a->cost_b = current_a->target_node->index;
		if (current_a->target_node->index > len_b / 2)
			current_a->cost_b = (len_b - current_a->target_node->index) * -1; // Negative means use 'rrb'

		current_a = current_a->next;
	}
}

// Find the correct target node in Stack B for each node in Stack A
void	set_target_a_to_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_a;
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_value;

	current_a = stack_a;
	while (current_a)
	{
		best_match_value = LONG_MIN; // Start with the smallest possible number
		current_b = stack_b;
		target_node = NULL;
		while (current_b)
		{
			// We want a number in B that is SMALLER than A, but CLOSEST to it
			if (current_b->value < current_a->value && current_b->value > best_match_value)
			{
				best_match_value = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		// Edge Case: If A is smaller than everything in B, target the HIGHEST in B
		if (best_match_value == LONG_MIN)
			target_node = find_highest(stack_b);

		current_a->target_node = target_node; // Save it to the struct
		current_a = current_a->next;
	}
}
