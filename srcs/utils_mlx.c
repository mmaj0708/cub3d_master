/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:06:06 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/31 17:53:56 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

void	ft_load_texture(t_raycast *rayc)
{
	rayc->tex_ptr[0] = mlx_xpm_file_to_image(rayc->mlx_ptr, rayc->no,
	&rayc->tex_width[0], &rayc->tex_height[0]);
	rayc->tex_ptr[1] = mlx_xpm_file_to_image(rayc->mlx_ptr, rayc->so,
	&rayc->tex_width[1], &rayc->tex_height[1]);
	rayc->tex_ptr[2] = mlx_xpm_file_to_image(rayc->mlx_ptr, rayc->we,
	&rayc->tex_width[2], &rayc->tex_height[2]);
	rayc->tex_ptr[3] = mlx_xpm_file_to_image(rayc->mlx_ptr, rayc->ea,
	&rayc->tex_width[3], &rayc->tex_height[3]);
	rayc->tex_ptr[4] = mlx_xpm_file_to_image(rayc->mlx_ptr, rayc->sprite,
	&rayc->tex_width[4], &rayc->tex_height[4]);
}

void	ft_data_texture(t_raycast *rayc)
{
	rayc->tex_pix_addr[0] = (int*)mlx_get_data_addr(rayc->tex_ptr[0],
	&rayc->tex_bpp[0], &rayc->tex_sl[0], &rayc->tex_endian[0]);
	rayc->tex_pix_addr[1] = (int*)mlx_get_data_addr(rayc->tex_ptr[1],
	&rayc->tex_bpp[1], &rayc->tex_sl[1], &rayc->tex_endian[1]);
	rayc->tex_pix_addr[2] = (int*)mlx_get_data_addr(rayc->tex_ptr[2],
	&rayc->tex_bpp[2], &rayc->tex_sl[2], &rayc->tex_endian[2]);
	rayc->tex_pix_addr[3] = (int*)mlx_get_data_addr(rayc->tex_ptr[3],
	&rayc->tex_bpp[3], &rayc->tex_sl[3], &rayc->tex_endian[3]);
	rayc->tex_pix_addr[4] = (int*)mlx_get_data_addr(rayc->tex_ptr[4],
	&rayc->tex_bpp[4], &rayc->tex_sl[4], &rayc->tex_endian[4]);
}
