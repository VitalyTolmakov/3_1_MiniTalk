/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:24:36 by fheidi            #+#    #+#             */
/*   Updated: 2021/10/27 15:23:32 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		rez;

	if (n > ft_strlen(s2))
	{
		if (ft_strlen(s1) > ft_strlen(s2))
			n = ft_strlen(s1);
		else
			n = ft_strlen(s2);
	}
	i = 0;
	while (i < (n))
	{
		rez = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (rez != 0)
		{
			return (rez);
		}
		i++;
	}
	return (0);
}
