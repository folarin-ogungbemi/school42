#include "push_swap.h"

void	radix_sort(t_node **a, t_node **b, int max)
{
	int	max_bits;
	int	i;
	int	j;
	int	count;

	i = 0;
	max_bits = 0;
	while (((max - 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		count = list_size(*a);
		j = 0;
		while (j < count)
		{
			if ((((*a)->index >> i) & 1) == 0)
				push_b(a, b);
			else
				rotate_a(a);
			j++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}
