/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:00:04 by fheidi            #+#    #+#             */
/*   Updated: 2021/10/18 23:00:20 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_st;
	int		len;

	len = ft_strlen(s);
	new_st = (char *)malloc(sizeof(s[0]) * (len + 1));
	if (NULL == new_st)
		return (NULL);
	new_st[len] = '\0';
	while ((len - 1) >= 0)
	{
		new_st[len - 1] = s[len - 1];
		len--;
	}
	return (new_st);
}
