/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:00:37 by fheidi            #+#    #+#             */
/*   Updated: 2021/11/13 04:14:31 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_st;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	new_st = (char *)malloc(len + 1);
	if (new_st == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		new_st[i] = s[(size_t)start + i];
		i++;
	}
	new_st[i] = '\0';
	return (new_st);
}
