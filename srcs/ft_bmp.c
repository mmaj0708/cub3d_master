/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 17:32:39 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 16:43:09 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"
#include "../header/mlx.h"
#include "../header/mlx_int.h"

int		ft_init_mlx_bmp(t_raycast *rayc)
{
	rayc->mlx_ptr = mlx_init();
	ft_load_texture(rayc);
	if (!rayc->tex_ptr[4] || !rayc->tex_ptr[3] || !rayc->tex_ptr[2]
	|| !rayc->tex_ptr[1] || !rayc->tex_ptr[0])
	{
		rayc->error = ERR_TEXT;
		ft_quit(rayc);
	}
	ft_data_texture(rayc);
	return (0);
}

int		ft_first_img_bmp(t_raycast *rayc)
{
	rayc->rayc_ptr = mlx_new_image(rayc->mlx_ptr,
	rayc->resol_x, rayc->resol_y);
	rayc->pixel_address = mlx_get_data_addr(rayc->rayc_ptr,
	&rayc->bits_per_pixel,
	&rayc->size_line, &rayc->endian);
	put_sky_floor(rayc);
	ft_wallcasting(rayc);
	sprite_cast(rayc);
	return (0);
}

t_bmp	ft_init_s_bmp(t_raycast *rayc)
{
	t_bmp	bmp;

	bmp.file_type[0] = 'B';
	bmp.file_type[1] = 'M';
	bmp.file_type[2] = '\0';
	bmp.set_zero = 0;
	bmp.data_offset = 54;
	bmp.header_size = 40;
	bmp.img_width = rayc->resol_x;
	bmp.img_height = rayc->resol_y;
	bmp.planes = 1;
	bmp.bpp = 32;
	bmp.size_file = 2;
	bmp.data_ptr = (int*)rayc->pixel_address;
	bmp.trash = 0;
	return (bmp);
}

void	ft_write_bmp(t_raycast *rayc, int fd)
{
	int		x;
	int		y;
	t_bmp	bmp;

	bmp = ft_init_s_bmp(rayc);
	write(fd, &bmp.file_type, 2);
	write(fd, &bmp.size_file, 4);
	write(fd, &bmp.set_zero, 4);
	write(fd, &bmp.data_offset, 4);
	write(fd, &bmp.header_size, 4);
	write(fd, &bmp.img_width, 4);
	write(fd, &bmp.img_height, 4);
	write(fd, &bmp.planes, 2);
	write(fd, &bmp.bpp, 2);
	write(fd, &bmp.trash, 8);
	write(fd, &bmp.trash, 8);
	write(fd, &bmp.trash, 8);
	y = bmp.img_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < bmp.img_width)
			write(fd, &bmp.data_ptr[y * bmp.img_width + x++], 4);
		y--;
	}
}

int		ft_bmp(t_raycast *rayc, char **av)
{
	int fd;

	if (ft_strcmp(av[2], "--save") != 0)
	{
		rayc->error = ERR_WRONG_ARG;
		ft_quit(rayc);
	}
	ft_init_param(rayc);
	ft_init_map(rayc);
	if (ft_set(av[1], rayc, rayc->struct_map) == FAILURE)
		ft_quit(rayc);
	ft_init_rayc(rayc);
	if (ft_init_mlx_bmp(rayc) == -1)
		ft_quit(rayc);
	ft_first_img_bmp(rayc);
	fd = open("Wolf3d.bmp", O_RDWR | O_CREAT, S_IRWXU);
	ft_write_bmp(rayc, fd);
	close(fd);
	exit(0);
	return (0);
}
