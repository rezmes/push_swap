/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:49:02 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/03 16:15:38 by mmesgari         ###   ########.fr       */
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

void	ra(t_stack_node **stack_a)
{
		t_stack_node *first_node;
		t_stack_node *last_node;

		if (!*stack_a || !(*stack_a))
				return;
		first_node = *stack_a;
		last_node = find_last_node(*stack_a);

		*stack_a = first_node->next;
		(*stack_a)->prev = NULL;

		last_node->next = first_node;
		first_node->prev = last_node;
		first_node->next = NuLL;

		write(1, "ra\n", 3);
}

void	rra(t_stack_node **stack_a)
{
		t_stack_node	*last_node;
		if(!*stack_a || !(*stack_a)->next)
				return;
		last_node = find_last_node(*stack_a);
		last_node->prev->next = NULL;
		last_node->next = *stack_a;
		last_node->prev = NULL;
		(*stack_a)->prev = last_node;
		*stack_a = last_node;
		write(1, "rra\n", 4);
}


