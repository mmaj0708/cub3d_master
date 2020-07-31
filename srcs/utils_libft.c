/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:02:47 by mmaj              #+#    #+#             */
/*   Updated: 2020/07/30 17:03:48 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/structure.h"
#include "../header/function.h"
#include "../header/definition.h"

int		ft_atoi(char *str)
{
	long			i;
	long			sign;
	unsigned int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i++;
	}
	return ((int)(nb * sign));
}

int		ft_strlen(char *s, char c)
{
	int	i;

	i = 0;
	if ((!s) || (!s[i]))
		return (0);
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*new;

	i = ft_strlen(s1, 0);
	if ((!s1) && (!s2))
		return (NULL);
	if (!(new = malloc(sizeof(new)
		* (ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1))))
		return (NULL);
	if (s1 != NULL)
		ft_strcpy(new, s1);
	ft_strcpy(&new[i], s2);
	free(s1);
	s1 = NULL;
	return (new);
}

void	ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
	{
		n = -1 * nb;
		ft_put_char('-');
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_put_char(n % 10 + 48);
}
