/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:02:19 by fheidi            #+#    #+#             */
/*   Updated: 2022/02/27 14:45:31 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned long long	nbr;
	int					sign;

	sign = 1;
	nbr = 0;
	while (*nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= 48 && *nptr <= 57)
	{
		nbr = nbr * 10 + (*nptr - '0');
		nptr++;
		if (nbr > 9223372036854775807 && sign == 1)
			return (-1);
		else if (nbr > 9223372036854775807 && sign == -1)
			return (0);
	}
	return ((int)(nbr * sign));
}
