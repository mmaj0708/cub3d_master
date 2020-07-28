/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:59:20 by mmaj              #+#    #+#             */
/*   Updated: 2020/05/12 11:59:20 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

int		ft_strstr(char **str, char *to_find)
{
	int i;

	i = 0;
	while (str[0][i] == to_find[i])
	{
		i++;
		// printf("**str == %c, *to_find == %c\n", **str, *to_find);
	// printf("check current char strstr : %c\n", *str[0]);
		if (to_find[i] == '\0')
			return (TRUE);	
		if (str[0][i] == '\0')
			return (FAILURE);
	}
	return (FAILURE);
}

int		get_id(char **map, t_raycast *rayc)
{
	if (ft_strstr(map, "R ") == 1)
		return (0);
	if (ft_strstr(map, "NO ") == 1)
		return (1);
	if (ft_strstr(map, "SO ") == 1)
		return (2);
	if (ft_strstr(map, "WE ") == 1)
		return (3);
	if (ft_strstr(map, "EA ") == 1)
		return (4);
	if (ft_strstr(map, "S ") == 1)
		return (5);
	if (ft_strstr(map, "F ") == 1)
		return (6);
	if (ft_strstr(map, "C ") == 1)
		return (7);
	rayc->error = ERR_WR_ID;
	return (FAILURE);
}

t_fct_take_id	*fct_tk_id_init(t_fct_take_id *fct_tk_id)
{
	fct_tk_id[0].ptrfct = &ft_id_r;
	fct_tk_id[0].id = 0;
	fct_tk_id[1].ptrfct = &ft_id_no;
	fct_tk_id[1].id = 1;
	fct_tk_id[2].ptrfct = &ft_id_so;
	fct_tk_id[2].id = 2;
	fct_tk_id[3].ptrfct = &ft_id_we;
	fct_tk_id[3].id = 3;
	fct_tk_id[4].ptrfct = &ft_id_ea;
	fct_tk_id[4].id = 4;
	fct_tk_id[5].ptrfct = &ft_id_s;
	fct_tk_id[5].id = 5;
	fct_tk_id[6].ptrfct = &ft_id_f;
	fct_tk_id[6].id = 6;
	fct_tk_id[7].ptrfct = &ft_id_c;
	fct_tk_id[7].id = 7;
	fct_tk_id[8].ptrfct = NULL;
	fct_tk_id[8].id = FAILURE;
	return (fct_tk_id);
}

int		affect_id(int id, char **map_str, t_raycast *rayc)
{
	int				i;
	int				ret;
	t_fct_take_id	fct_tk_id[9];
	
	i = 0;
	ret = FAILURE;

	// fct_tk_id = malloc(sizeof(fct_tk_id) * 1);
	fct_tk_id_init(fct_tk_id);

	// printf("check current char affect_id: %c\n", *map_str[0]);

	while (fct_tk_id[i].id != id && fct_tk_id[i].id != -1)
		i++;
	if (fct_tk_id[i].id == id)
		ret = fct_tk_id[i].ptrfct(map_str, rayc);
	// printf("check affect_id : %d\n", id);
	return (ret);
}

int		ft_is_complete(t_raycast *rayc)
{
	if (rayc->sprite != NULL && rayc->no != NULL && rayc->so != NULL && rayc->we != NULL 
	&& rayc->ea != NULL && rayc->rc != -1 && rayc->gc != -1 && rayc->bc != -1
	&& rayc->rf != -1 && rayc->gf != -1 && rayc->bf != -1 && rayc->resol_x != -1
	&& rayc->resol_y != -1 ) // ne marche pas si des valeurs valent zéro 
		return (TRUE); // initialiser à -1 je dirais ou voir si possible éviter initialisation
	else
		return (FALSE);
}

int		ft_move_nl(char **map_str)
{

	while (*map_str[0] != '\0' && (*map_str[0] == ' ' || *map_str[0] == 13))
		map_str[0]++;
	// ATTENTION : il y a un char invisible en plus faudra ptet le virer à 42
	
	if (*map_str[0] == '\0' || *map_str[0] == '\n')
	{
		map_str[0]++;
		if (*map_str[0] != '\0')
			return (SUCCESS);
	}
	// printf("check RET\n");
	// printf("check char : %c\n", *map_str[0]);
	return (FAILURE);	
}


int		ft_getinfo(char **map_str, t_raycast *rayc)
{
	int		ret;
	int		id;

	ret = 0;
	while (*map_str[0] == ' ' || *map_str[0] == '\n' || *map_str[0] == 13)
	{
		map_str[0]++; // bug parce que '^M'
	}
	if (*map_str[0] == '1' && ft_is_complete(rayc) == FALSE)
	{
		rayc->error = ERR_NB_ID;
		return (FAILURE);
	}
	if (*map_str[0] != '1' && ft_is_complete(rayc) == TRUE)
	{
	// printf("check char : %c\n", *map_str[0]);

		rayc->error = ERR_NO_MAP;
		return (FAILURE);
	}
	if (*map_str[0] == '1' && ft_is_complete(rayc) == TRUE)
		return (SUCCESS);
	
	id = get_id(map_str, rayc); // quel identifiant ?
	// printf("id = %d\n", id);
	if (id == FAILURE)
		return (FAILURE);
	
	while (*map_str[0] && *map_str[0] != ' ') // passer l'id
		map_str[0]++;
	while (*map_str[0] && *map_str[0] == ' ')
		map_str[0]++;
	// printf("check first char  : %c\n", *map_str[0]);

	if ((ret = affect_id(id, map_str, rayc) == FAILURE)) // affecte les infos suivant l'id à une structure
		return (FAILURE);

	// printf("check path R : %d, %d\n", rayc->resol_x, rayc->resol_y);
	// printf("check test rgb : %d %d %d\n", rayc->rc, rayc->gc, rayc->bc);
	// printf("check retour affect : %d\n", ret);


	if ((ret = ft_move_nl(map_str)) == FAILURE) // passer à la ligne suivante en acceptant les esp
	{	

		rayc->error = ERR_SYNT;
		return (FAILURE);
	}


	return (TRUE);
}