/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:40:22 by fheidi            #+#    #+#             */
/*   Updated: 2021/10/30 15:59:30 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*rez;
	unsigned int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	rez = (char *)malloc(ft_strlen(s) + 1);
	if (rez == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		rez[i] = f(i, s[i]);
		i++;
	}
	rez[i] = '\0';
	return (rez);
}
