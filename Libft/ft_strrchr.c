/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:04:58 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/03 15:42:45 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function returns a pointer to the last occurrence
 * of  the  character  c  in  the string s.*/

char	*ft_strrchr(const char *s, int c)
{
	const char	*seen;

	seen = NULL;
	c = c % 256;
	while (*s != '\0')
	{
		if (*s == c)
			seen = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)seen);
}
