/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelta <gdelta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:41:29 by gdelta            #+#    #+#             */
/*   Updated: 2021/03/25 20:33:03 by gdelta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_map *map, t_player *player)
{
	if (map->map[(int)player->py]
	[(int)(player->px + player->pdx * SPEED)] == '0')
		player->px += player->pdx * SPEED;
	if (map->map[(int)(player->py + player->pdy * SPEED)]
	[(int)player->px] == '0')
		player->py += player->pdy * SPEED;
}

void	move_backward(t_map *map, t_player *player)
{
	if (map->map[(int)player->py]
	[(int)(player->px - player->pdx * SPEED)] == '0')
		player->px -= player->pdx * SPEED;
	if (map->map[(int)(player->py - player->pdy * SPEED)]
	[(int)player->px] == '0')
		player->py -= player->pdy * SPEED;
}

void	move_left(t_map *map, t_player *player)
{
	if (map->map[(int)player->py]
	[(int)(player->px - player->planex * SPEED)] == '0')
		player->px -= player->planex * SPEED;
	if (map->map[(int)(player->py - player->planey * SPEED)]
	[(int)player->px] == '0')
		player->py -= player->planey * SPEED;
}

void	move_right(t_map *map, t_player *player)
{
	if (map->map[(int)player->py]
	[(int)(player->px + player->planex * SPEED)] == '0')
		player->px += player->planex * SPEED;
	if (map->map[(int)(player->py + player->planey * SPEED)]
	[(int)player->px] == '0')
		player->py += player->planey * SPEED;
}
