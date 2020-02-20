/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:20:37 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/18 20:41:51 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "filler_vizual.h"

int			idx(int row, int col, int dim)
{
	return (row * dim + col);
}

double		ft_lint(double start, double end, double decimal_percent)
{
	if (start == end)
		return (start);
	return (start * (1.0 - decimal_percent) + (end * decimal_percent));
}

char		*board_strdup(t_game *game, int i, const char *s)
{
	char	*new_s;
	char	*start;
	size_t	len;
	size_t	j;

	len = ft_strlen(s);
	if ((new_s = (char *)malloc((len + 1) * sizeof(*new_s))) != NULL)
	{
		new_s[len] = '\0';
		start = new_s;
		j = 0;
		while (j < len)
		{
			*new_s = *s;
			if (*s == 'o' || *s == 'x')
				game->color_t_rt[idx(i, (int)j, game->w)] = game->gss->turn;
			new_s++;
			s++;
			j++;
		}
		return (start);
	}
	return (NULL);
}
