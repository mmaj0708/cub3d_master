/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:22:34 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 16:26:07 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

void		put_pixel_to_rayc(t_raycast *rayc, int x, int y, int color)
{
	int		*addr;

	addr = (int *)rayc->pixel_address;
	addr[x + y * rayc->size_line / 4] = color;
	return ;
}

int			ft_get_color_int(int red, int green, int blue)
{
	int rgb;

	rgb = red;
	rgb = (rgb << 8) + blue;
	rgb = (rgb << 8) + green;
	return (rgb);
}

void		draw_ceiling(t_raycast *rayc, int i, int j)
{
	int *addr;

	addr = (int *)rayc->pixel_address;
	while (j < rayc->resol_y / 2)
	{
		while (i < rayc->resol_x)
		{
			put_pixel_to_rayc(rayc, i, j,
			ft_get_color_int(rayc->rc, rayc->bc, rayc->gc));
			i++;
		}
		j++;
		i = 0;
	}
}

void		draw_floor(t_raycast *rayc, int i, int j)
{
	j = rayc->resol_y / 2;
	while (j < rayc->resol_y)
	{
		while (i < rayc->resol_x)
		{
			put_pixel_to_rayc(rayc, i, j,
			ft_get_color_int(rayc->rf, rayc->bf, rayc->gf));
			i++;
		}
		j++;
		i = 0;
	}
}

int			put_sky_floor(t_raycast *rayc)
{
	int i;
	int j;

	j = 0;
	i = 0;
	draw_ceiling(rayc, i, j);
	draw_floor(rayc, i, j);
	return (0);
}
