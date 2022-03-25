/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:02:19 by fheidi            #+#    #+#             */
/*   Updated: 2021/11/13 02:57:42 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*(char *)little)
		return ((char *)big);
	while ((char)big[i] && len > i)
	{
		j = 0;
		while ((char)big[i + j] == (char)little[j] && len > (i + j))
		{
			j++;
			if (!(char)little[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
