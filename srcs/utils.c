/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:49:01 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 17:06:49 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"
#include "../header/mlx.h"
#include "../header/mlx_int.h"

int		is_good_path_char(char c)
{
	if (c == '\\' || c == ':' || c == '*' || c == '?' || c == '"'
	|| c == '<' || c == '>' || c == '|')
		return (FAILURE);
	return (TRUE);
}

void	ft_pass_sp(char **map_str)
{
	while (*map_str[0] == ' ')
		map_str[0]++;
}

void	ft_pass_digit(char **map_str)
{
	while (is_digit(*map_str[0]) == TRUE)
		map_str[0]++;
}

int		ft_check_nb_text(t_raycast *param, char *texture)
{
	if (texture != NULL)
	{
		param->error = ERR_NB_TEXT;
		return (FAILURE);
	}
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
