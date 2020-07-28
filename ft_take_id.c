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
	int		resx;
	int		resy;
	if (param->resol_x != -1 || param->resol_y != -1)
		return (FAILURE);
	// printf("check char id r : %c\n", *map_str[0]);
	resx = ft_atoi(map_str[0]);
	if (resx <= 0) // ou <= 0
	{
		param->error = ERR_RESOL;
		return (FAILURE);
	}
	while (*map_str[0] >= '0' && *map_str[0] <= '9')
		map_str[0]++;
	while (*map_str[0] == ' ')
		map_str[0]++;
	resy = ft_atoi(map_str[0]);
	if (resy <= 0)
	{
		param->error = ERR_RESOL;
		return (FAILURE);
	}
	while ((*map_str[0] >= '0' && *map_str[0] <= '9') || *map_str[0] == 13) // enlever ^M
		map_str[0]++;
	if (resx > 1727)
		resx = 1727;
	if (resy > 992)
		resy = 992;
	param->resol_x = resx;
	param->resol_y = resy;
	// printf("check R x = %d y = %d\n", param->resol_x, param->resol_y);
	return (SUCCESS);
}

int		ft_id_no(char **map_str, t_raycast *param)
{
	char	*path;

	if ((*map_str[0] != '.' && (map_str[0][1]) != '/')
	|| param->no != NULL)
	{
		if (param->no != NULL)
			param->error = ERR_NB_TEXT;
		else
			param->error = ERR_TEXT_PATH;
		return (FAILURE);
	}
	path = malloc(sizeof(path) * 1);
	path[0] = '\0';
	// printf("curr char %c\n", *map_str[0]);
	while ((is_good_path_char(*map_str[0])) == TRUE && *map_str[0] != '\0'
	&& *map_str[0] != ' ' && *map_str[0] != '\n' && *map_str[0] != 13)
	{
		// write(1, &(*map_str[0]), 1);
		path = ft_strjoin_char(path, *map_str[0]);
		map_str[0]++;
	}
	if (*map_str[0] == 13)
		map_str[0]++;
	if (*map_str[0] == ' ' || *map_str[0] == '\n' || *map_str[0] == '\0')
	{
		param->no = path; // pensez à free à la fin
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

	if ((*map_str[0] != '.' && (map_str[0][1]) != '/')
	|| param->so != NULL)
	{
		if (param->so != NULL)
			param->error = ERR_NB_TEXT;
		else
			param->error = ERR_TEXT_PATH;
		return (FAILURE);
	}
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
		param->so = path; // pensez à free à la fin
		// printf("check path SO : %s\n", param->so);
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

	if ((*map_str[0] != '.' && (map_str[0][1]) != '/')
	|| param->we != NULL)
	{
		if (param->we != NULL)
			param->error = ERR_NB_TEXT;
		else
			param->error = ERR_TEXT_PATH;
		return (FAILURE);
	}
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
		param->we = path; // pensez à free à la fin
		// printf("check path WE : %s\n", param->we);
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

	if ((*map_str[0] != '.' && (map_str[0][1]) != '/')
	|| param->ea != NULL)
	{
		if (param->ea != NULL)
			param->error = ERR_NB_TEXT;
		else
			param->error = ERR_TEXT_PATH;
		return (FAILURE);
	}
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
		param->ea = path; // pensez à free à la fin
	// printf("check char : %c\n", *map_str[0]);
		// printf("check path EA : %s\n", param->ea);
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

	if ((*map_str[0] != '.' && (map_str[0][1]) != '/')
	|| param->sprite != NULL)
	{
		if (param->sprite != NULL)
			param->error = ERR_NB_TEXT;
		else
			param->error = ERR_TEXT_PATH;
		return (FAILURE);
	}
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
		param->sprite = path; // pensez à free à la fin
		// printf("check path SPRITE : %s\n", param->sprite);
		return (SUCCESS);
	}
	else
	{
		param->error = ERR_TEXT_PATH;
		free(path);
		return (FAILURE);
	}
}

int		ft_id_f(char **map_str, t_raycast *param)
{
	if (param->rf != -1 || param->gf != -1 || param->bf != -1)
	{
		param->error = ERR_NB_FC;
		return (FAILURE);
	}
	// printf("check char : %c\n", *map_str[0]);
	// if (is_digit(*map_str[0]) == FALSE)
	// 	return (FAILURE);
	param->rf = ft_atoi(map_str[0]);
	if (param->rf < 0 || param->rf > 255)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	while (is_digit(*map_str[0]) == TRUE)
		map_str[0]++;
	while (*map_str[0] == ' ')
		map_str[0]++;
	if (*map_str[0]++ != ',')
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	while (*map_str[0] == ' ')
		map_str[0]++;
	if (is_digit(*map_str[0]) == FALSE)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	param->gf = ft_atoi(map_str[0]);
	if (param->gf < 0 || param->gf > 255)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	while (is_digit(*map_str[0]) == TRUE)
		map_str[0]++;
	while (*map_str[0] == ' ')
		map_str[0]++;
	if (*map_str[0]++ != ',')
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	while (*map_str[0] == ' ')
		map_str[0]++;
	if (is_digit(*map_str[0]) == FALSE)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	param->bf = ft_atoi(map_str[0]);
	if (param->bf < 0 || param->bf > 255)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	while (is_digit(*map_str[0]) == TRUE)
		map_str[0]++;
	// printf("floor : %d %d %d\n", param->rf, param->gf, param->bf);
	return (SUCCESS);
}

int		ft_id_c(char **map_str, t_raycast *param)
{
	if (param->rc != -1 || param->gc != -1|| param->bc != -1)
	{
		param->error = ERR_NB_FC;
		return (FAILURE);
	}
	param->rc = ft_atoi(map_str[0]);
	if (param->rc < 0 || param->rc > 255)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	while (is_digit(*map_str[0]) == TRUE)
		map_str[0]++;
	while (*map_str[0] == ' ')
		map_str[0]++;
	if (*map_str[0]++ != ',')
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	while (*map_str[0] == ' ')
		map_str[0]++;
	if (is_digit(*map_str[0]) == FALSE)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	param->gc = ft_atoi(map_str[0]);
	if (param->gc < 0 || param->gc > 255)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	while (is_digit(*map_str[0]) == TRUE)
		map_str[0]++;
	while (*map_str[0] == ' ')
		map_str[0]++;
	if (*map_str[0]++ != ',')
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	while (*map_str[0] == ' ')
		map_str[0]++;
	if (is_digit(*map_str[0]) == FALSE)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	param->bc = ft_atoi(map_str[0]);
	if (param->bc < 0 || param->bc > 255)
	{
		param->error = ERR_FC;
		return (FAILURE);
	}
	while (is_digit(*map_str[0]) == TRUE)
		map_str[0]++;
	// printf("curr char %c", *map_str[0]);
	return (SUCCESS);
}
