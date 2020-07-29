/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:23:48 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/29 12:16:26 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

void		print_error2(t_raycast *rayc)
{
	if (rayc->error == ERR_NB_FC)
		ft_putstr("ERREUR : Identifiant F ou C en trop\n");
	if (rayc->error == ERR_FC)
		ft_putstr(ERR_FC_MSG);
	if (rayc->error == ERR_SYNT)
		ft_putstr("ERREUR : Syntaxe non reconnue dans le fichier\n");
	if (rayc->error == ERR_NO_MAP)
		ft_putstr("ERREUR : Map non trouvée et/ou identifiants en trop\n");
	if (rayc->error == ERR_DIGIT_MAP)
		ft_putstr("ERREUR : Map incorrecte\n");
	if (rayc->error == ERR_MAP_NOT_CLOSE)
		ft_putstr(ERR_MAP_NOT_CLOSE_MSG);
	if (rayc->error == ERR_NB_PLAYER)
		ft_putstr("ERREUR : Trop de joueurs trouvés\n");
	if (rayc->error == ERR_PLAYER)
		ft_putstr("ERREUR : Aucun joueur trouvé\n");
	if (rayc->error == ERR_FILE)
		ft_putstr("ERREUR : Fichier de configuration non trouvé ou vide\n");
}

void		print_error(t_raycast *rayc)
{
	if (rayc->error == ERR_NB_ARG)
		ft_putstr("ERREUR : Nombre d'argument incorrect\n");
	if (rayc->error == ERR_WRONG_ARG)
		ft_putstr(ERR_WRONG_ARG_MSG);
	if (rayc->error == ERR_NB_ID)
		ft_putstr("ERREUR : Identifiant(s) manquant(s)\n");
	if (rayc->error == ERR_WR_ID)
		ft_putstr("ERREUR : Identifiant non reconnu\n");
	if (rayc->error == ERR_RESOL)
		ft_putstr(ERR_RESOL_MSG);
	if (rayc->error == ERR_TEXT_PATH)
		ft_putstr("ERREUR : chemin de texture incorrect\n");
	if (rayc->error == ERR_NB_TEXT)
		ft_putstr("ERREUR : texture en trop\n");
	if (rayc->error == ERR_TEXT)
		ft_putstr("ERREUR : Une (ou plusieurs) texture n'a pas été trouvée\n");
	print_error2(rayc);
}

int			ft_quit(t_raycast *rayc)
{
	free(rayc->no);
	free(rayc->so);
	free(rayc->we);
	free(rayc->ea);
	free(rayc->sprite);
	if (rayc->rayc_ptr)
		mlx_destroy_image(rayc->mlx_ptr, rayc->rayc_ptr);
	if (rayc->mlx_win)
		mlx_destroy_window(rayc->mlx_ptr, rayc->mlx_win);
	print_error(rayc);
	exit(0);
}