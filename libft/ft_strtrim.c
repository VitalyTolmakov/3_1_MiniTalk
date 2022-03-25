/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:10:03 by fheidi            #+#    #+#             */
/*   Updated: 2021/10/21 19:10:03 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;

	if (s1 == NULL)
		return (NULL);
	begin = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[begin]) && s1[begin] != '\0')
		begin++;
	while (ft_strchr(set, s1[end]) && begin <= end)
		end--;
	return (ft_substr(s1, begin, end - begin + 1));
}
