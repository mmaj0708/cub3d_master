/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 16:49:12 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 16:50:24 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"
#include "../header/mlx.h"
#include "../header/mlx_int.h"

int		is_good_move(int digit)
{
	if (digit == 'N' - 48 || digit == 'S' - 48 || digit == 'W' - 48
	|| digit == 'E' - 48 || digit == 0)
		return (TRUE);
	else
		return (0);
}

void	ft_mv_forward(t_raycast *r)
{
	if (r->keyboard[KEY_W] == 1)
	{
		if (is_good_move(r->struct_map[(int)(r->posx
		+ r->dirx * r->movespeed)][(int)r->posy]) == TRUE)
			r->posx += r->dirx * r->movespeed;
		if (is_good_move(r->struct_map[(int)r->posx][(int)(r->posy
		+ r->diry * r->movespeed)]) == TRUE)
			r->posy += r->diry * r->movespeed;
		mlx_destroy_image(r->mlx_ptr, r->rayc_ptr);
		r->rayc_ptr = mlx_new_image(r->mlx_ptr, r->resol_x, r->resol_y);
		r->pixel_address = mlx_get_data_addr(r->rayc_ptr,
		&r->bits_per_pixel, &r->size_line, &r->endian);
		put_sky_floor(r);
		ft_wallcasting(r);
		sprite_cast(r);
		mlx_put_image_to_window(r->mlx_ptr, r->mlx_win, r->rayc_ptr, 0, 0);
	}
}

void	ft_mv_backward(t_raycast *r)
{
	if (r->keyboard[KEY_S] == 1)
	{
		if (is_good_move(r->struct_map[(int)(r->posx
		- r->dirx * r->movespeed)][(int)r->posy]) == TRUE)
			r->posx -= r->dirx * r->movespeed;
		if (is_good_move(r->struct_map[(int)r->posx][(int)(r->posy
		- r->diry * r->movespeed)]) == TRUE)
			r->posy -= r->diry * r->movespeed;
		mlx_destroy_image(r->mlx_ptr, r->rayc_ptr);
		r->rayc_ptr = mlx_new_image(r->mlx_ptr, r->resol_x, r->resol_y);
		r->pixel_address = mlx_get_data_addr(r->rayc_ptr,
		&r->bits_per_pixel, &r->size_line, &r->endian);
		put_sky_floor(r);
		ft_wallcasting(r);
		sprite_cast(r);
		mlx_put_image_to_window(r->mlx_ptr, r->mlx_win, r->rayc_ptr, 0, 0);
	}
}

void	ft_mv_left(t_raycast *r)
{
	if (r->keyboard[KEY_A] == 1)
	{
		r->perpdirx = r->diry;
		r->perpdiry = -r->dirx;
		if (is_good_move(r->struct_map[(int)(r->posx
		- r->perpdirx * r->movespeed)][(int)r->posy]) == TRUE)
			r->posx -= r->perpdirx * r->movespeed;
		if (is_good_move(r->struct_map[(int)r->posx][(int)(r->posy
		- r->perpdiry * r->movespeed)]) == TRUE)
			r->posy -= r->perpdiry * r->movespeed;
		mlx_destroy_image(r->mlx_ptr, r->rayc_ptr);
		r->rayc_ptr = mlx_new_image(r->mlx_ptr, r->resol_x, r->resol_y);
		r->pixel_address = mlx_get_data_addr(r->rayc_ptr,
		&r->bits_per_pixel, &r->size_line, &r->endian);
		put_sky_floor(r);
		ft_wallcasting(r);
		sprite_cast(r);
		mlx_put_image_to_window(r->mlx_ptr, r->mlx_win, r->rayc_ptr, 0, 0);
	}
}

void	ft_mv_right(t_raycast *r)
{
	if (r->keyboard[KEY_D] == 1)
	{
		r->perpdirx = r->diry;
		r->perpdiry = -r->dirx;
		if (is_good_move(r->struct_map[(int)(r->posx
		+ r->perpdirx * r->movespeed)][(int)r->posy]) == TRUE)
			r->posx += r->perpdirx * r->movespeed;
		if (is_good_move(r->struct_map[(int)r->posx][(int)(r->posy
		+ r->perpdiry * r->movespeed)]) == TRUE)
			r->posy += r->perpdiry * r->movespeed;
		mlx_destroy_image(r->mlx_ptr, r->rayc_ptr);
		r->rayc_ptr = mlx_new_image(r->mlx_ptr, r->resol_x, r->resol_y);
		r->pixel_address = mlx_get_data_addr(r->rayc_ptr,
		&r->bits_per_pixel, &r->size_line, &r->endian);
		put_sky_floor(r);
		ft_wallcasting(r);
		sprite_cast(r);
		mlx_put_image_to_window(r->mlx_ptr, r->mlx_win, r->rayc_ptr, 0, 0);
	}
}
