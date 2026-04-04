/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:40:35 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 19:40:46 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack_node	*find_highest(t_stack_node *stack)
{
	t_stack_node	*highest;

	if (!stack)
		return (NULL);
	highest = stack;
	while (stack)
	{
		if (stack->value > highest->value)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

t_stack_node	*get_target_in_a(t_stack_node *stack_a, int b_value)
{
	t_stack_node	*cur;
	t_stack_node	*target;
	long			best;

	cur = stack_a;
	target = NULL;
	best = LONG_MAX;
	while (cur)
	{
		if (cur->value > b_value && cur->value < best)
		{
			best = cur->value;
			target = cur;
		}
		cur = cur->next;
	}
	if (best == LONG_MAX)
		target = find_smallest(stack_a);
	return (target);
}

void	calculate_cost_a_to_b(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost_a = a->index;
		if (a->index > len_a / 2)
			a->cost_a = (len_a - a->index) * -1;
		a->cost_b = a->target_node->index;
		if (a->target_node->index > len_b / 2)
			a->cost_b = (len_b - a->target_node->index) * -1;
		a = a->next;
	}
}

void	set_target_a_to_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_b;
	t_stack_node	*target;
	long			best;

	while (a)
	{
		best = LONG_MIN;
		target = NULL;
		cur_b = b;
		while (cur_b)
		{
			if (cur_b->value < a->value && cur_b->value > best)
			{
				best = cur_b->value;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best == LONG_MIN)
			target = find_highest(b);
		a->target_node = target;
		a = a->next;
	}
}
