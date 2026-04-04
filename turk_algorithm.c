/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:54:44 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 20:39:29 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_indexes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
}

void	align_stack(t_stack_node **stack_a)
{
	t_stack_node	*smallest;
	int				len;

	smallest = find_smallest(*stack_a);
	len = stack_len(*stack_a);
	while ((*stack_a) != smallest)
	{
		if (smallest->index <= len / 2)
			ra(stack_a);
		else
			rra(stack_a);
		set_current_position(*stack_a);
		len = stack_len(*stack_a);
	}
}

static void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	while (*b)
	{
		update_indexes(*a, *b);
		tmp = *b;
		while (tmp)
		{
			tmp->target_node = get_target_in_a(*a, tmp->value);
			tmp = tmp->next;
		}
		calculate_cost_b_to_a(*a, *b);
		move_b_to_a(a, b);
	}
}

void	turk_sort(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a > 3)
		pb(b, a);
	if (len_a > 4)
		pb(b, a);
	while (stack_len(*a) > 3)
	{
		update_indexes(*a, *b);
		set_target_a_to_b(*a, *b);
		calculate_cost_a_to_b(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	push_b_to_a(a, b);
	align_stack(a);
}
