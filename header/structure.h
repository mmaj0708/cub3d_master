/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:04:51 by mmaj              #+#    #+#             */
/*   Updated: 2020/08/02 21:52:19 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "definition.h"

typedef struct	s_raycast
{
	int		struct_map[MPH][MPW];
	int		endmap;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;
	int		resol_x;
	int		resol_y;
	int		rf;
	int		gf;
	int		bf;
	int		rc;
	int		gc;
	int		bc;
	int		screenw;
	int		screenh;
	int		error;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	perpdirx;
	double	perpdiry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	int		w;
	int		x;
	int		y;
	double	raydirx;
	double	raydiry;
	double	camerax;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	frametime;
	double	movespeed;
	double	rotspeed;
	double	olddirx;
	double	oldplanex;
	void	*rayc_ptr;
	void	*mlx_ptr;
	void	*mlx_win;
	char	*pixel_address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		keyboard[65365];
	void	*tex_ptr[5];
	int		tex_width[5];
	int		tex_height[5];
	int		*tex_pix_addr[5];
	int		tex_bpp[5];
	int		tex_sl[5];
	int		tex_endian[5];
	int		texnum;
	double	wallx;
	int		texx;
	int		texy;
	int		d;
	int		pix_color;
	double	zbuffer[2500];
	double	spritedistance;
	double	sprite_x[100];
	double	sprite_y[100];
	int		numsprite;
	double	sprite_c_x;
	double	sprite_c_y;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spritewidth;
	int		spriteheight;
	int		drawstartx;
	int		drawstarty;
	int		drawendx;
	int		drawendy;
	int		stripe;
}				t_raycast;

typedef struct	s_fct_take_id
{
	int		(*ptrfct)(char **map_str, t_raycast *param);
	int		id;
}				t_fct_take_id;

typedef	struct	s_bmp
{
	char		file_type[3];
	int			size_file;
	int			set_zero;
	int			data_offset;
	int			header_size;
	int			img_width;
	int			img_height;
	short	int	planes;
	short	int	bpp;
	int			*data_ptr;
	double		trash;
}				t_bmp;
#endif
