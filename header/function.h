/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:16:07 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/15 15:08:44 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
#define FUNCTION_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include<mlx.h>
#include<string.h>
#include "structure.h"

// init mlx & raycast
int		ft_init_mlx(t_raycast *rayc);
int		ft_first_img(t_raycast *rayc);
void	ft_init_rayc(t_raycast *rayc);
int		ft_init_param(t_raycast *rayc);
void		ft_init_map(t_raycast *rayc);


// dealkey
int	ft_key_hit(int key, t_raycast *rayc);
int	ft_key_release(int key, t_raycast *rayc);
int	dealkey(t_raycast *rayc);

// spritecasting
void	ft_sortsprite(int	*spriteorder, int	*spritedistance, t_raycast *rayc);
int		ft_swap(int *spritedistance, t_raycast *rayc, int i);
void	sprite_cast(t_raycast *rayc);

// wallcasting
void	ft_get_raydir(t_raycast *rayc);
void	ft_get_step_sidedist(t_raycast *rayc);
void	ft_dda(t_raycast *rayc);
void	ft_get_perpwalldist(t_raycast *rayc);
void	ft_choose_texture(t_raycast *rayc);
void	ft_wallcasting(t_raycast *rayc);

// drawing function
int	put_sky_floor(t_raycast *rayc);
void	put_pixel_to_rayc(int *addr, int x, int y, int color, int size);

// quit
int			ft_quit(t_raycast *rayc);

// Extraction des infos
int		ft_id_r(char **map_str, t_raycast *param);
int		ft_id_no(char **map_str, t_raycast *param);
int		ft_id_so(char **map_str, t_raycast *param);
int		ft_id_we(char **map_str, t_raycast *param);
int		ft_id_ea(char **map_str, t_raycast *param);
int		ft_id_s(char **map_str, t_raycast *param);
int		ft_id_f(char **map_str, t_raycast *param);
int		ft_id_c(char **map_str, t_raycast *param);

// affecter les éléments du fichier donné
int				ft_set(char *cubfile, t_raycast *param, int struct_map[MAPHEIGHT][MAPWIDTH]);

// mettre le contenu de la map dans une string
char			*ft_read_map(char *map_file);

// parsing des identifiants
int				ft_id_parsing(char **map, t_raycast *param);
int				ft_getinfo(char **map_str, t_raycast *param);
int				get_id(char **map, t_raycast *rayc);
int				affect_id(int id, char **map_str, t_raycast *param);
t_fct_take_id	*fct_tk_id_init(t_fct_take_id *fct_tk_id);
int				ft_is_complete(t_raycast *param);

// parsing de map
int				ft_map_parsing(char **map_str, int struct_map[MAPHEIGHT][MAPWIDTH], t_raycast *rayc);
int				ft_get_map(char **map_str, int struct_map[MAPHEIGHT][MAPWIDTH], t_raycast *rayc);
int				verif_digit(t_raycast *rayc);

// gestion du bmp
int		ft_bmp(t_raycast *rayc, char **av);

// utils.c
int				ft_strstr(char **str, char *to_find);
int				ft_atoi(char *str);
int				is_good_path_char(char c);
void			ft_strcpy(char *dst, char *src);
int				ft_strlen(char *s, char c);
char			*ft_strjoin_char(char *str, char c);
char			*ft_strjoin(char *s1, char *s2);
int				is_digit(char c);
void			ft_putstr(char *s);
void			ft_putnbr(int nb);

#endif