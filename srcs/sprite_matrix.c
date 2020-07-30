/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 12:45:20 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 13:13:36 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

void	ft_spr_draw_calc(t_raycast *rayc)
{
	rayc->spriteheight = abs((int)(rayc->resol_y / rayc->transformy));
	rayc->drawstarty = -rayc->spriteheight / 2 + rayc->resol_y / 2;
	if (rayc->drawstarty < 0)
		rayc->drawstarty = -1;
	rayc->drawendy = rayc->spriteheight / 2 + rayc->resol_y / 2;
	if (rayc->drawendy >= rayc->resol_y)
		rayc->drawendy = rayc->resol_y - 1;
	rayc->spritewidth = abs((int)(rayc->resol_y / rayc->transformy));
	rayc->drawstartx = -rayc->spritewidth / 2 + rayc->spritescreenx;
	if (rayc->drawstartx < 0)
		rayc->drawstartx = 0;
	rayc->drawendx = rayc->spritewidth / 2 + rayc->spritescreenx;
	if (rayc->drawendx >= rayc->resol_x)
		rayc->drawendx = rayc->resol_x;
}

void	sprite_matrix(t_raycast *rayc, int i)
{
	rayc->sprite_c_x = rayc->sprite_x[i] - rayc->posx + 0.5;
	rayc->sprite_c_y = rayc->sprite_y[i] - rayc->posy + 0.5;
	rayc->invdet = 1.0
	/ (rayc->planex * rayc->diry - rayc->dirx * rayc->planey);
	rayc->transformx = rayc->invdet
	* (rayc->diry * rayc->sprite_c_x - rayc->dirx * rayc->sprite_c_y);
	rayc->transformy = rayc->invdet
	* (-rayc->planey * rayc->sprite_c_x + rayc->planex * rayc->sprite_c_y);
	rayc->spritescreenx = (int)((rayc->resol_x / 2)
	* (1 + rayc->transformx / rayc->transformy));
	ft_spr_draw_calc(rayc);
}
