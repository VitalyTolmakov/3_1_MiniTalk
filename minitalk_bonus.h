/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:49:40 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/13 11:49:42 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "libft/libft.h"

void	err_exit(char *st)
{
	write(1, st, ft_strlen(st));
	exit (1);
}

typedef struct s_line
{
	int		ndig;
	char	sym;
	char	*line;
	int		size;
}	t_line;

#endif