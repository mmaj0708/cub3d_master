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
	fct_tk_id_init(fct_tk_id);
	while (fct_tk_id[i].id != id && fct_tk_id[i].id != -1)
		i++;
	if (fct_tk_id[i].id == id)
		ret = fct_tk_id[i].ptrfct(map_str, rayc);
	return (ret);
}
