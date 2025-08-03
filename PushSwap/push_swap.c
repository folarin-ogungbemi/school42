#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	append_node(t_node **headRef, t_node *new)
{
	t_node	*temp;

	if (!*headRef)
	{
		*headRef = new;
		return ;
	}
	temp = *headRef;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	free_stack(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

t_node	*list_last(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	print_stack(t_node *stack, const char *label)
{
	int	count;

	printf("%s: ", label);
	count = 0;
	while (stack)
	{
		printf("[%d: %d | %d] -> ", count, stack->value, stack->index);
		stack = stack->next;
		count++;
	}
	printf("NULL\n");
}
