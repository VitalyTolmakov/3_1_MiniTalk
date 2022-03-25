/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:58:42 by fheidi            #+#    #+#             */
/*   Updated: 2021/11/13 06:07:31 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new_st;
	size_t	i;

	new_st = (char *)malloc(nmemb * size);
	if (NULL == new_st)
		return (NULL);
	i = 0;
	while (i < (size * nmemb))
	{
		new_st[i] = 0;
		i++;
	}
	return (new_st);
}
