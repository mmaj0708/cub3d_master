/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:38:37 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/22 18:42:57 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

int		ft_swap(int *spritedistance, t_raycast *rayc, int i)
{
	int	save_x;
	int	save_y;
	int	save_dist;

	save_x = rayc->sprite_x[i];
	save_y = rayc->sprite_y[i];
	save_dist = spritedistance[i];
	rayc->sprite_x[i] = rayc->sprite_x[i + 1];
	rayc->sprite_y[i] = rayc->sprite_y[i + 1];
	spritedistance[i] = spritedistance[i + 1];
	rayc->sprite_x[i + 1] = save_x;
	rayc->sprite_y[i + 1] = save_y;
	spritedistance[i + 1] = save_dist;
	return (0);
}

void	ft_sortsprite(int	*spriteorder, int	*spritedistance, t_raycast *rayc)
{
	int	i;

	i = 0;
	while (i + 1 < rayc->numsprite)
	{
		if (spritedistance[i] < spritedistance[i + 1])
		{
			ft_swap(spritedistance, rayc, i);
			i = 0;
		}
		i++;
	}
}

void	sprite_matrix(t_raycast *rayc, int i)
{
	rayc->sprite_c_x = rayc->sprite_x[i] - rayc->posx; // + 0.5 pour centrer ?
	rayc->sprite_c_y = rayc->sprite_y[i] - rayc->posy;

	rayc->invdet = 1.0 / (rayc->planex * rayc->diry - rayc->dirx * rayc->planey);
	rayc->transformx = rayc->invdet * (rayc->diry * rayc->sprite_c_x - rayc->dirx * rayc->sprite_c_y);
	rayc->transformy = rayc->invdet * (-rayc->planey * rayc->sprite_c_x + rayc->planex * rayc->sprite_c_y);
	// rayc->spritescreenx = (int)((rayc->resol_x / 2) * (1 + rayc->transformx / rayc->transformy));
	rayc->spritescreenx = (int)((rayc->resol_x / 2) * (1 + rayc->transformx / rayc->transformy));
	// height of sprite on screen
	rayc->spriteheight = abs((int)(rayc->resol_y / rayc->transformy));
	rayc->drawstarty = -rayc->spriteheight / 2 + rayc->resol_y / 2;
	if (rayc->drawstarty < 0)
		rayc->drawstarty = -1; // peut causer prob si ça bug
	rayc->drawendy = rayc->spriteheight / 2 + rayc->resol_y / 2;
	if (rayc->drawendy >= rayc->resol_y)
		rayc->drawendy = rayc->resol_y - 1;
		// width of sprite
	rayc->spritewidth = abs((int)(rayc->resol_y / rayc->transformy));
	rayc->drawstartx = -rayc->spritewidth / 2 + rayc->spritescreenx;
	if (rayc->drawstartx < 0)
		rayc->drawstartx = 0;
	rayc->drawendx = rayc->spritewidth / 2 + rayc->spritescreenx;
	if (rayc->drawendx >= rayc->resol_x)
		rayc->drawendx = rayc->resol_x;
}

void	draw_sprite(t_raycast *rayc)
{
	int	*addr;

	addr = (int *)rayc->pixel_address;
	rayc->stripe = rayc->drawstartx ;
	while (rayc->stripe < rayc->drawendx)
	{
		rayc->texx = (int)(256 * (rayc->stripe - (-rayc->spritewidth / 2 + rayc->spritescreenx)) * rayc->tex_width[4] / rayc->spritewidth) / 256;
		if (rayc->transformy > 0 && rayc->stripe >= 0 && rayc->stripe <= rayc->resol_x && rayc->transformy < rayc->zbuffer[rayc->stripe])
		{
			rayc->y = rayc->drawstarty + 1;
			while (rayc->y <= rayc->drawendy)
			{
				rayc->d = rayc->y * 256 - rayc->resol_y * 128 + rayc->spriteheight * 128;
				rayc->texy = ((rayc->d * rayc->tex_height[4]) / rayc->spriteheight) / 256;
				rayc->pix_color = rayc->tex_pix_addr[4][rayc->texx + rayc->texy * rayc->tex_sl[4] / 4];
				if ((rayc->pix_color & 0x00FFFFFF) != 0)
					put_pixel_to_rayc(addr, rayc->stripe, rayc->y, rayc->pix_color, rayc->size_line);
				rayc->y++;
			}
		}
		rayc->stripe++;
	}
}

void	sprite_cast(t_raycast *rayc)
{
	int	i;
	int spritedistance[rayc->numsprite];
	int spriteorder[rayc->numsprite];
	
	i = 0;
	// distance sprite -> joueur
	while (i < rayc->numsprite)
	{
		spriteorder[i] = i;
		spritedistance[i] = ((rayc->posx - rayc->sprite_x[i]) * (rayc->posx - rayc->sprite_x[i]) + (rayc->posy - rayc->sprite_y[i]) * (rayc->posy - rayc->sprite_y[i]));
		i++;
	}
	ft_sortsprite(spriteorder, spritedistance, rayc);
	i = 0;
	while (i < rayc->numsprite)
	{
		sprite_matrix(rayc, i);
	// draw sprite
		draw_sprite(rayc);
		i++;
	}	
}
