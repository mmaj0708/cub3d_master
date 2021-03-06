/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:10:33 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 14:43:55 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITION_H
# define DEFINITION_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
/*
** return fct
*/
# define FALSE 0
# define SUCCESS 0
# define TRUE	1
# define FAILURE	-1
/*
** KEY EVENT AND MASK
*/
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define KEY_Z 122
# define KEY_S 115
# define KEY_Q 113
# define KEY_D 100
# define KEY_A 97
# define KEY_W 119
# define ARROW_LEFT_MAC 123
# define ARROW_RIGHT_MAC 124
# define KEY_W_MAC 13
# define KEY_S_MAC 1
# define KEY_A_MAC 0
# define KEY_D_MAC 2
# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROY_NOTIFY 17
# define ECHAP 65307
# define ECHAP_MAC 53
/*
** map width and map height
*/
# define MPW 1000
# define MPH 1000
# define WALL_HEIGHT_PROTECTION 200000
/*
** COLOR AND WIDTH (inutile)
*/
# define WHITE 16777215
# define BLUE 255
# define GREEN 65280
# define RED 16711680
# define COLOR1 4268132
# define COLOR2 13132850
# define WIDTH 1000
# define HEIGHT 800
/*
** ERREUR
*/
# define ERR_SYNT 0
# define ERR_RESOL 1
# define ERR_TEXT 2
# define ERR_RGB 3
# define ERR_MAP 4
# define ERR_WRONG_ARG 5
# define ERR_NB_ARG 6
# define ERR_PLAYER 7
# define ERR_NB_PLAYER 8
# define ERR_FILE 9
# define ERR_NB_ID 10
# define ERR_WR_ID 11
# define ERR_TEXT_PATH 12
# define ERR_NB_TEXT 13
# define ERR_NB_FC 14
# define ERR_FC 15
# define ERR_NO_MAP 16
# define ERR_DIGIT_MAP 17
# define ERR_MAP_NOT_CLOSE 18

#endif
