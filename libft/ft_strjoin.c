/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:43:57 by fheidi            #+#    #+#             */
/*   Updated: 2021/10/21 13:43:57 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_st;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_st = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (NULL == new_st)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_st[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_st[i++] = s2[j++];
	new_st[i] = '\0';
	return (new_st);
}
