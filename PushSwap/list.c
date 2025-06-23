#include "push_swap.h"

int	list_size(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	assign_indices(t_node *stack)
{
	int		size;
	int		i;
	t_node	*min;
	t_node	*curr;

	size = list_size(stack);
	i = 0;
	while (i < size)
	{
		min = NULL;
		curr = stack;
		while (curr)
		{
			if (curr->index == -1 && (!min || curr->value < min->value))
				min = curr;
			curr = curr->next;
		}
		if (min)
			min->index = i++;
		else
			break ;
	}
}
