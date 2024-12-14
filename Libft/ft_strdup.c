/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:28:44 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/02 15:49:17 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The  strdup()  function returns a pointer to a new string which 
 * is a duplicate of the string s.*/
char	*ft_strdup(const char *s)
{
	size_t		s_len;
	size_t		i;
	char		*d;

	i = 0;
	s_len = ft_strlen(s) + 1;
	d = (char *)malloc(s_len);
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
