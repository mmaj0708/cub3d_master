/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_closed_mp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:50:09 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/29 15:50:30 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

int		is_one_vertn(t_raycast *rayc, int i, int j)
{
	while (j < rayc->endmap && j >= 0
	&& is_zero(rayc->struct_map[j][i]) == TRUE)
		j--;
	if (rayc->struct_map[j][i] == 1)
		return (TRUE);
	else
		return (FALSE);
}

int		is_one_verts(t_raycast *rayc, int i, int j)
{
	while (j < rayc->endmap && j >= 0
	&& is_zero(rayc->struct_map[j][i]) == TRUE)
		j++;
	if (rayc->struct_map[j][i] == 1)
		return (TRUE);
	else
		return (FALSE);
}

int		is_one_horiw(t_raycast *rayc, int i, int j)
{
	while (rayc->struct_map[j][i] != -1 && i >= 0
	&& is_zero(rayc->struct_map[j][i]) == TRUE)
		i--;
	if (rayc->struct_map[j][i] == 1)
		return (TRUE);
	else
		return (FALSE);
}

int		is_one_horie(t_raycast *rayc, int i, int j)
{
	while (rayc->struct_map[j][i] != -1 && i >= -1
	&& is_zero(rayc->struct_map[j][i]) == TRUE)
		i++;
	if (rayc->struct_map[j][i] == 1)
		return (TRUE);
	else
		return (FALSE);
}

int		ft_check_closed_map(t_raycast *rayc, int i, int j)
{
	if (is_one_vertn(rayc, i, j) == FALSE)
		return (FAILURE);
	if (is_one_verts(rayc, i, j) == FALSE)
		return (FAILURE);
	if (is_one_horiw(rayc, i, j) == FALSE)
		return (FAILURE);
	if (is_one_horie(rayc, i, j) == FALSE)
		return (FAILURE);
	return (TRUE);
}
