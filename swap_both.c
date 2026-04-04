/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 20:26:48 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 20:26:52 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*first_a;
	t_stack_node	*last_a;
	t_stack_node	*first_b;
	t_stack_node	*last_b;

	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	first_a = *stack_a;
	last_a = find_last_node(*stack_a);
	*stack_a = first_a->next;
	(*stack_a)->prev = NULL;
	last_a->next = first_a;
	first_a->prev = last_a;
	first_a->next = NULL;
	first_b = *stack_b;
	last_b = find_last_node(*stack_b);
	*stack_b = first_b->next;
	(*stack_b)->prev = NULL;
	last_b->next = first_b;
	first_b->prev = last_b;
	first_b->next = NULL;
	write(1, "rr\n", 3);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*last_a;
	t_stack_node	*last_b;

	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	last_a = find_last_node(*stack_a);
	last_a->prev->next = NULL;
	last_a->next = *stack_a;
	last_a->prev = NULL;
	(*stack_a)->prev = last_a;
	*stack_a = last_a;
	last_b = find_last_node(*stack_b);
	last_b->prev->next = NULL;
	last_b->next = *stack_b;
	last_b->prev = NULL;
	(*stack_b)->prev = last_b;
	*stack_b = last_b;
	write(1, "rrr\n", 4);
}
