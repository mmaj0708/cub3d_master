/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 14:04:16 by mmaj              #+#    #+#             */
/*   Updated: 2020/05/12 14:04:16 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

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
	if (param->resol_x > 1727)
		param->resol_x = 1727;
	if (param->resol_y > 992)
		param->resol_y = 992;
	return (SUCCESS);
}

