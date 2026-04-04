/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:41:07 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 19:41:11 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					cost_a;
	int					cost_b;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Operations
void			sa(t_stack_node **a);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

// Utils
t_stack_node	*find_last_node(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			free_stack(t_stack_node **stack);
void			error_exit(t_stack_node **stack);
void			set_current_position(t_stack_node *stack);

// Parser
void			init_stack_a(t_stack_node **a, char **argv);
long			ft_atol(const char *str);
char			**ft_split(char const *s, char c);
void			free_split(char **args);

// Tiny sort
void			sort_three(t_stack_node **a);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_highest(t_stack_node *stack);

// Target & Cost
void			set_target_a_to_b(t_stack_node *a, t_stack_node *b);
void			calculate_cost_a_to_b(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_target_in_a(t_stack_node *a, int b_value);
void			calculate_cost_b_to_a(t_stack_node *a, t_stack_node *b);
int				calculate_total_cost(int cost_a, int cost_b);

// Algorithm
void			turk_sort(t_stack_node **a, t_stack_node **b);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			execute_rotations(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			align_stack(t_stack_node **a);
void			update_indexes(t_stack_node *a, t_stack_node *b);

int				is_sorted(t_stack_node *stack);

#endif