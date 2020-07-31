/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:49:20 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/31 17:53:56 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

int		ft_is_complete(t_raycast *rayc)
{
	if (rayc->sprite != NULL && rayc->no != NULL && rayc->so != NULL
	&& rayc->we != NULL
	&& rayc->ea != NULL && rayc->rc != -1 && rayc->gc != -1 && rayc->bc != -1
	&& rayc->rf != -1 && rayc->gf != -1 && rayc->bf != -1 && rayc->resol_x != -1
	&& rayc->resol_y != -1)
		return (TRUE);
	else
		return (FALSE);
}

int		ft_move_nl(char **map_str)
{
	while (*map_str[0] != '\0' && (*map_str[0] == ' ' || *map_str[0] == 13))
		map_str[0]++;
	if (*map_str[0] == '\0' || *map_str[0] == '\n')
	{
		map_str[0]++;
		if (*map_str[0] != '\0')
			return (SUCCESS);
	}
	return (FAILURE);
}

int		ft_end_id(char **map_str, t_raycast *rayc)
{
	if (*map_str[0] == '1' && ft_is_complete(rayc) == FALSE)
	{
		rayc->error = ERR_NB_ID;
		return (FAILURE);
	}
	if (*map_str[0] != '1' && ft_is_complete(rayc) == TRUE)
	{
		rayc->error = ERR_NO_MAP;
		return (FAILURE);
	}
	if (*map_str[0] == '1' && ft_is_complete(rayc) == TRUE)
		return (SUCCESS);
	return (1);
}

int		ft_getinfo(char **map_str, t_raycast *rayc)
{
	int		id;

	while (*map_str[0] == ' ' || *map_str[0] == '\n' || *map_str[0] == 13)
		map_str[0]++;
	if (ft_end_id(map_str, rayc) == SUCCESS)
		return (SUCCESS);
	if (ft_end_id(map_str, rayc) == FAILURE)
		return (FAILURE);
	if ((id = get_id(map_str, rayc)) == FAILURE)
		return (FAILURE);
	while (*map_str[0] && *map_str[0] != ' ')
		map_str[0]++;
	while (*map_str[0] && *map_str[0] == ' ')
		map_str[0]++;
	if (affect_id(id, map_str, rayc) == FAILURE)
		return (FAILURE);
	if (ft_move_nl(map_str) == FAILURE)
	{
		rayc->error = ERR_SYNT;
		return (FAILURE);
	}
	return (TRUE);
}

int		ft_id_parsing(char **map, t_raycast *rayc)
{
	int			ret;

	ret = TRUE;
	while (ret == TRUE)
		ret = ft_getinfo(map, rayc);
	return (ret);
}
