#include "push_swap.h"

static void	update_values(int *min, int *max, const int *s, const int *chunk_s)
{
	*min = *max;
	*max += *chunk_s;
	if (*max > *s)
		*max = *s;
}

static void	push_chunks_to_b(t_node **a, t_node **b, int chunk_size, int size)
{
	int	min;
	int	max;
	int	pos;
	int	len;

	min = 0;
	max = chunk_size;
	while (*a)
	{
		while (has_in_range(*a, min, max))
		{
			len = list_size(*a);
			pos = position_in_stack(*a, min, max);
			if (pos <= len / 2)
				while (pos-- > 0)
					rotate_a(a);
			else
				while (pos++ < len)
					rotatex2_a(a);
			push_b(a, b);
			if (list_size(*b) > 1 && (*b)->index < min + (chunk_size / 2))
				rotate_b(b);
		}
		update_values(&min, &max, &size, &chunk_size);
	}
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	int	max_idx;
	int	pos;

	while (*b)
	{
		max_idx = find_max_index(*b);
		pos = position_of_index(*b, max_idx);
		if (pos <= list_size(*b) / 2)
			while (pos-- > 0)
				rotate_b(b);
		else
			while (pos++ < list_size(*b))
				rotatex2_b(b);
		push_a(a, b);
	}
}

static void	chunk_sort(t_node **a, t_node **b, int size)
{
	int	chunk_count;
	int	chunk_size;

	if (size <= 100)
		chunk_count = 5;
	else if (size <= 250)
		chunk_count = 9;
	else
		chunk_count = 11;
	chunk_size = (size + chunk_count - 1) / chunk_count;
	push_chunks_to_b(a, b, chunk_size, size);
	push_back_to_a(a, b);
}

void	sort_by_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	assign_indices(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	size = list_size(*stack_a);
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		chunk_sort(stack_a, stack_b, size);
}
