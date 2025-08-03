#include "push_swap.h"

void	sort_2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}
