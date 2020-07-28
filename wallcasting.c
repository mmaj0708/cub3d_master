/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:13:39 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/21 22:23:47 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

void	ft_get_raydir(t_raycast *rayc)
{
		rayc->camerax = 2 * rayc->x / (double)rayc->w - 1;

		rayc->raydirx = rayc->dirx + rayc->planex * rayc->camerax;
		rayc->raydiry = rayc->diry + rayc->planey * rayc->camerax;

		// position du carré où est le rayon
		rayc->mapx = rayc->posx;
		rayc->mapy = rayc->posy;

		// longueur d'un côté x ou y jusqu'au côté x ou y suivant
		rayc->deltadistx = fabs(1 / rayc->raydirx); // utiliser libmath pour valeur absolue
		rayc->deltadisty = fabs(1 / rayc->raydiry);

		rayc->hit = 0; // mur touché, 0 = x-side ; 1 = y-sides
}

void	ft_get_step_sidedist(t_raycast *rayc)
{
		if (rayc->raydirx < 0)
		{
			rayc->stepx = -1;
			rayc->sidedistx = (rayc->posx - rayc->mapx) * rayc->deltadistx;
		}
		else
		{
			rayc->stepx = 1;
			rayc->sidedistx = (rayc->mapx + 1.0 - rayc->posx) * rayc->deltadistx;
		}
		if (rayc->raydiry < 0)
		{
			rayc->stepy = -1;
			rayc->sidedisty = (rayc->posy - rayc->mapy) * rayc->deltadisty; // pk soustraction inversée ?
		}
		else
		{
			rayc->stepy = 1;
			rayc->sidedisty = (rayc->mapy + 1.0 - rayc->posy) * rayc->deltadisty; // pk + 1 ?
		}
}

void	ft_dda(t_raycast *rayc)
{
	while (rayc->hit == 0) // la boucle ne s'arrête jamais si on touche x-side ?
	{
		if (rayc->sidedistx < rayc->sidedisty) // donc quand inf. forcément un x-side
		{
			rayc->sidedistx += rayc->deltadistx; // sidex = sidex + deltax
			rayc->mapx += rayc->stepx;
			rayc->side = 0; // touché NS
		}
		else
		{
			rayc->sidedisty += rayc->deltadisty;
			rayc->mapy += rayc->stepy;
			rayc->side = 1;
		}
		if (rayc->struct_map[rayc->mapx][rayc->mapy] == 1)
			rayc->hit = 1;
	}
}

void	ft_get_perpwalldist(t_raycast *rayc)
{
	if (rayc->side == 0) // NS
			rayc->perpwalldist = (rayc->mapx - rayc->posx + (1 - rayc->stepx) / 2) / rayc->raydirx;
	else
		rayc->perpwalldist = (rayc->mapy - rayc->posy + (1 - rayc->stepy) / 2) / rayc->raydiry;
	
			// hauteur de la ligne à tracer
	rayc->lineheight = (int)(rayc->resol_y / rayc->perpwalldist);
	
			// calcul du premier et dernier pixel de la colone à remplir
	rayc->drawstart = -rayc->lineheight / 2 + rayc->resol_y / 2;
	if (rayc->drawstart < 0)
		rayc->drawstart = 0;
	rayc->drawend = rayc->lineheight / 2 + rayc->resol_y / 2;
	if (rayc->drawend >= rayc->resol_y)
		rayc->drawend = rayc->resol_y;
}

void	ft_choose_texture(t_raycast *rayc)
{
	if (rayc->side == 0 && rayc->raydirx < 0) // EST
		rayc->texnum = 3;
	if (rayc->side == 0 && rayc->raydirx > 0) // OUEST
		rayc->texnum = 2;
	if (rayc->side == 1 && rayc->raydiry < 0) // NORD
		rayc->texnum = 0;
	if (rayc->side == 1 && rayc->raydiry > 0) // S
		rayc->texnum = 1;
}

void	ft_calculate_texture(t_raycast *rayc)
{
	int		*img_addr;

	img_addr = (int *)rayc->pixel_address;
	if (rayc->side == 0)
		rayc->wallx = rayc->posy + rayc->perpwalldist * rayc->raydiry;
	else
		rayc->wallx = rayc->posx + rayc->perpwalldist * rayc->raydirx;
	rayc->wallx -= floor((rayc->wallx)); // floor arrondi le float à l'eniter le plus proche
	
		// texx = the x coordinate of the text.
	rayc->texx = (int)(rayc->wallx * (double)rayc->tex_width[rayc->texnum]);

		rayc->y = rayc->drawstart;
	while (rayc->y < rayc->drawend) // je crois que tu dois faire le buffer poto
	{
		rayc->d = rayc->y * 256 - rayc->resol_y * 128 + rayc->lineheight * 128;
		rayc->texy = ((rayc->d * rayc->tex_height[rayc->texnum]) / rayc->lineheight) / 256;
		rayc->pix_color = rayc->tex_pix_addr[rayc->texnum][rayc->texx + rayc->texy * rayc->tex_sl[rayc->texnum] / 4];
		put_pixel_to_rayc(img_addr, rayc->x, rayc->y, rayc->pix_color, rayc->size_line);
		rayc->y++;
	}
}

void	ft_wallcasting(t_raycast *rayc)
{

	rayc->x = 0;
	while (rayc->x < rayc->w)
	{
		// printf("check pos : %f, %f\n", rayc->posx, rayc->posy);
		ft_get_raydir(rayc);
		// calcul de step et sidedist
		ft_get_step_sidedist(rayc);
		// application DDA
		ft_dda(rayc);
		// calcul de perwalldist
		ft_get_perpwalldist(rayc);

		// calcul de texture
		ft_choose_texture(rayc);
		// where the wall was hit avec wallx
		ft_calculate_texture(rayc);
		
		// printf("rayc->x : %d\n", rayc->x);

		rayc->zbuffer[rayc->x] = rayc->perpwalldist;
		rayc->x++; // à mettre à la fin je pense
	}
}
