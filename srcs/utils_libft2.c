/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:04:07 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/31 17:53:56 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

char	*ft_strjoin_char(char *str, char c)
{
	int		i;
	char	*new;

	i = ft_strlen(str, 0);
	if ((!str) && (!c))
		return (NULL);
	new = malloc((i + 1 + 1));
	if (str != NULL)
		ft_strcpy(new, str);
	new[i] = c;
	new[++i] = '\0';
	free(str);
	str = NULL;
	return (new);
}

int		is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == 13)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_put_char(str[i]);
		i++;
	}
}

int		ft_strstr(char **str, char *to_find)
{
	int i;

	i = 0;
	while (str[0][i] == to_find[i])
	{
		i++;
		if (to_find[i] == '\0')
			return (TRUE);
		if (str[0][i] == '\0')
			return (FAILURE);
	}
	return (FAILURE);
}
