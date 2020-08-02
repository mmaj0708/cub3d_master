/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:06:49 by mmaj              #+#    #+#             */
/*   Updated: 2020/08/02 22:49:42 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

int		ft_init_mlx(t_raycast *rayc)
{
	rayc->mlx_ptr = mlx_init();
	ft_load_texture(rayc);
	if (!rayc->tex_ptr[4] || !rayc->tex_ptr[3] || !rayc->tex_ptr[2]
	|| !rayc->tex_ptr[1] || !rayc->tex_ptr[0])
	{
		rayc->error = ERR_TEXT;
		ft_quit(rayc);
	}
	mlx_get_screen_size(rayc->mlx_ptr, &rayc->screenw, &rayc->screenh);
	if (rayc->resol_x > rayc->screenw)
		rayc->resol_x = rayc->screenw;
	if (rayc->resol_y > rayc->screenh)
		rayc->resol_y = rayc->screenh;
	rayc->mlx_win = mlx_new_window(rayc->mlx_ptr, rayc->resol_x,
	rayc->resol_y, "Wolf3D");
	ft_data_texture(rayc);
	return (0);
}

int		ft_first_img(t_raycast *rayc)
{
	rayc->rayc_ptr = mlx_new_image(rayc->mlx_ptr,
	rayc->resol_x, rayc->resol_y);
	rayc->pixel_address = mlx_get_data_addr(rayc->rayc_ptr,
	&rayc->bits_per_pixel,
	&rayc->size_line, &rayc->endian);
	put_sky_floor(rayc);
	ft_wallcasting(rayc);
	sprite_cast(rayc);
	mlx_put_image_to_window(rayc->mlx_ptr,
	rayc->mlx_win, rayc->rayc_ptr, 0, 0);
	return (0);
}

void	ft_init_rayc(t_raycast *rayc)
{
	rayc->time = 0;
	rayc->oldtime = 0;
	rayc->w = rayc->resol_x;
	rayc->x = 0;
	rayc->movespeed = 0.1;
	rayc->rotspeed = 0.05;
}
