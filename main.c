/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:41:51 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/03 20:02:29 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if the stack is already perfectly sorted
bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	// 1. Basic Argument Check
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);

	init_stack_a(&stack_a, argv + 1);
	// 3. Algorithm Selection
	if (!is_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			turk_sort(&stack_a, &stack_b);
	}

	// 4. Cleanup
	free_stack(&stack_a);
	return (0);
}
