/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:03:01 by user42            #+#    #+#             */
/*   Updated: 2020/08/02 12:56:28 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

void		ft_init_map(t_raycast *rayc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < MPH)
	{
		while (i < MPW)
		{
			rayc->struct_map[j][i] = -1;
			i++;
		}
		j++;
		i = 0;
	}
}

int			ft_init_param(t_raycast *rayc)
{
	rayc->no = NULL;
	rayc->so = NULL;
	rayc->we = NULL;
	rayc->ea = NULL;
	rayc->sprite = NULL;
	rayc->rc = -1;
	rayc->gc = -1;
	rayc->bc = -1;
	rayc->rf = -1;
	rayc->gf = -1;
	rayc->bf = -1;
	rayc->resol_x = -1;
	rayc->resol_y = -1;
	rayc->posx = -1;
	rayc->posy = -1;
	rayc->error = -1;
	rayc->numsprite = 0;
	rayc->endmap = 0;
	return (0);
}

int			ft_check_arg(char **av)
{
	int		i;

	i = 0;
	while (av[1][i] != '\0')
		i++;
	if (av[1][i - 1] && av[1][i - 2] && av[1][i - 3] && av[1][i - 4]
	&& av[1][i - 1] == 'b' && av[1][i - 2] == 'u'
	&& av[1][i - 3] == 'c' && av[1][i - 4])
		return (TRUE);
	else
		return (FALSE);
}

void		ft_err_arg(int ac, char **av, t_raycast *rayc)
{
	if (ac > 3 || ac < 2)
	{
		rayc->error = ERR_NB_ARG;
		ft_quit(rayc);
	}
	if (ft_check_arg(av) == FALSE)
	{
		rayc->error = ERR_WRONG_ARG;
		ft_quit(rayc);
	}
}

int			main(int ac, char **av)
{
	t_raycast	rayc;

	ft_init_param(&rayc);
	ft_init_map(&rayc);
	ft_err_arg(ac, av, &rayc);
	if (ac == 3)
		ft_bmp(&rayc, av);
	if (ft_set(av[1], &rayc, rayc.struct_map) == FAILURE)
		ft_quit(&rayc);
	ft_init_rayc(&rayc);
	ft_init_mlx(&rayc);
	ft_first_img(&rayc);
	mlx_hook(rayc.mlx_win, KEYPRESS, 1L << 0, &ft_key_hit, &rayc);
	mlx_hook(rayc.mlx_win, KEYRELEASE, 1L << 1, &ft_key_release, &rayc);
	mlx_hook(rayc.mlx_win, DESTROY_NOTIFY, 1L << 17, &ft_quit, &rayc);
	mlx_loop_hook(rayc.mlx_ptr, &dealkey, &rayc);
	mlx_loop(rayc.mlx_ptr);
}
