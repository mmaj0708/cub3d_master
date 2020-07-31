/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealkey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:41:30 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 16:50:18 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"
#include "../header/mlx.h"
#include "../header/mlx_int.h"

int		ft_key_hit(int key, t_raycast *rayc)
{
	rayc->keyboard[key] = 1;
	return (0);
}

int		ft_key_release(int key, t_raycast *rayc)
{
	rayc->keyboard[key] = 0;
	return (0);
}

void	ft_turn_left(t_raycast *r)
{
	if (r->keyboard[ARROW_LEFT] == 1)
	{
		r->olddirx = r->dirx;
		r->dirx = r->dirx * cos(r->rotspeed) - r->diry * sin(r->rotspeed);
		r->diry = r->olddirx * sin(r->rotspeed) + r->diry * cos(r->rotspeed);
		r->oldplanex = r->planex;
		r->planex = r->planex * cos(r->rotspeed) - r->planey * sin(r->rotspeed);
		r->planey = r->oldplanex * sin(r->rotspeed)
		+ r->planey * cos(r->rotspeed);
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

void	ft_turn_right(t_raycast *r)
{
	if (r->keyboard[ARROW_RIGHT] == 1)
	{
		r->olddirx = r->dirx;
		r->dirx = r->dirx * cos(-r->rotspeed) - r->diry * sin(-r->rotspeed);
		r->diry = r->olddirx * sin(-r->rotspeed) + r->diry * cos(-r->rotspeed);
		r->oldplanex = r->planex;
		r->planex = r->planex * cos(-r->rotspeed)
		- r->planey * sin(-r->rotspeed);
		r->planey = r->oldplanex * sin(-r->rotspeed)
		+ r->planey * cos(-r->rotspeed);
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

int		dealkey(t_raycast *rayc)
{
	ft_turn_left(rayc);
	ft_turn_right(rayc);
	ft_mv_forward(rayc);
	ft_mv_backward(rayc);
	ft_mv_left(rayc);
	ft_mv_right(rayc);
	if (rayc->keyboard[ECHAP] == 1)
		ft_quit(rayc);
	return (0);
}
