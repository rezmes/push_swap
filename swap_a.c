/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 20:26:15 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 20:26:18 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	ra(t_stack_node **stack_a)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first_node = *stack_a;
	last_node = find_last_node(*stack_a);
	*stack_a = first_node->next;
	(*stack_a)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_stack_node **stack_a)
{
	t_stack_node	*last_node;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last_node = find_last_node(*stack_a);
	last_node->prev->next = NULL;
	last_node->next = *stack_a;
	last_node->prev = NULL;
	(*stack_a)->prev = last_node;
	*stack_a = last_node;
	write(1, "rra\n", 4);
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*node_to_push;

	if (!*stack_b)
		return ;
	node_to_push = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*stack_a)
	{
		*stack_a = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *stack_a;
		(*stack_a)->prev = node_to_push;
		*stack_a = node_to_push;
	}
	write(1, "pa\n", 3);
}
