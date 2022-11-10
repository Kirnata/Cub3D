/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:03:11 by ptopping          #+#    #+#             */
/*   Updated: 2022/10/18 21:28:46 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest && !source)
		return (0);
	if (dest > source)
	{	
		i = size - 1;
		while (i < size)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(source + i);
			i--;
		}	
	}
	else
	{
		while (i < size)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(source + i);
			i++;
		}
	}
	return (dest);
}
