/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:41:26 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 19:41:29 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
