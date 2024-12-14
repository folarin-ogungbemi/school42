/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:12:09 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/09 15:16:17 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
void	print(t_list *list)
{
	int	size;
	if (list)
	{
		size = 0;
		while (list != NULL)
		{
			printf("content[%d] %s\n", size, (char *)list->content);
			size++;
			list = list->next;
		}
	}
	else
		printf("content is NULL\n");
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	int	size;
	t_list	*last;

	head = NULL;
	node1 = ft_lstnew("Good Morning!");
	node2 = ft_lstnew("Good Afternoon!");
	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);
	print(head);
	size = ft_lstsize(head);
	last = ft_lstlast(head);
	printf("size: %d\n", size);
	printf("last: %s\n", (char *)last->content);
	free(head->next);
	free(head);
	return (0);
}*/
