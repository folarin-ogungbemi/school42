#include "push_swap.h"

void	push_a(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dest;
	*dest = temp;
	write(1, "pa\n", 3);
}

void	push_b(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dest;
	*dest = temp;
	write(1, "pb\n", 3);
}
