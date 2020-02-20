/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 03:14:19 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/20 03:14:23 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "filler_vizual.h"

int		go_sound(char *command)
{
	int		status;

	status = 0;
	status = system(command);
	return (status);
}

void	take_sound(t_envars *e, t_gslst *gs)
{
	if (e->prev_turn != gs->turn)
	{
		if (gs->turn == 0 && (gs->flags & TURN_SWITCH) == 0)
			go_sound("afplay Sound/by_Vdelsie.mp3 &");
		if (gs->flags & TURN_SWITCH)
			go_sound("afplay Sound/Look_At_This_Dude.mp3");
		if (gs->turn == e->g->turn_rt - 1)
		{
			if (e->g->p1_rt > e->g->p2_rt)
				go_sound("afplay ./Sound/player_one_you_win.mp3 &");
			else if (e->g->p2_rt > e->g->p1_rt)
				go_sound("afplay ./Sound/player_two_you_win.mp3 &");
		}
		e->prev_turn = gs->turn;
	}
}
