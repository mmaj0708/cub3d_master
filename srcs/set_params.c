/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 16:53:35 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 16:53:46 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

int		ft_check_map(t_raycast *rayc)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (j < rayc->endmap)
	{
		while (rayc->struct_map[j][++i] != -1)
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
		j++;
		i = -1;
	}
	return (SUCCESS);
}

int		ft_map_parsing(char **mp, int struct_map[MPH][MPW], t_raycast *rayc)
{
	if (ft_get_map(mp, struct_map, rayc) == FAILURE)
		return (FAILURE);
	if (ft_check_map(rayc) == FAILURE)
		return (FAILURE);
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

int		ft_set(char *cubfile, t_raycast *rayc, int struct_map[MPH][MPW])
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
