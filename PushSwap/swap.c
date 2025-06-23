#include "push_swap.h"

void	swap(t_node **stack_a)
{
	t_node	*temp_1;
	t_node	*temp_2;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp_1 = *stack_a;
	temp_2 = temp_1->next;
	temp_1->next = temp_2->next;
	temp_2->next = temp_1;
	*stack_a = temp_2;
}

void	swap_a(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_node **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	swap_ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
