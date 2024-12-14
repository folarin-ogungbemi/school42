/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:05:01 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/02 12:30:58 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function allocates memory for an array of nmemb elements of size bytes each
 * and returns a pointer to the allocated memory. The memory is set to zero.
 * If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer
 * value  that  can  later be successfully passed to free().*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}
