#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

int		list_size(t_node *head);
int		exit_error(void);
long	ft_atol(const char *str);
void	append_node(t_node **head, t_node *new);
t_node	*create_node(int value);
void	print_stack(t_node *stack, const char *str);
void	free_stack(t_node *stack);
void	push_swap(t_node *stack_a);
void	push_a(t_node **src, t_node **dest);
void	push_b(t_node **src, t_node **dest);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ss(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_rr(t_node **stack_a, t_node **stack_b);
void	rotatex2_a(t_node **stack_a);
void	rotatex2_b(t_node **stack_b);
void	rotatex2_rr(t_node **stack_a, t_node **stack_b);
void	assign_indices(t_node *stack);
void	radix_sort(t_node **a, t_node **b, int max);
void	sort_by_stack(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node *stack_a);
int		has_duplicate(t_node *stack);
int		min_index_pos(t_node *stack_a);
t_node	*list_last(t_node *head);
int		has_in_range(t_node *stack, int min, int max);
int		find_max_pos(t_node *stack);
int		position_in_stack(t_node *stack, int min, int max);
int		position_of_index(t_node *stack, int target_index);
int		find_max_index(t_node *stack);
void	sort_2(t_node **stack_a);
void	sort_3(t_node **stack_a);
void	sort_4(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **a, t_node **b);
#endif
