/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 16:26:59 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 16:37:11 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

char		*ft_read_map(char *map_file)
{
	int		fd;
	int		ret;
	char	*map;
	char	*buff;

	map = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd == FAILURE)
		return (NULL);
	if (!(buff = malloc(33)))
		return (NULL);
	while ((ret = read(fd, buff, 32)) > 0)
	{
		buff[ret] = '\0';
		if (!(map = ft_strjoin(map, buff)))
			return (NULL);
	}
	free(buff);
	close(fd);
	return (map);
}
