/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:41:32 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/25 20:36:34 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_player *player)
{
	double olddirx;
	double oldplanex;

	olddirx = player->pdx;
	oldplanex = player->planex;
	player->pdx = player->pdx * cos(-TURN) - player->pdy * sin(-TURN);
	player->pdy = olddirx * sin(-TURN) + player->pdy * cos(-TURN);
	player->planex = player->planex * cos(-TURN) - player->planey * sin(-TURN);
	player->planey = oldplanex * sin(-TURN) + player->planey * cos(-TURN);
}

void	turn_right(t_player *player)
{
	double olddirx;
	double oldplanex;

	olddirx = player->pdx;
	oldplanex = player->planex;
	player->pdx = player->pdx * cos(TURN) - player->pdy * sin(TURN);
	player->pdy = olddirx * sin(TURN) + player->pdy * cos(TURN);
	player->planex = player->planex * cos(TURN) - player->planey * sin(TURN);
	player->planey = oldplanex * sin(TURN) + player->planey * cos(TURN);
}
