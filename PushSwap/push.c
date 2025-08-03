#include "push_swap.h"

void	push_a(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = temp->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	push_b(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = temp->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}
