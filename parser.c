/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:45:16 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/03 20:08:29 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// 1. Check if the string is a valid number (no letters, correct signs)
static int	syntax_error(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

// 2. Check if the number already exists in the stack
static int	duplicate_error(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

// 3. Create a new node and add it to the bottom of Stack A
static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

// 4. The main parsing function
void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i]) // Loop through each argument
	{
		// Note: If you used ft_split, argv[i] is already a single string number.
		if (syntax_error(argv[i]))
			error_exit(a);
		
		// Convert string to long to check for integer overflow
		n = ft_atol(argv[i]); // You need to implement ft_atol (like atoi but returns long)
		
		if (n > INT_MAX || n < INT_MIN)
			error_exit(a);
		if (duplicate_error(*a, (int)n))
			error_exit(a);
		
		// If it passed all checks, add it to the stack
		append_node(a, (int)n);
		i++;
	}
}
