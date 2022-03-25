/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:42:53 by fheidi            #+#    #+#             */
/*   Updated: 2021/11/14 10:34:23 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_nbr_strs(char const *trim_s, char sep)
{
	int	i;
	int	nbr_strs;

	i = 0;
	nbr_strs = 0;
	while (trim_s[i])
	{
		if (trim_s[i] == sep && trim_s[i - 1] != sep)
			nbr_strs++;
		i++;
	}
	return (nbr_strs + 1);
}

void	free_m_str(char **m_str)
{
	int	i;

	i = 0;
	while (m_str[i] != NULL)
	{
		free(m_str[i]);
		i++;
	}
	free(m_str);
	m_str = NULL;
}

int	make_sub_str_array(char **sub_m_str, int i_nbr_str, char *str)
{
	sub_m_str[i_nbr_str] = (char *)malloc(ft_strlen(str) + 1);
	if (NULL == sub_m_str[i_nbr_str])
	{
		free_m_str(sub_m_str);
		return (-1);
	}
	ft_strlcpy(sub_m_str[i_nbr_str], str, ft_strlen(str) + 1);
	return (0);
}

char	**make_m_str(char *trim_s, char **sub_m_str, char sep, int nbr_strs)
{
	t_split_list	h;

	h.i_trim_sp = 0;
	h.i_nbr_str_sp = 0;
	h.i_str_sp = 0;
	sub_m_str[nbr_strs] = NULL;
	h.str_sp = (char *)malloc(ft_strlen(trim_s) + 1);
	if (NULL == h.str_sp)
		return (NULL);
	while ((size_t)nbr_strs > h.i_nbr_str_sp)
	{
		if (trim_s[h.i_trim_sp] != sep && (trim_s[h.i_trim_sp] != '\0'))
			h.str_sp[h.i_str_sp++] = trim_s[h.i_trim_sp];
		else if ((trim_s[h.i_trim_sp] == sep && trim_s[h.i_trim_sp - 1] != sep)
			|| (trim_s[h.i_trim_sp] == '\0'))
		{
			h.str_sp[h.i_str_sp] = '\0';
			if (make_sub_str_array(sub_m_str, h.i_nbr_str_sp++, h.str_sp) == -1)
				return (NULL);
			h.i_str_sp = 0;
		}
		h.i_trim_sp++;
	}
	free(h.str_sp);
	return (sub_m_str);
}

char	**ft_split(char const *s, char c)
{
	char	**m_str;
	char	*trim_s;
	char	set[2];

	if (s == NULL)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	trim_s = ft_strtrim(s, set);
	if (trim_s == NULL || trim_s[0] == '\0')
	{
		m_str = (char **)malloc(sizeof(char *));
		if (NULL == m_str)
			return (NULL);
		m_str[0] = NULL;
		free(trim_s);
		return (m_str);
	}
	m_str = (char **)malloc((get_nbr_strs(trim_s, c) + 1) * sizeof(char *));
	if (NULL == m_str)
		return (NULL);
	m_str = make_m_str(trim_s, m_str, c, get_nbr_strs(trim_s, c));
	free(trim_s);
	return (m_str);
}
