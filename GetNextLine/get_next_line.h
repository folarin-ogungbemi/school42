/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:46:44 by foogungb          #+#    #+#             */
/*   Updated: 2025/01/16 14:46:51 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_gnl_state
{
	char	*buf;
	char	*data;
	ssize_t	bread;
}	t_gnl_state;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
