/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:58:46 by ale-roux          #+#    #+#             */
/*   Updated: 2023/07/20 02:00:47 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

long long	get_ms(void)
{
	struct timeval	tv;
	long long		ms;

	gettimeofday(&tv, NULL),
	ms = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
	return (ms);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && n > 0 && s2[i])
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	intlen(long int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				i;
	int				y;
	char			*nbr;
	unsigned int	saveme;

	i = intlen(n);
	y = 0;
	saveme = n;
	nbr = malloc((i + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[i] = '\0';
	if (n < 0)
	{
		nbr[0] = '-';
		saveme = -n;
		y++;
	}
	while (i > y)
	{
		nbr[--i] = (saveme % 10) + 48;
		saveme = saveme / 10;
	}
	return (nbr);
}
