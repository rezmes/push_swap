/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:40:11 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 20:48:04 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	syntax_error(char *str)
{
	int	len;

	len = 0;
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		len++;
		str++;
	}
	return (len > 10);
}

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

static void	process_split(t_stack_node **a, char **split)
{
	int		j;
	long	n;

	j = 0;
	while (split[j])
	{
		if (syntax_error(split[j]))
		{
			free_split(split);
			error_exit(a);
		}
		n = ft_atol(split[j]);
		if (n > INT_MAX || n < INT_MIN || duplicate_error(*a, (int)n))
		{
			free_split(split);
			error_exit(a);
		}
		append_node(a, (int)n);
		j++;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	char	**split;

	i = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
		{
			if (split)
				free_split(split);
			error_exit(a);
		}
		process_split(a, split);
		free_split(split);
		i++;
	}
}
