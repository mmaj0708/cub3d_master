/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealkey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:41:30 by mmaj              #+#    #+#             */
/*   Updated: 2020/06/25 18:04:57 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

int	ft_key_hit(int key, t_raycast *rayc)
{
	rayc->keyboard[key] = 1;
	return (0);
}

int	ft_key_release(int key, t_raycast *rayc)
{
	rayc->keyboard[key] = 0;
	return (0);
}

int	is_good_move(int digit)
{
	if (digit == 'N' - 48 || digit == 'S' - 48 || digit == 'W' - 48
	|| digit == 'E' - 48 || digit == 2 || digit == 0)
		return (TRUE);
	else
		return (0);
}

int	dealkey(t_raycast *rayc)
{
	if (rayc->keyboard[ARROW_LEFT] == 1)
	{		
		rayc->olddirx = rayc->dirx;
		rayc->dirx = rayc->dirx * cos(rayc->rotspeed) - rayc->diry * sin(rayc->rotspeed);
		rayc->diry = rayc->olddirx * sin(rayc->rotspeed) + rayc->diry * cos(rayc->rotspeed);
		rayc->oldplanex = rayc->planex;
		rayc->planex = rayc->planex * cos(rayc->rotspeed) - rayc->planey * sin(rayc->rotspeed);
		rayc->planey = rayc->oldplanex * sin(rayc->rotspeed) + rayc->planey * cos(rayc->rotspeed);

		mlx_destroy_image(rayc->mlx_ptr, rayc->rayc_ptr);
		rayc->rayc_ptr = mlx_new_image(rayc->mlx_ptr, rayc->resol_x, rayc->resol_y);
		rayc->pixel_address = mlx_get_data_addr(rayc->rayc_ptr,
		&rayc->bits_per_pixel, &rayc->size_line, &rayc->endian);

		put_sky_floor(rayc);
		ft_wallcasting(rayc);
		sprite_cast(rayc);
		mlx_put_image_to_window(rayc->mlx_ptr, rayc->mlx_win, rayc->rayc_ptr, 0, 0);
	}
	if (rayc->keyboard[ARROW_RIGHT] == 1)
	{
		rayc->olddirx = rayc->dirx;
		rayc->dirx = rayc->dirx * cos(-rayc->rotspeed) - rayc->diry * sin(-rayc->rotspeed);
		rayc->diry = rayc->olddirx * sin(-rayc->rotspeed) + rayc->diry * cos(-rayc->rotspeed);
		rayc->oldplanex = rayc->planex;
		rayc->planex = rayc->planex * cos(-rayc->rotspeed) - rayc->planey * sin(-rayc->rotspeed);
		rayc->planey = rayc->oldplanex * sin(-rayc->rotspeed) + rayc->planey * cos(-rayc->rotspeed);
		
		mlx_destroy_image(rayc->mlx_ptr, rayc->rayc_ptr);
		rayc->rayc_ptr = mlx_new_image(rayc->mlx_ptr, rayc->resol_x, rayc->resol_y);
		rayc->pixel_address = mlx_get_data_addr(rayc->rayc_ptr,
		&rayc->bits_per_pixel, &rayc->size_line, &rayc->endian);

		put_sky_floor(rayc);
		ft_wallcasting(rayc);
		sprite_cast(rayc);
		mlx_put_image_to_window(rayc->mlx_ptr, rayc->mlx_win, rayc->rayc_ptr, 0, 0);
	}
	if (rayc->keyboard[KEY_Z] == 1)
	{
		if (is_good_move(rayc->struct_map[(int)(rayc->posx + rayc->dirx * rayc->movespeed)][(int)rayc->posy]) == TRUE) // pk false ? Il faut regarder s'il y a bien un espace en ces coord.
			rayc->posx += rayc->dirx * rayc->movespeed;
		if (is_good_move(rayc->struct_map[(int)rayc->posx][(int)(rayc->posy + rayc->diry * rayc->movespeed)]) == TRUE)
			rayc->posy += rayc->diry * rayc->movespeed;
		
		mlx_destroy_image(rayc->mlx_ptr, rayc->rayc_ptr);
		rayc->rayc_ptr = mlx_new_image(rayc->mlx_ptr, rayc->resol_x, rayc->resol_y);
		rayc->pixel_address = mlx_get_data_addr(rayc->rayc_ptr,
		&rayc->bits_per_pixel, &rayc->size_line, &rayc->endian);

		put_sky_floor(rayc);
		ft_wallcasting(rayc);
		sprite_cast(rayc);
		mlx_put_image_to_window(rayc->mlx_ptr, rayc->mlx_win, rayc->rayc_ptr, 0, 0);
	}
	if (rayc->keyboard[KEY_S] == 1)
	{
		if (is_good_move(rayc->struct_map[(int)(rayc->posx - rayc->dirx * rayc->movespeed)][(int)rayc->posy]) == TRUE) // pk false ? Il faut regarder s'il y a bien un espace en ces coord.
			rayc->posx -= rayc->dirx * rayc->movespeed;
		if (is_good_move(rayc->struct_map[(int)rayc->posx][(int)(rayc->posy - rayc->diry * rayc->movespeed)]) == TRUE)
			rayc->posy -= rayc->diry * rayc->movespeed;
		
		mlx_destroy_image(rayc->mlx_ptr, rayc->rayc_ptr);
		rayc->rayc_ptr = mlx_new_image(rayc->mlx_ptr, rayc->resol_x, rayc->resol_y);
		rayc->pixel_address = mlx_get_data_addr(rayc->rayc_ptr,
		&rayc->bits_per_pixel, &rayc->size_line, &rayc->endian);

		put_sky_floor(rayc);
		ft_wallcasting(rayc);
		sprite_cast(rayc);
		mlx_put_image_to_window(rayc->mlx_ptr, rayc->mlx_win, rayc->rayc_ptr, 0, 0);
	}
	if (rayc->keyboard[KEY_Q] == 1)
	{
		rayc->perpdirx = rayc->diry;
		rayc->perpdiry = -rayc->dirx;
		if (is_good_move(rayc->struct_map[(int)(rayc->posx - rayc->perpdirx * rayc->movespeed)][(int)rayc->posy]) == TRUE) // pk false ? Il faut regarder s'il y a bien un espace en ces coord.
			rayc->posx -= rayc->perpdirx * rayc->movespeed;
		if (is_good_move(rayc->struct_map[(int)rayc->posx][(int)(rayc->posy - rayc->perpdiry * rayc->movespeed)]) == TRUE)
			rayc->posy -= rayc->perpdiry * rayc->movespeed;

		mlx_destroy_image(rayc->mlx_ptr, rayc->rayc_ptr);
		rayc->rayc_ptr = mlx_new_image(rayc->mlx_ptr, rayc->resol_x, rayc->resol_y);
		rayc->pixel_address = mlx_get_data_addr(rayc->rayc_ptr,
		&rayc->bits_per_pixel, &rayc->size_line, &rayc->endian);

		put_sky_floor(rayc);
		ft_wallcasting(rayc);
		sprite_cast(rayc);
		mlx_put_image_to_window(rayc->mlx_ptr, rayc->mlx_win, rayc->rayc_ptr, 0, 0);
	}
	if (rayc->keyboard[KEY_D] == 1)
	{
		rayc->perpdirx = rayc->diry;
		rayc->perpdiry = -rayc->dirx;
		if (is_good_move(rayc->struct_map[(int)(rayc->posx + rayc->perpdirx * rayc->movespeed)][(int)rayc->posy]) == TRUE) // pk false ? Il faut regarder s'il y a bien un espace en ces coord.
			rayc->posx += rayc->perpdirx * rayc->movespeed;
		if (is_good_move(rayc->struct_map[(int)rayc->posx][(int)(rayc->posy + rayc->perpdiry * rayc->movespeed)]) == TRUE)
			rayc->posy += rayc->perpdiry * rayc->movespeed;

		mlx_destroy_image(rayc->mlx_ptr, rayc->rayc_ptr);
		rayc->rayc_ptr = mlx_new_image(rayc->mlx_ptr, rayc->resol_x, rayc->resol_y);
		rayc->pixel_address = mlx_get_data_addr(rayc->rayc_ptr,
		&rayc->bits_per_pixel, &rayc->size_line, &rayc->endian);

		put_sky_floor(rayc);
		ft_wallcasting(rayc);
		sprite_cast(rayc);
		mlx_put_image_to_window(rayc->mlx_ptr, rayc->mlx_win, rayc->rayc_ptr, 0, 0);
	}
	if (rayc->keyboard[ECHAP] == 1)
		ft_quit(rayc);
	return (0);
}
