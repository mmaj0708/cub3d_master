/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 18:49:01 by mmaj              #+#    #+#             */
/*   Updated: 2020/06/22 13:37:24 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/structure.h"
#include "./header/function.h"
#include "./header/definition.h"

int				ft_atoi(char *str)
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

int				is_good_path_char(char c)
{
	if (c == '\\' || c == ':' || c == '*' || c == '?' || c == '"'
	|| c == '<' || c == '>' || c == '|')
		return (FAILURE);
	return (TRUE);
}

char			*ft_strjoin_char(char *str, char c)
{
	int		i;
	char	*new;

	i = ft_strlen(str, 0);
	if ((!str) && (!c))
		return (NULL);
	new = malloc((i + 1 + 1));
		// return (NULL);
	if (str != NULL)
		ft_strcpy(new, str);
	new[i] = c;
	new[++i] = '\0';
	free(str);
	str = NULL;
	return (new);
}

int				is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == 13)
		return (TRUE);
	else
		return (FALSE);
}

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		put_char(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
	{
		n = -1 * nb;
		put_char('-');
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	put_char(n % 10 + 48);
}
