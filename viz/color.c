/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:12:22 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/11 14:33:08 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_vizual.h"

int			color_lint(int c1, int c2, double decimal_percent)
{
	int	r;
	int	g;
	int	b;

	if (c1 == c2)
		return (c1);
	if (decimal_percent == 0.0)
		return (c1);
	if (decimal_percent == 1.0)
		return (c2);
	r = (int)ft_lint(((c1 >> 16) & 0xFF), ((c2 >> 16) & 0xFF), decimal_percent);
	g = (int)ft_lint(((c1 >> 8) & 0xFF), ((c2 >> 8) & 0xFF), decimal_percent);
	b = (int)ft_lint((c1 & 0xFF), (c2 & 0xFF), decimal_percent);
	return (r << 16 | g << 8 | b);
}

int			choose_board_color(t_envars *e, int row, int col)
{
	t_game	*g;
	t_gslst	*gs;
	double	progress;
	int		color;

	gs = e->curr_gs;
	g = e->g;
	color = 0;
	progress = (double)gs->color_tab[idx(row, col, g->w)] / (double)g->turn_rt;
	if (gs->board[row][col] == '.')
		color = 0xD3D3D3;
	else if (gs->board[row][col] == 'O')
		color = color_lint(0x99FF99, 0x00FF00, progress);
	else if (gs->board[row][col] == 'o')
		color = 0xFFA500;
	else if (gs->board[row][col] == 'X')
		color = color_lint(0xFFC4C4, 0xFF0000, progress);
	else if (gs->board[row][col] == 'x')
		color = 0x00A5FF;
	return (color);
}

int			choose_piece_color(t_envars *e, int row, int col)
{
	int		color;
	t_gslst	*gs;

	gs = e->curr_gs;
	color = 0;
	if (gs->piece[row][col] == '.')
		color = 0xD3D3D3;
	else if (gs->piece[row][col] == '*')
	{
		if (gs->flags & P1_PLACED)
			color = 0x18FF0A;
		else
			color = 0xFE1537;
	}
	return (color);
}
