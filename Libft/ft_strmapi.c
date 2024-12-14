/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:56:41 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/02 12:54:15 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies the function f to each character of the string s,
 * passing its index as the first argument and the character itself
 * as the second.A new string is created (using malloc(3)) to collect 
 * the results from the successive applications of f. */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*m;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	m = (char *)malloc(len + 1);
	if (!m)
		return (NULL);
	while (i < len)
	{
		m[i] = f(i, s[i]);
		i++;
	}
	m[i] = '\0';
	return (m);
}
