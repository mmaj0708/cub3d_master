/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcasting_calculs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 16:59:21 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/31 17:53:56 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

void	ft_get_raydir(t_raycast *rayc)
{
	rayc->camerax = 2 * rayc->x / (double)rayc->w - 1;
	rayc->raydirx = rayc->dirx + rayc->planex * rayc->camerax;
	rayc->raydiry = rayc->diry + rayc->planey * rayc->camerax;
	rayc->mapx = rayc->posx;
	rayc->mapy = rayc->posy;
	rayc->deltadistx = fabs(1 / rayc->raydirx);
	rayc->deltadisty = fabs(1 / rayc->raydiry);
	rayc->hit = 0;
}

void	ft_get_step_sidedist(t_raycast *rayc)
{
	if (rayc->raydirx < 0)
	{
		rayc->stepx = -1;
		rayc->sidedistx = (rayc->posx - rayc->mapx) * rayc->deltadistx;
	}
	else
	{
		rayc->stepx = 1;
		rayc->sidedistx = (rayc->mapx + 1.0 - rayc->posx) * rayc->deltadistx;
	}
	if (rayc->raydiry < 0)
	{
		rayc->stepy = -1;
		rayc->sidedisty = (rayc->posy - rayc->mapy) * rayc->deltadisty;
	}
	else
	{
		rayc->stepy = 1;
		rayc->sidedisty = (rayc->mapy + 1.0 - rayc->posy) * rayc->deltadisty;
	}
}

void	ft_dda(t_raycast *rayc)
{
	while (rayc->hit == 0)
	{
		if (rayc->sidedistx < rayc->sidedisty)
		{
			rayc->sidedistx += rayc->deltadistx;
			rayc->mapx += rayc->stepx;
			rayc->side = 0;
		}
		else
		{
			rayc->sidedisty += rayc->deltadisty;
			rayc->mapy += rayc->stepy;
			rayc->side = 1;
		}
		if (rayc->struct_map[rayc->mapx][rayc->mapy] == 1)
			rayc->hit = 1;
	}
}
