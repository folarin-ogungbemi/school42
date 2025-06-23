#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

int		list_size(t_node *head);
int		ft_atoi(char *str);
void	append_node(t_node **head, t_node *new);
t_node	*create_node(int value);
void	print_stack(t_node *stack, const char *str);
void	free_stack(t_node *stack);
void	push_swap(t_node *stack_a);
void	push_a(t_node **src, t_node **dest);
void	push_b(t_node **src, t_node **dest);
void	swap(t_node **stack_a);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ss(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_rr(t_node **stack_a, t_node **stack_b);
void	rotatex2(t_node **stack);
void	rotatex2_a(t_node **stack_a);
void	rotatex2_b(t_node **stack_b);
void	rotatex2_rr(t_node **stack_a, t_node **stack_b);
void	assign_indices(t_node *stack);
void	radix_sort(t_node **a, t_node **b, int *max);
void	sort_by_stack(t_node **stack_a, t_node **stack_b);

#endif
