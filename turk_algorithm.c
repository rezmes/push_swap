/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:40:52 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/03 19:41:16 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper to update indexes before every calculation
void	update_indexes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
}

// The Final Alignment (Bringing the smallest to top)
void	align_stack(t_stack_node **stack_a)
{
	t_stack_node	*smallest;
	int				len;

	smallest = find_smallest(*stack_a);
	len = stack_len(*stack_a);
	set_current_position(*stack_a); // Refresh index

	while (*stack_a != smallest)
	{
		if (smallest->index <= len / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

// THE MAIN ENGINE
void	turk_sort(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	
	// 1. Bootstrap: Push 2 nodes to B to start the algorithm
	if (len_a > 3)
		pb(b, a);
	if (len_a > 4)
		pb(b, a);

	// 2. The Great Transfer (A to B)
	while (stack_len(*a) > 3)
	{
		update_indexes(*a, *b);
		set_target_a_to_b(*a, *b); // You need to implement this target logic
		calculate_cost_a_to_b(*a, *b);
		move_a_to_b(a, b); // The function we wrote in the previous step
	}

	// 3. Sort the remaining 3 anchors
	sort_three(a);

	// 4. The Return Journey (B to A)
	while (*b)
	{
		update_indexes(*a, *b);
		(*b)->target_node = get_target_in_a(*a, (*b)->value); // Find target in A
		
		// Move target to top of A (simpler than cost calculation)
		while (*a != (*b)->target_node)
		{
			if ((*b)->target_node->index <= stack_len(*a) / 2)
				ra(a);
			else
				rra(a);
		}
		pa(a, b); // Push back home
	}

	// 5. Final Alignment
	align_stack(a);
}
