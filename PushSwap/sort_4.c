#include "push_swap.h"

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int	pos;

	while (list_size(*stack_a) > 3)
	{
		if (is_sorted(*stack_a))
			break ;
		pos = min_index_pos(*stack_a);
		if (pos == 0)
			push_b(stack_a, stack_b);
		else if (pos == 3)
			rotatex2_a(stack_a);
		else if (pos == 2)
		{
			rotatex2_a(stack_a);
			rotatex2_a(stack_a);
		}
		else if (pos == 1)
			swap_a(stack_a);
	}
	if (list_size(*stack_a) == 3)
	{
		sort_3(stack_a);
		push_a(stack_a, stack_b);
	}
}
