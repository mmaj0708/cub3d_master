/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affect_id_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:06:10 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 16:35:34 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

int		ft_id_no(char **map_str, t_raycast *param)
{
	char	*path;

	if (ft_check_nb_text(param, param->no) == FAILURE)
		return (FAILURE);
	path = malloc(sizeof(path) * 1);
	path[0] = '\0';
	while ((is_good_path_char(*map_str[0])) == TRUE && *map_str[0] != '\0'
	&& *map_str[0] != ' ' && *map_str[0] != '\n' && *map_str[0] != 13)
	{
		path = ft_strjoin_char(path, *map_str[0]);
		map_str[0]++;
	}
	if (*map_str[0] == 13)
		map_str[0]++;
	if (*map_str[0] == ' ' || *map_str[0] == '\n' || *map_str[0] == '\0')
	{
		param->no = path;
		return (SUCCESS);
	}
	else
	{
		free(path);
		param->error = ERR_TEXT_PATH;
		return (FAILURE);
	}
}

int		ft_id_so(char **map_str, t_raycast *param)
{
	char	*path;

	if (ft_check_nb_text(param, param->so) == FAILURE)
		return (FAILURE);
	path = malloc(sizeof(path) * 1);
	path[0] = '\0';
	while ((is_good_path_char(*map_str[0])) == TRUE && *map_str[0] != '\0'
	&& *map_str[0] != ' ' && *map_str[0] != '\n' && *map_str[0] != 13)
	{
		path = ft_strjoin_char(path, *map_str[0]);
		map_str[0]++;
	}
	if (*map_str[0] == 13)
		map_str[0]++;
	if (*map_str[0] == ' ' || *map_str[0] == '\n' || *map_str[0] == '\0')
	{
		param->so = path;
		return (SUCCESS);
	}
	else
	{
		free(path);
		param->error = ERR_TEXT_PATH;
		return (FAILURE);
	}
}

int		ft_id_we(char **map_str, t_raycast *param)
{
	char	*path;

	if (ft_check_nb_text(param, param->we) == FAILURE)
		return (FAILURE);
	path = malloc(sizeof(path) * 1);
	path[0] = '\0';
	while ((is_good_path_char(*map_str[0])) == TRUE && *map_str[0] != '\0'
	&& *map_str[0] != ' ' && *map_str[0] != '\n' && *map_str[0] != 13)
	{
		path = ft_strjoin_char(path, *map_str[0]);
		map_str[0]++;
	}
	if (*map_str[0] == 13)
		map_str[0]++;
	if (*map_str[0] == ' ' || *map_str[0] == '\n' || *map_str[0] == '\0')
	{
		param->we = path;
		return (SUCCESS);
	}
	else
	{
		param->error = ERR_TEXT_PATH;
		free(path);
		return (FAILURE);
	}
}

int		ft_id_ea(char **map_str, t_raycast *param)
{
	char	*path;

	if (ft_check_nb_text(param, param->ea) == FAILURE)
		return (FAILURE);
	path = malloc(sizeof(path) * 1);
	path[0] = '\0';
	while ((is_good_path_char(*map_str[0])) == TRUE && *map_str[0] != '\0'
	&& *map_str[0] != ' ' && *map_str[0] != '\n' && *map_str[0] != 13)
	{
		path = ft_strjoin_char(path, *map_str[0]);
		map_str[0]++;
	}
	if (*map_str[0] == 13)
		map_str[0]++;
	if (*map_str[0] == ' ' || *map_str[0] == '\n' || *map_str[0] == '\0')
	{
		param->ea = path;
		return (SUCCESS);
	}
	else
	{
		param->error = ERR_TEXT_PATH;
		free(path);
		return (FAILURE);
	}
}

int		ft_id_s(char **map_str, t_raycast *param)
{
	char	*path;

	if (ft_check_nb_text(param, param->sprite) == FAILURE)
		return (FAILURE);
	path = malloc(sizeof(path) * 1);
	path[0] = '\0';
	while ((is_good_path_char(*map_str[0])) == TRUE && *map_str[0] != '\0'
	&& *map_str[0] != ' ' && *map_str[0] != '\n' && *map_str[0] != 13)
	{
		path = ft_strjoin_char(path, *map_str[0]);
		map_str[0]++;
	}
	if (*map_str[0] == 13)
		map_str[0]++;
	if (*map_str[0] == ' ' || *map_str[0] == '\n' || *map_str[0] == '\0')
	{
		param->sprite = path;
		return (SUCCESS);
	}
	else
	{
		param->error = ERR_TEXT_PATH;
		free(path);
		return (FAILURE);
	}
}
