/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:38:37 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 14:10:02 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"
#include "../header/mlx.h"
#include "../header/mlx_int.h"

int		ft_swap(double *spritedistance, t_raycast *rayc, int i)
{
	double	save_x;
	double	save_y;
	double	save_dist;

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

void	ft_sortsprite(double *sprdst, t_raycast *rayc)
{
	int	i;

	i = 0;
	while (i + 1 < rayc->numsprite)
	{
		if (sprdst[i] < sprdst[i + 1])
		{
			ft_swap(sprdst, rayc, i);
			i = 0;
		}
		i++;
	}
}

void	ft_calc_pix_tex(t_raycast *rayc)
{
	rayc->d = rayc->y * 256 - rayc->resol_y * 128 + rayc->spriteheight * 128;
	rayc->texy = ((rayc->d * rayc->tex_height[4]) / rayc->spriteheight) / 256;
	rayc->pix_color = rayc->tex_pix_addr[4][rayc->texx
	+ rayc->texy * rayc->tex_sl[4] / 4];
}

void	draw_sprite(t_raycast *rayc)
{
	rayc->stripe = rayc->drawstartx;
	while (rayc->stripe < rayc->drawendx)
	{
		rayc->texx = (int)(256 * (rayc->stripe
		- (-rayc->spritewidth / 2 + rayc->spritescreenx))
		* rayc->tex_width[4] / rayc->spritewidth) / 256;
		if (rayc->transformy > 0 && rayc->stripe >= 0
		&& rayc->stripe <= rayc->resol_x
		&& rayc->transformy < rayc->zbuffer[rayc->stripe])
		{
			rayc->y = rayc->drawstarty + 1;
			while (rayc->y < rayc->drawendy)
			{
				ft_calc_pix_tex(rayc);
				if ((rayc->pix_color & 0x00FFFFFF) != 0)
					put_pixel_to_rayc(rayc, rayc->stripe,
					rayc->y, rayc->pix_color);
				rayc->y++;
			}
		}
		rayc->stripe++;
	}
}

void	sprite_cast(t_raycast *r)
{
	int		i;
	double	sprdst[r->numsprite];

	i = 0;
	while (i < r->numsprite)
	{
		sprdst[i] = ((r->posx - r->sprite_x[i]) * (r->posx - r->sprite_x[i])
		+ (r->posy - r->sprite_y[i]) * (r->posy - r->sprite_y[i]));
		i++;
	}
	ft_sortsprite(sprdst, r);
	i = 0;
	while (i < r->numsprite)
	{
		sprite_matrix(r, i);
		draw_sprite(r);
		i++;
	}
}
