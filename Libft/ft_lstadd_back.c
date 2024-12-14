/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:17:40 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/09 15:32:13 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr = ft_lstlast(*lst);
	curr->next = new;
}
/*
void	print(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		printf("content[%d] %s\n", size, (char *)lst->content);
		size++;
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;

	head = NULL;
	node1 = ft_lstnew("Good Morning!");
	node2 = ft_lstnew("Good Afternoon!");
	ft_lstadd_back(&head, node1);
	ft_lstadd_back(&head, node2);
	print(head);
	free(head->next);
	free(head);
}
*/
