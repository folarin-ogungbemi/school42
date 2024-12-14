/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:36:10 by foogungb          #+#    #+#             */
/*   Updated: 2024/11/14 18:10:28 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* The  bzero()  function  erases  the data in the n bytes
 * of the memory starting at the location pointed to by s,
 * by writing zeros (bytes containing '\0') to that area.*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	unsigned char	value;
	size_t			i;

	p = s;
	value = 0;
	i = 0;
	while (i < n)
	{
		p[i] = value;
		i++;
	}
}
/*
int	main(void)
{
	char	arr[13] = "Hello World!";

	printf("should return string: %s\n", arr);
	bzero(arr, sizeof(arr));
	printf("should return empty string: %s\n", arr);
	return (0);
}*/
