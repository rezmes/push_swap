/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 20:26:26 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 20:26:29 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack_node **stack_b)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = find_last_node(*stack_b);
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_stack_node **stack_b)
{
	t_stack_node	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = find_last_node(*stack_b);
	last->prev->next = NULL;
	last->next = *stack_b;
	last->prev = NULL;
	(*stack_b)->prev = last;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	pb(t_stack_node **stack_b, t_stack_node **stack_a)
{
	t_stack_node	*node_to_push;

	if (!*stack_a)
		return ;
	node_to_push = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*stack_b)
	{
		*stack_b = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *stack_b;
		(*stack_b)->prev = node_to_push;
		*stack_b = node_to_push;
	}
	write(1, "pb\n", 3);
}
