/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:13:39 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/31 17:53:56 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

void	ft_get_perpwalldist(t_raycast *r)
{
	if (r->side == 0)
		r->perpwalldist = (r->mapx - r->posx + (1 - r->stepx) / 2) / r->raydirx;
	else
		r->perpwalldist = (r->mapy - r->posy + (1 - r->stepy) / 2) / r->raydiry;
	r->lineheight = (int)(r->resol_y / r->perpwalldist);
	if (r->lineheight > WALL_HEIGHT_PROTECTION)
		r->lineheight = WALL_HEIGHT_PROTECTION;
	r->drawstart = -r->lineheight / 2 + r->resol_y / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + r->resol_y / 2;
	if (r->drawend >= r->resol_y)
		r->drawend = r->resol_y;
}

void	ft_choose_texture(t_raycast *rayc)
{
	if (rayc->side == 0 && rayc->raydirx < 0)
		rayc->texnum = 1;
	if (rayc->side == 0 && rayc->raydirx > 0)
		rayc->texnum = 0;
	if (rayc->side == 1 && rayc->raydiry < 0)
		rayc->texnum = 3;
	if (rayc->side == 1 && rayc->raydiry > 0)
		rayc->texnum = 2;
}

void	ft_calculate_texture(t_raycast *r)
{
	if (r->side == 0)
		r->wallx = r->posy + r->perpwalldist * r->raydiry;
	else
		r->wallx = r->posx + r->perpwalldist * r->raydirx;
	r->wallx -= floor((r->wallx));
	r->texx = (int)(r->wallx * (double)r->tex_width[r->texnum]);
	r->y = r->drawstart;
	while (r->y < r->drawend)
	{
		r->d = r->y * 256 - r->resol_y * 128 + r->lineheight * 128;
		r->texy = ((r->d * r->tex_height[r->texnum]) / r->lineheight) / 256;
		r->pix_color = r->tex_pix_addr[r->texnum][r->texx
		+ r->texy * r->tex_sl[r->texnum] / 4];
		put_pixel_to_rayc(r, r->x, r->y, r->pix_color);
		r->y++;
	}
}

void	ft_wallcasting(t_raycast *rayc)
{
	rayc->x = 0;
	while (rayc->x < rayc->w)
	{
		ft_get_raydir(rayc);
		ft_get_step_sidedist(rayc);
		ft_dda(rayc);
		ft_get_perpwalldist(rayc);
		ft_choose_texture(rayc);
		ft_calculate_texture(rayc);
		rayc->zbuffer[rayc->x] = rayc->perpwalldist;
		rayc->x++;
	}
}
