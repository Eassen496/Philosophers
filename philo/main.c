/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:58:46 by ale-roux          #+#    #+#             */
/*   Updated: 2023/01/19 23:02:07 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

void is_thinkig()
{
	printf("\d")
}

int	get_ms()
{
	
}

void philosopher(void *philo)
{
	int id;

	id = (t_philo)philo.utils.id;
	while (42)
	{
		is_thinking();
		if (id % 2 == 0)
			philosopher_eat_2();
		else
			philosopher_eat_1();
	}
}


int	thread_create(t_philo philo)
{
	int	i;

	i = 0;
	while (i < philo.nphilo)
	{
		philo.utils.id = i + 1;
		pthread_create(&philo.utils.thread[i], NULL, philosopher, &philo);
		i++;
	}
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

int	whitesp(char *str, int *ptr_i)
{
	int	count;
	int	i;
	int	sign;

	i = 0;
	count = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
		count++;
	}
	*ptr_i = i;
	if (count != 0)
		return (count * sign);
	else
		return (sign);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = whitesp(str, &i);
	if (sign != -1 && sign != 1)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	res *= sign;
	return (res);
}

void philo_init(int argc, char **argv)
{
	t_philo philos;

	philos = malloc(1 * sizeof(t_philo));
}

int	arg_verif(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], ft_itoa(ft_atoi(argv[i])), ft_strlen(argv[i])))
			return (arg_error_1());
		if (ft_atoi(argv[i]) < 0)
			return (arg_error_2());
		i++;
	}
	if (ft_atoi(argv[1]) == 0)
		return (arg_error_3());
	if (ft_atoi(argv[1]) > 200)
		return (arg_error_4());
	return (0);
}

int	unique_case()

int	main(int argc, char	**argv)
{
	if (argc < 5 || argc > 6)
		return (arg_error_0());
	if (arg_verif(argv, argc) != 0)
		return (1);
	if (ft_atoi(argv[1]) == 1)
		return (unique_case(int argc, char **argv));
	philo_init(argc, argv);
	return (0);
}
