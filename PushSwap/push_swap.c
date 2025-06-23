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

void	append_node(t_node **head, t_node *new)
{
	t_node	*temp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	free_stack(t_node *stack)
{
	t_node	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
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
