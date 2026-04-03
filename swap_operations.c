/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:49:02 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/03 15:53:34 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(t_stack_node **stack_a)
{
		t_stack_node	*first;
		t_stack_node	*second;

		if (!*stack_a || !(*stack_a)->next)
				return;

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
