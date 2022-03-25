/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:04:29 by fheidi            #+#    #+#             */
/*   Updated: 2021/10/21 22:04:29 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	get_int_len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*if_negative(int n)
{
	char	*new_st;
	int		len;

	len = get_int_len(n) + 1;
	new_st = (char *)malloc(len + 1);
	if (NULL == new_st)
		return (NULL);
	new_st[0] = '-';
	new_st[len] = '\0';
	len--;
	while (len > 0)
	{
		new_st[len] = ((n % 10 * -1) + '0');
		n = n / 10;
		len--;
	}
	return (new_st);
}

char	*ft_itoa(int n)
{
	char	*new_st;
	int		sign;
	int		len;

	if (n < 0)
		new_st = if_negative(n);
	else
	{
		len = get_int_len(n);
		new_st = (char *)malloc(len + 1);
		if (NULL == new_st)
			return (NULL);
		sign = 1;
		new_st[len] = '\0';
		len--;
		while ((len) >= 0)
		{
			new_st[len] = ((n % 10 * sign) + '0');
			n = n / 10;
			len--;
		}
	}
	return (new_st);
}
