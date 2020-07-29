/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:04:51 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/29 13:39:29 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "definition.h"

typedef struct	s_raycast
{
	// parameters
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
	// erreur
	int		error;
	// position
	double	posx;
	double	posy;
	// vecteur direction
	double	dirx;
	double	diry;
	// direction perpendiculaire
	double	perpdirx;
	double	perpdiry;
	// vecteur plan camera
	double	planex;
	double	planey;
	// variables de temps
	double	time;
	double	oldtime;
	// variables de raycasting
	int		w;
	int		x;
	int		y; // pour la texture ensuite
	double	raydirx;
	double	raydiry;
	double	camerax;
	// position du carré
	int		mapx;
	int		mapy;
	// dist. position -> première arête
	double	sidedistx;
	double	sidedisty;
	// dist. arête -> arête suivante
	double	deltadistx;
	double	deltadisty;
	// longueur rayon
	double perpwalldist;
	// pas
	int		stepx;
	int		stepy;
	// variables mur touché
	int		hit;
	int		side;
	// variables de la colonne à remplir
	int		lineheight;
	int		drawstart;
	int		drawend;
	// variables temps et vitesse
	double	frametime;
	double	movespeed;
	double	rotspeed;
	double	olddirx;
	double	oldplanex;
	// variables rayc
	void	*rayc_ptr;
	void 	*mlx_ptr;
	void 	*mlx_win;
	char	*pixel_address;
	int		bits_per_pixel;
	int		size_line;
	int 	endian;
	int		width;
	int		height;
	// Press and release
	int		keyboard[65365];
	// Texture
	void	*tex_ptr[5];
	int		tex_width[5];
	int		tex_height[5];
	int		*tex_pix_addr[5]; // faire un tableau pour toutes les text.
	int		tex_bpp[5];
	int		tex_sl[5];
	int 	tex_endian[5];
	int		texnum;
	double		wallx;
	int		texx;
	int		texy;
	int		d;
	int		pix_color;
	// sprite
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