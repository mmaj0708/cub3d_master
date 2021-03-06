/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_verify_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 16:45:22 by mmaj              #+#    #+#             */
/*   Updated: 2020/08/02 12:53:19 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

int		is_end_file(char **map_str, int k)
{
	while (map_str[0][k] == '\n' || map_str[0][k] == 13)
		k++;
	if (map_str[0][k] == '\0')
		return (TRUE);
	else
		return (FALSE);
}

int		ft_get_map(char **map_str, int struct_map[MPH][MPW], t_raycast *rayc)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (map_str[0][k] && map_str[0][k] != '\n')
	{
		while (map_str[0][k] != '\0' && map_str[0][k] != 13)
		{
			struct_map[rayc->endmap][i] = map_str[0][k] - 48;
			i++;
			k++;
		}
		if (map_str[0][k] == 13)
			k = k + 2;
		if ((map_str[0][k] == '\n' || map_str[0][k] == 13)
		&& is_end_file(map_str, k) == FALSE)
		{
			rayc->error = ERR_DIGIT_MAP;
			return (FAILURE);
		}
		rayc->endmap++;
		i = 0;
	}
	return (0);
}

int		is_good_digit(int a)
{
	if (a == 0 || a == 2 || a == 'N' - 48 || a == 'S' - 48
	|| a == 'W' - 48 || a == 'E' - 48
	|| a == 1)
		return (TRUE);
	else
		return (FALSE);
}

int		is_zero(int a)
{
	if (a == 0 || a == 2 || a == 'N' - 48 || a == 'S' - 48
	|| a == 'W' - 48 || a == 'E' - 48)
		return (TRUE);
	else
		return (FALSE);
}

int		verif_digit(t_raycast *r)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < r->endmap)
	{
		while (r->struct_map[j][i] == ' ' - 48)
			i++;
		while (is_good_digit(r->struct_map[j][i]) == TRUE)
		{
			if (is_zero(r->struct_map[j][i]) && !ft_check_closed_map(r, i, j))
				return (FAILURE);
			i++;
		}
		if (r->struct_map[j][i] == ' ' - 48
		&& r->struct_map[j][i + 1] != -1)
			i++;
		else
		{
			j++;
			i = 0;
		}
	}
	return (SUCCESS);
}
