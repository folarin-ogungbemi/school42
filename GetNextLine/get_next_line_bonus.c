/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:44:45 by foogungb          #+#    #+#             */
/*   Updated: 2025/01/20 18:54:30 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <string.h>

static char	*extract_line(t_fd_node **node)
{
	char	*newline;
	char	*line;
	char	*rest;

	newline = ft_strchr((*node)->data, '\n');
	if (!newline)
	{
		line = ft_strdup((*node)->data);
		free((*node)->data);
		(*node)->data = NULL;
		return (line);
	}
	line = ft_strndup((*node)->data, (newline - (*node)->data + 1));
	rest = ft_strdup(newline + 1);
	free((*node)->data);
	(*node)->data = rest;
	if (!(*node)->data)
		(*node)->data = NULL;
	if (!*(*node)->data)
	{
		free((*node)->data);
		(*node)->data = NULL;
	}
	return (line);
}

static void	parse_data(t_fd_node **node, t_gnl_buffer *b)
{
	char	*temp;

	while (!ft_strchr((*node)->data, '\n'))
	{
		b->bread = read((*node)->fd, b->buf, BUFFER_SIZE);
		if (b->bread < 0)
		{
			free((*node)->data);
			(*node)->data = NULL;
			break ;
		}
		if (b->bread == 0)
			break ;
		(b->buf)[b->bread] = '\0';
		temp = ft_strjoin((*node)->data, b->buf);
		if (!temp)
		{
			free((*node)->data);
			(*node)->data = NULL;
			break ;
		}
		free((*node)->data);
		(*node)->data = temp;
	}
}

static t_fd_node	*get_fd_node(t_fd_node **head, int *fd)
{
	t_fd_node	*curr;
	t_fd_node	*new_node;

	curr = *head;
	while (curr)
	{
		if (curr->fd == *fd)
			return (curr);
		curr = curr->next;
	}
	new_node = (t_fd_node *)malloc(sizeof(t_fd_node));
	if (!new_node)
		return (NULL);
	new_node->fd = *fd;
	new_node->data = NULL;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

static void	fd_lst_remove(t_fd_node **head, int fd)
{
	t_fd_node	*curr;
	t_fd_node	*prev;

	curr = *head;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (prev == NULL)
				*head = curr->next;
			else
				prev->next = curr->next;
			free(curr->data);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

char	*get_next_line(int fd)
{
	static t_fd_node	*fd_list;
	t_fd_node			*curr;
	t_gnl_buffer		b;

	b.buf = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !b.buf || (read(fd, 0, 0) < 0))
		return (free(b.buf), NULL);
	curr = get_fd_node(&fd_list, &fd);
	if (!curr)
		return (free(b.buf), NULL);
	parse_data(&curr, &b);
	free(b.buf);
	if (!curr->data)
	{
		fd_lst_remove(&fd_list, fd);
		return (NULL);
	}
	if (!*curr->data)
		return(free(curr->data), NULL);
	return (extract_line(&curr));
}
