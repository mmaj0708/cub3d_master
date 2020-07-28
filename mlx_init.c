/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:06:49 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/28 16:23:04 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

// nord : 0, sud : 1, west : 2, east : 3, sprite : 4

int		ft_init_mlx(t_raycast *rayc)
{
	rayc->mlx_ptr = mlx_init();
	rayc->tex_ptr[0] = mlx_xpm_file_to_image(rayc->mlx_ptr, rayc->no, &rayc->tex_width[0], &rayc->tex_height[0]);
	rayc->tex_ptr[1] = mlx_xpm_file_to_image(rayc->mlx_ptr, rayc->so, &rayc->tex_width[1], &rayc->tex_height[1]);
	rayc->tex_ptr[2] = mlx_xpm_file_to_image(rayc->mlx_ptr, rayc->we, &rayc->tex_width[2], &rayc->tex_height[2]);
	rayc->tex_ptr[3] = mlx_xpm_file_to_image(rayc->mlx_ptr, rayc->ea, &rayc->tex_width[3], &rayc->tex_height[3]);
	rayc->tex_ptr[4] = mlx_xpm_file_to_image(rayc->mlx_ptr, rayc->sprite, &rayc->tex_width[4], &rayc->tex_height[4]);
	if (!rayc->tex_ptr[4] || !rayc->tex_ptr[3] || !rayc->tex_ptr[2]
	|| !rayc->tex_ptr[1] || !rayc->tex_ptr[0])
	{
		rayc->error = ERR_TEXT;
		ft_quit(rayc);
	}
	rayc->mlx_win = mlx_new_window(rayc->mlx_ptr, rayc->resol_x,
	rayc->resol_y, "wouf wouf");
	rayc->tex_pix_addr[0] = (int*)mlx_get_data_addr(rayc->tex_ptr[0], &rayc->tex_bpp[0], &rayc->tex_sl[0], &rayc->tex_endian[0]);
	rayc->tex_pix_addr[1] = (int*)mlx_get_data_addr(rayc->tex_ptr[1], &rayc->tex_bpp[1], &rayc->tex_sl[1], &rayc->tex_endian[1]);
	rayc->tex_pix_addr[2] = (int*)mlx_get_data_addr(rayc->tex_ptr[2], &rayc->tex_bpp[2], &rayc->tex_sl[2], &rayc->tex_endian[2]);
	rayc->tex_pix_addr[3] = (int*)mlx_get_data_addr(rayc->tex_ptr[3], &rayc->tex_bpp[3], &rayc->tex_sl[3], &rayc->tex_endian[3]);
	rayc->tex_pix_addr[4] = (int*)mlx_get_data_addr(rayc->tex_ptr[4], &rayc->tex_bpp[4], &rayc->tex_sl[4], &rayc->tex_endian[4]);
	return (0);
}

int		ft_first_img(t_raycast *rayc)
{
	rayc->rayc_ptr = mlx_new_image(rayc->mlx_ptr, rayc->resol_x, rayc->resol_y);
	rayc->pixel_address = mlx_get_data_addr(rayc->rayc_ptr, &rayc->bits_per_pixel,
	&rayc->size_line, &rayc->endian);
	put_sky_floor(rayc);
	ft_wallcasting(rayc);
	sprite_cast(rayc);
	mlx_put_image_to_window(rayc->mlx_ptr, rayc->mlx_win, rayc->rayc_ptr, 0, 0);
	return (0);
}

void	ft_init_rayc(t_raycast *rayc)
{
	rayc->time = 0; // time of current frame
	rayc->oldtime = 0;

	rayc->w = rayc->resol_x;
	rayc->x = 0;

	// speed modifiers (utilise frametime normalement)
	rayc->movespeed = 0.1; // la valeur constante en carré/s
	rayc->rotspeed =  0.05; // la valeur constante en radians/s
}