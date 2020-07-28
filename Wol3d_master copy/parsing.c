/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 16:50:26 by mmaj              #+#    #+#             */
/*   Updated: 2020/05/09 16:50:26 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

int		ft_id_parsing(char **map, t_raycast *rayc)
{
	int			ret;

	ret = TRUE;
	while (ret == TRUE)
	{
		ret = ft_getinfo(map, rayc);
		// printf("check current map char : %c\n", *map[0]);
	}
	// printf("check current map char after mvnl: %c\n", *map_str[0]);

	return (ret);
}

void	ft_get_pos_no_so(t_raycast *rayc, int digit)
{

}

void	ft_get_we_ea(t_raycast *rayc, int digit)
{

}

int		ft_get_sprite_pos(t_raycast *rayc)
{
	int i;
	int j;
	int sprite_i;
	
	j = 0;
	i = 0;
	sprite_i = 0;
	while (j < rayc->endmap)
	{
		while (rayc->struct_map[j][i] != -1)
		{
			// on ajoute -48 parce que la carte a été parsée de cette manière
				// printf("check [j][i] : %d\n", rayc->struct_map[j][i]);
			if ((rayc->struct_map[j][i] == 'N' - 48 || rayc->struct_map[j][i] == 'S' - 48
			|| rayc->struct_map[j][i] == 'W' - 48 || rayc->struct_map[j][i] == 'E' - 48)
			&& rayc->posx != -1)
			{
				rayc->error = ERR_NB_PLAYER;
				return (FAILURE);
			}
			if ((rayc->struct_map[j][i] == 'N' - 48 || rayc->struct_map[j][i] == 'S' - 48
			|| rayc->struct_map[j][i] == 'W' - 48 || rayc->struct_map[j][i] == 'E' - 48)
			&& rayc->posx == -1)
			{
				rayc->posx = j + 0.5;
				rayc->posy = i + 0.5;
				if (rayc->struct_map[j][i] == 'N' - 48)
				{
					rayc->dirx = -0.99;
					rayc->diry = 0;
					rayc->planex = 0;
					rayc->planey = 0.66;
				}
				if (rayc->struct_map[j][i] == 'S' - 48)
				{
					// printf("check\n");
					rayc->dirx = 0.99;
					rayc->diry = 0;
					rayc->planex = 0;
					rayc->planey = -0.66;
				}
				if (rayc->struct_map[j][i] == 'W' - 48)
				{
					rayc->dirx = 0;
					rayc->diry = -0.99; // -1
					rayc->planex = -0.66; // -0.66 sinon bug de spawn
					rayc->planey = 0;
				}
				if (rayc->struct_map[j][i] == 'E' - 48)
				{
					rayc->dirx = 0;
					rayc->diry = 0.99; // ds le tuto 1
					rayc->planex = 0.66; // ds le tuto 0.66
					rayc->planey = 0;
				}
			}
			if (rayc->struct_map[j][i] == 2)
			{
				rayc->sprite_x[sprite_i] = j;
				rayc->sprite_y[sprite_i] = i;
				sprite_i++;
			}
			i++;
		}
		j++;
		i = 0;
	}
	rayc->numsprite = sprite_i;

	return (0);
}

int		ft_check_map(t_raycast *rayc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < rayc->endmap)
	{
		while (rayc->struct_map[j][i] != -1)
		{
			if (rayc->struct_map[j][i] != 1 &&
			rayc->struct_map[j][i] != 0 &&
			rayc->struct_map[j][i] != 2 &&
			rayc->struct_map[j][i] != 'N' - 48 &&
			rayc->struct_map[j][i] != 'S' - 48 &&
			rayc->struct_map[j][i] != 'W' - 48 &&
			rayc->struct_map[j][i] != 'E' - 48 &&
			rayc->struct_map[j][i] != ' ' - 48)
			{
				rayc->error = ERR_DIGIT_MAP;
				return (FAILURE);
			}
			i++;
		}
		j++;
		i = 0;
	}
	return (SUCCESS);
}

int		ft_map_parsing(char **map_str, int struct_map[400][400], t_raycast *rayc)
{
	if (ft_get_map(map_str, struct_map, rayc) == FAILURE)
		return (FAILURE);


	if (ft_check_map(rayc) == FAILURE)
		return (FAILURE);

	// printf("check map : %d\n", ret);
	if (verif_digit(rayc) == FAILURE)
	{
		rayc->error = ERR_MAP_NOT_CLOSE;
		return (FAILURE);
	}
	if (ft_get_sprite_pos(rayc) == FAILURE)
		return (FAILURE);
	if (rayc->posx == -1)
	{
		rayc->error = ERR_PLAYER;
		return (FAILURE);
	}
	return (SUCCESS);
}

int		ft_begin_line(char **map)
{
	while (*map[0] != '\n')
		map[0]--;
	map[0]++;
	return (0);
}

int		ft_set(char *cubfile, t_raycast *rayc, int struct_map[400][400])
{
	// printf("check set\n");
	char	**map;
	char	*free_save;
	int		ret;

	map = malloc(sizeof(map) * 1);
	if ((*map = ft_read_map(cubfile)) == NULL)
	{
	printf("check empy file\n");
		rayc->error = ERR_FILE;
		free(map);
		ft_quit(rayc);
	}
	free_save = *map; // garder l'adresse pour la free à la fin
	
	ret = ft_id_parsing(map, rayc);
	if (ret == FAILURE)
	{
		free(free_save);
		free(map);
		map = NULL;
		return (FAILURE);
	}
	ft_begin_line(map);
		// printf("check current map char : %c\n", *map[0]);
	if((ret = ft_map_parsing(map, struct_map, rayc)) == FAILURE) // GERER ESP + SPRITE
	{
	printf("check\n");
		free(free_save);
		free(map);
		map = NULL;
		return (FAILURE);
	}
	// printf("check ret set\n");
	
	// *map = *map - length_file;
	free(free_save);
	free(map);
	map = NULL;

	return (SUCCESS);
}

	// printf("no : %s\n", rayc->no);
	// printf("so : %s\n", rayc->so);
	// printf("we : %s\n", rayc->we);
	// printf("ea : %s\n", rayc->ea);
	// printf("sprite : %s\n", rayc->sprite);
	// printf("floor : %d %d %d\n", rayc->rf, rayc->gf, rayc->bf);
	// printf("ceiling : %d %d %d\n", rayc->rc, rayc->gc, rayc->bc);
	// printf("resol : %d %d\n", rayc->resol_x, rayc->resol_y);
	// printf("ret = %d\n", ret);