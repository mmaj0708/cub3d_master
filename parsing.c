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
		ret = ft_getinfo(map, rayc);
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

void	ft_set_free(t_raycast *rayc, char **map)
{
		rayc->error = ERR_FILE;
		free(map);
		map = NULL;
		ft_quit(rayc);
}

int		ft_set(char *cubfile, t_raycast *rayc, int struct_map[400][400])
{
	char	**map;
	char	*free_save;

	map = malloc(sizeof(map) * 1);
	if ((*map = ft_read_map(cubfile)) == NULL)
		ft_set_free(rayc, map);
	free_save = *map;
	if (ft_id_parsing(map, rayc) == FAILURE)
	{
		free(free_save);
		free(map);
		return (FAILURE);
	}
	ft_begin_line(map);
	if (ft_map_parsing(map, struct_map, rayc) == FAILURE)
	{
		free(free_save);
		free(map);
		map = NULL;
		return (FAILURE);
	}
	free(free_save);
	free(map);
	map = NULL;
	return (SUCCESS);
}
