/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:10:33 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/28 18:37:50 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITION_H
#define DEFINITION_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// return fct
#define FALSE 0
#define SUCCESS 0
#define	TRUE	1
#define FAILURE	-1
// KEY EVENT AND MASK
#define ARROW_LEFT 65361
#define ARROW_RIGHT 65363
#define ARROW_DOWN 65364
#define ARROW_UP 65362
#define KEY_Z 122 // VM
#define KEY_S 115 // VM
#define KEY_Q 113 // VM
#define KEY_D 100 // VM

#define ARROW_LEFT_MAC 123 // MAC
#define ARROW_RIGHT_MAC 124 // MAC
#define KEY_W_MAC 13 // MAC
#define KEY_S_MAC 1 // MAC
#define KEY_A_MAC 0 // MAC
#define KEY_D_MAC 2 // MAC
#define KeyPressMask 1L<<0
#define KeyReleaseMask 1L<<1
#define KeyPress 2
#define KeyRelease 3
#define STRUCT_NOTIFY_MASK 1L<<17
#define DESTROY_NOTIFY 17
#define ECHAP 65307 // VM
#define ECHAP_MAC 53 // MAC
// map width and map height
#define MAPWIDTH 400
#define MAPHEIGHT 400
#define WALL_HEIGHT_PROTECTION 200000
// COLOR AND WIDTH (inutile)
#define WHITE 16777215
#define BLUE 255
#define GREEN 65280
#define RED 16711680
#define COLOR1 4268132
#define COLOR2 13132850
#define WIDTH 1000
#define HEIGHT 800
// ERREUR
#define	ERR_SYNT 0
#define	ERR_RESOL 1
#define ERR_RESOL_MSG "ERREUR : Résolution incorrect, le format demandé est : \"R [x] [y]\" avec x && y > 0\n"
#define	ERR_TEXT 2
#define	ERR_RGB 3
#define	ERR_MAP 4
#define	ERR_WRONG_ARG 5
#define ERR_WRONG_ARG_MSG "ERREUR : Le premier argument doit terminer par .cub et le second (facultatif) doit être --save\n"
#define	ERR_NB_ARG 6
#define	ERR_PLAYER 7
#define	ERR_NB_PLAYER 8
#define	ERR_FILE 9
#define	ERR_NB_ID 10
#define	ERR_WR_ID 11
#define	ERR_TEXT_PATH 12
#define	ERR_NB_TEXT 13
#define	ERR_NB_FC 14
#define	ERR_FC 15
#define ERR_FC_MSG "ERREUR : les valeurs RGB de F et C doivent être comprises entre 0 et 255 dans le format : F [R],[G],[B]\n"
#define	ERR_NO_MAP 16
#define	ERR_DIGIT_MAP 17
#define	ERR_MAP_NOT_CLOSE 18
#define ERR_MAP_NOT_CLOSE_MSG "ERREUR : Map non fermée par des '1' ou contient des espaces\n"

#endif