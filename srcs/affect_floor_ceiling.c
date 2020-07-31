/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affect_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:48:39 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 16:30:31 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"
#include "../header/mlx.h"
#include "../header/mlx_int.h"

int		ft_pass_comma(char **map_str, t_raycast *param)
{
	ft_pass_sp(map_str);
	if (*map_str[0]++ != ',')
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	ft_pass_sp(map_str);
	return (0);
}

int		affect_floor_ceiling(char **map_str, t_raycast *param, int *color)
{
	if (is_digit(*map_str[0]) == FALSE)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	*color = ft_atoi(map_str[0]);
	if (*color < 0 || *color > 255)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	ft_pass_digit(map_str);
	return (0);
}

int		ft_id_f(char **map_str, t_raycast *param)
{
	if (param->rf != -1 || param->gf != -1 || param->bf != -1)
	{
		param->error = ERR_NB_FC;
		return (FAILURE);
	}
	if (affect_floor_ceiling(map_str, param, &param->rf) == FAILURE)
		return (FAILURE);
	if (ft_pass_comma(map_str, param) == FAILURE)
		return (FAILURE);
	if (affect_floor_ceiling(map_str, param, &param->gf) == FAILURE)
		return (FAILURE);
	if (ft_pass_comma(map_str, param) == FAILURE)
		return (FAILURE);
	if (affect_floor_ceiling(map_str, param, &param->bf) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int		ft_id_c(char **map_str, t_raycast *param)
{
	if (param->rc != -1 || param->gc != -1 || param->bc != -1)
	{
		param->error = ERR_NB_FC;
		return (FAILURE);
	}
	if (affect_floor_ceiling(map_str, param, &param->rc) == FAILURE)
		return (FAILURE);
	if (ft_pass_comma(map_str, param) == FAILURE)
		return (FAILURE);
	if (affect_floor_ceiling(map_str, param, &param->gc) == FAILURE)
		return (FAILURE);
	if (ft_pass_comma(map_str, param) == FAILURE)
		return (FAILURE);
	if (affect_floor_ceiling(map_str, param, &param->bc) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
