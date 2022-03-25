/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:24:36 by fheidi            #+#    #+#             */
/*   Updated: 2021/10/23 16:14:30 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		rez;

	i = 0;
	while (i < n)
	{
		rez = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
		if (rez != 0)
			return (rez);
		i++;
	}
	return (0);
}
