/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:18:11 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/29 13:24:44 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"
#include "../header/mlx.h"
#include "../header/mlx_int.h"

void	ft_get_pos_no_so(t_raycast *rayc, int digit)
{
	if (digit == 'N' - 48)
	{
		rayc->dirx = -0.99;
		rayc->diry = 0;
		rayc->planex = 0;
		rayc->planey = 0.66;
	}
	if (digit == 'S' - 48)
	{
		rayc->dirx = 0.99;
		rayc->diry = 0;
		rayc->planex = 0;
		rayc->planey = -0.66;
	}
}

void	ft_get_we_ea(t_raycast *rayc, int digit)
{
	if (digit == 'W' - 48)
	{
		rayc->dirx = 0;
		rayc->diry = -0.99;
		rayc->planex = -0.66;
		rayc->planey = 0;
	}
	if (digit == 'E' - 48)
	{
		rayc->dirx = 0;
		rayc->diry = 0.99;
		rayc->planex = 0.66;
		rayc->planey = 0;
	}
}

void	ft_affect_pos(t_raycast *rayc, int digit, int j, int i)
{
	if ((digit == 'N' - 48 || digit == 'S' - 48
	|| digit == 'W' - 48 || digit == 'E' - 48)
	&& rayc->posx == -1)
	{
		rayc->posx = j + 0.5;
		rayc->posy = i + 0.5;
		ft_get_pos_no_so(rayc, digit);
		ft_get_we_ea(rayc, digit);
	}
	if (digit == 2)
	{
		rayc->sprite_x[rayc->numsprite] = j;
		rayc->sprite_y[rayc->numsprite] = i;
		rayc->numsprite++;
	}
}

int		ft_check_nb_player(t_raycast *rayc, int j, int i)
{
	if ((rayc->struct_map[j][i] == 'N' - 48
	|| rayc->struct_map[j][i] == 'S' - 48
	|| rayc->struct_map[j][i] == 'W' - 48
	|| rayc->struct_map[j][i] == 'E' - 48)
	&& rayc->posx != -1)
	{
		rayc->error = ERR_NB_PLAYER;
		return (FAILURE);
	}
	return (SUCCESS);
}

int		ft_get_sprite_pos(t_raycast *rayc)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < rayc->endmap)
	{
		while (rayc->struct_map[j][i] != -1)
		{
			if (ft_check_nb_player(rayc, j, i) == FAILURE)
				return (FAILURE);
			ft_affect_pos(rayc, rayc->struct_map[j][i], j, i);
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}
