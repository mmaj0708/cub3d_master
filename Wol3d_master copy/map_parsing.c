/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 20:33:29 by mmaj              #+#    #+#             */
/*   Updated: 2020/05/16 20:33:29 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

int		is_end_file(char **map_str, int k)
{
	while (map_str[0][k] == '\n' || map_str[0][k] == 13)
		k++;
	if (map_str[0][k] == '\0')
		return (TRUE);
	else
		return (FALSE);
}

int		ft_get_map(char **map_str, int struct_map[400][400], t_raycast *rayc)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (map_str[0][k] && map_str[0][k] != '\n')
	{
		while (map_str[0][k] != '\0' && map_str[0][k] != 13)
		{
			// while (map_str[0][k] == ' ' && map_str[0][k] != '\0') // si ya des espaces je malloc en trop par contre
			// 	k++;
			struct_map[j][i] = map_str[0][k] - 48;
			// printf("current value struct_map[%d][%d] : %d\n", j, i, struct_map[j][i]);
			i++;
			k++;
		}
		struct_map[j][i] = -1;
		// printf("check current map char : %c\n", map_str[0][k]);
		if (map_str[0][k] == 13)
			k = k + 2; // sauter ^M + \n
		if ((map_str[0][k] == '\n' || map_str[0][k] == 13) && is_end_file(map_str, k) == FALSE)
		{
			rayc->error = ERR_DIGIT_MAP;
			return (FAILURE);
		}
		j++;
		i = 0;
	}
	rayc->endmap = j;
	struct_map[j][i] = -1;
	// struct_map[j] = NULL;
	return (0);
}

int		is_good_digit(int a)
{
	if (a == 0 || a == 2 || a == 'N' - 48 || a == 'S' - 48 || a == 'W' - 48 || a == 'E' - 48
	|| a == 1)
	return (TRUE);
	else
		return (FALSE);
}

int		is_zero(int a)
{
	if (a == 0 || a == 2 || a == 'N' - 48 || a == 'S' - 48 || a == 'W' - 48 || a == 'E' - 48)
	return (TRUE);
	else
		return (FALSE);
}

int		is_one_vertN(t_raycast *rayc, int i, int j)
{
	// printf("\n\ncheck digit : %d\n\n", struct_map[j][i]);
	while (j < rayc->endmap && j >= 0 && is_zero(rayc->struct_map[j][i]) == TRUE)
	{
	// printf("check j i : %d %d\n", j, i);
		j--;
	}
	if (rayc->struct_map[j][i] == 1)
	{
	// printf("right nb : %d\n", rayc->struct_map[j][i]);
		return (TRUE);
	}
	else
	{
	// printf("check false nb : %d\n", rayc->struct_map[j][i]);
		return (FALSE);
	}
}

int		is_one_vertS(t_raycast *rayc, int i, int j)
{
	while (j < rayc->endmap && j >= 0 && is_zero(rayc->struct_map[j][i]) == TRUE)
	{
		j++;
	}
	if (rayc->struct_map[j][i] == 1)
		return (TRUE);
	else
		return (FALSE);
}

int		is_one_horiW(t_raycast *rayc, int i, int j)
{
	while (rayc->struct_map[j][i] != -1 && i >= 0 && is_zero(rayc->struct_map[j][i]) == TRUE)
	{
		i--;
	}
	if (rayc->struct_map[j][i] == 1)
	{
	// printf("right nb : %d\n", rayc->struct_map[j][i]);
		return (TRUE);
	}
	else
	{
	// printf("check false nb : %d\n", rayc->struct_map[j][i]);
		return (FALSE);
	}
}

int		is_one_horiE(t_raycast *rayc, int i, int j)
{
	while (rayc->struct_map[j][i] != -1 && i >= -1 && is_zero(rayc->struct_map[j][i]) == TRUE)
	{
		i++;
	}
	if (rayc->struct_map[j][i] == 1)
		return (TRUE);
	else
		return (FALSE);
}


int		verif_digit(t_raycast *rayc)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	while (j < rayc->endmap)
	{
		while (rayc->struct_map[j][i] == ' ' - 48)
		{
			// printf("check space\n");	
			i++;
		}
		while (is_good_digit(rayc->struct_map[j][i]) == TRUE)
		{
			// printf("retour good digit %d\n", is_good_digit(rayc->struct_map[j][i]));
			if (is_zero(rayc->struct_map[j][i]) == TRUE)
			{
				if((ret = is_one_vertN(rayc, i, j)) == FALSE) // sinon tu lui files i et j
				{
					// printf("check N : %d\n", ret);
					return (FAILURE);
				}
				if((ret = is_one_vertS(rayc, i, j)) == FALSE) // sinon tu lui files i et j
				{
					// printf("check S : %d\n", ret);
					return (FAILURE);
				}
				if((ret = is_one_horiW(rayc, i, j)) == FALSE) // sinon tu lui files i et j
				{
					// printf("check W : %d\n", ret);
					return (FAILURE);
				}
				if((ret = is_one_horiE(rayc, i, j)) == FALSE) // sinon tu lui files i et j
				{
					// printf("check E : %d\n", ret);
					return (FAILURE);
				}
			}
			i++;
		}
		if (rayc->struct_map[j][i] == ' ' - 48 && rayc->struct_map[j][i + 1] != -1)
			i++;
		else
		{
			i = 0;
			j++;
		}
		
	}
	return (SUCCESS);
}
