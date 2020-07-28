/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:03:01 by user42            #+#    #+#             */
/*   Updated: 2020/07/22 17:48:06 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

void		print_error(t_raycast *rayc)
{
	if (rayc->error == ERR_NB_ARG)
		ft_putstr("ERREUR : Trop d'arguments\n");
	if (rayc->error == ERR_WRONG_ARG)
		ft_putstr("ERREUR : Le premier argument doit terminer par .cub et le second (facultatif) doit être --save\n");
	if (rayc->error == ERR_NB_ID)
		ft_putstr("ERREUR : Identifiant(s) manquant(s)\n");
	if (rayc->error == ERR_WR_ID)
		ft_putstr("ERREUR : Identifiant non reconnu\n");
	if (rayc->error == ERR_RESOL)
		ft_putstr("ERREUR : Résolution incorrect, le format demandé est : \"R [x] [y]\" avec x && y > 0\n");
	if (rayc->error == ERR_TEXT_PATH)
		ft_putstr("ERREUR : chemin de texture incorrect\n");
	if (rayc->error == ERR_NB_TEXT)
		ft_putstr("ERREUR : texture en trop\n");
	if (rayc->error == ERR_TEXT)
		ft_putstr("ERREUR : Une (ou plusieurs) texture n'a pas été trouvée\n");
	if (rayc->error == ERR_NB_FC)
		ft_putstr("ERREUR : Identifiant F ou C en trop\n");
	if (rayc->error == ERR_FC)
		ft_putstr("ERREUR : les valeurs RGB de F et C doivent être comprises entre 0 et 255 dans le format : F [R],[G],[B]\n");	
	if (rayc->error == ERR_SYNT)
		ft_putstr("ERREUR : Syntaxe non reconnue dans le fichier\n");
	if (rayc->error == ERR_NO_MAP)
		ft_putstr("ERREUR : Map non trouvée et/ou identifiants en trop\n");
	if (rayc->error == ERR_DIGIT_MAP)
		ft_putstr("ERREUR : Caractère(s) incorrect(s) dans la map\n");
	if (rayc->error == ERR_MAP_NOT_CLOSE)
		ft_putstr("ERREUR : Map non fermée par des '1' ou contient des espaces\n");
	if (rayc->error == ERR_NB_PLAYER)
		ft_putstr("ERREUR : Trop de joueurs trouvés\n");
	if (rayc->error == ERR_PLAYER)
		ft_putstr("ERREUR : Aucun joueur trouvé\n");
	if (rayc->error == ERR_FILE)
		ft_putstr("ERREUR : Fichier de configuration non trouvé ou vide\n");
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
	if(rayc->mlx_win)
		mlx_destroy_window(rayc->mlx_ptr, rayc->mlx_win);
	print_error(rayc);
	exit(0);
}

void		ft_init_map(t_raycast *rayc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < MAPHEIGHT)
	{
		while (i < MAPWIDTH)
		{
			// printf("check init map\n");
			rayc->struct_map[j][i] = -1;
			i++;	
		}
		j++;
		i = 0;
	}
}

int			ft_init_param(t_raycast *rayc)
{
	rayc->no = NULL;
	rayc->so = NULL;
	rayc->we = NULL;
	rayc->ea = NULL;
	rayc->sprite = NULL;
	rayc->rc = -1;
	rayc->gc = -1;
	rayc->bc = -1;
	rayc->rf = -1;
	rayc->gf = -1;
	rayc->bf = -1;
	rayc->resol_x = -1;
	rayc->resol_y = -1;
	rayc->posx = -1;
	rayc->posy = -1;
	rayc->error = -1;
	return (0);
}

int			ft_check_arg(char **av)
{
	int		i;

	i = 0;
	while (av[1][i] != '\0')
		i++;
	if (av[1][i - 1] && av[1][i - 2] && av[1][i - 3] && av[1][i - 4]
	&& av[1][i - 1] == 'b' && av[1][i - 2] == 'u' && av[1][i - 3] == 'c' && av[1][i - 4])
	return (TRUE);
	else
		return (FALSE);
}

int			main(int ac, char **av)
{
	t_raycast	rayc;

	ft_init_param(&rayc);
	ft_init_map(&rayc);

	if (ac > 3)
	{
		rayc.error = ERR_NB_ARG;
		ft_quit(&rayc);
	}
	if (ac == 3)
		ft_bmp(&rayc, av);

	if (ft_check_arg(av) == FALSE)
	{
		rayc.error = ERR_WRONG_ARG;
		ft_quit(&rayc);
	}
	if (ft_set(av[1], &rayc, rayc.struct_map) == FAILURE)
		ft_quit(&rayc);

	ft_init_rayc(&rayc);
	ft_init_mlx(&rayc);

	ft_first_img(&rayc);
	mlx_hook(rayc.mlx_win, KeyPress, KeyPressMask, &ft_key_hit, &rayc);
	mlx_hook(rayc.mlx_win, KeyRelease, KeyReleaseMask, &ft_key_release, &rayc);
	mlx_hook(rayc.mlx_win, DESTROY_NOTIFY, STRUCT_NOTIFY_MASK, &ft_quit, &rayc);
	mlx_loop_hook(rayc.mlx_ptr, &dealkey, &rayc);
	mlx_loop(rayc.mlx_ptr);
}
	// 	int i = 0;
	// int j = 0;
	// while (j < rayc.endmap)
	// {
	// 	while (rayc.struct_map[j][i] != -1)
	// 	{
	// 		printf("%d", rayc.struct_map[j][i]);
	// 		i++;
	// 	}
	// 	printf("\n");
	// 	j++;
	// 	i = 0;
	// }
	// printf("no : %s\n", rayc.no);
	// printf("so : %s\n", rayc.so);
	// printf("we : %s\n", rayc.we);
	// printf("ea : %s\n", rayc.ea);
	// printf("sprite : %s\n", rayc.sprite);
	// printf("floor : %d %d %d\n", rayc.rf, rayc.gf, rayc.bf);
	// printf("ceiling : %d %d %d\n", rayc.rc, rayc.gc, rayc.bc);
	// printf("resol : %d %d\n", rayc.resol_x, rayc.resol_y);

// // afficher struct_map
// 	int i = 0;
// 	int j = 0;
// 	printf("posx : %f\nposy : %f\n", rayc.posx, rayc.posy);
// 	printf("dirx : %f\ndiry : %f\n", rayc.dirx, rayc.diry);
// 	while (i < rayc.numsprite)
// 	{
// 		printf("sprite_x : %f\nsprite_y : %f\n", rayc.sprite_x[i], rayc.sprite_y[i]);
// 		i++;
// 	}