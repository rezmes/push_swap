/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:39:37 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/03 19:40:25 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_stack_node **stack_a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*stack_a);
	if (*stack_a == highest_node)
		ra(stack_a);
	else if ((*stack_a)->next == highest_node)
		rra(stack_a);
	
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}
