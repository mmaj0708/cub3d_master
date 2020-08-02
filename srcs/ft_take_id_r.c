/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_id_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 16:38:03 by mmaj              #+#    #+#             */
/*   Updated: 2020/08/02 22:06:09 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

int		ft_id_r(char **map_str, t_raycast *param)
{
	if (param->resol_x != -1 || param->resol_y != -1)
		return (FAILURE);
	param->resol_x = ft_atoi(map_str[0]);
	if (param->resol_x <= 0)
	{
		param->error = ERR_RESOL;
		return (FAILURE);
	}
	while (*map_str[0] >= '0' && *map_str[0] <= '9')
		map_str[0]++;
	while (*map_str[0] == ' ')
		map_str[0]++;
	param->resol_y = ft_atoi(map_str[0]);
	if (param->resol_y <= 0)
	{
		param->error = ERR_RESOL;
		return (FAILURE);
	}
	while ((*map_str[0] >= '0' && *map_str[0] <= '9') || *map_str[0] == 13)
		map_str[0]++;
	return (SUCCESS);
}
