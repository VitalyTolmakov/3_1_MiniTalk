/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:09:14 by fheidi            #+#    #+#             */
/*   Updated: 2021/11/07 13:18:58 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

void	get_reverse_st_from_ulong(long long ln, char *dst)
{
	int	i;

	i = 0;
	while (ln != 0)
	{
		dst[i] = ln % 10 + '0';
		ln = ln / 10;
		i++;
	}
	dst[i] = '\0';
}

void	int_to_str(int nbr, char *st)
{
	int			len;
	int			i;
	char		reverse_u_st[22];
	long long	ln;

	i = 0;
	ln = nbr;
	if (ln < 0)
	{
		st[i] = '-';
		i++;
		ln = ((-1) * ln);
	}
	get_reverse_st_from_ulong(ln, reverse_u_st);
	len = ft_strlen(reverse_u_st);
	while (len > 0)
	{
		len--;
		st[i] = reverse_u_st[len];
		i++;
	}
	st[i] = '\0';
}

void	ft_putnbr_fd(int n, int fd)
{
	char	s[22];

	if (n == 0)
		write(fd, "0", 1);
	else
	{
		int_to_str(n, s);
		write(fd, s, ft_strlen(s));
	}
}
