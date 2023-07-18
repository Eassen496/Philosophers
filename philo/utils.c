/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:58:46 by ale-roux          #+#    #+#             */
/*   Updated: 2023/07/18 22:10:52 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philosopher_thinking(t_philo *philo, int id)
{
	long long time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == false)
		printf("%lld %d is thinking\n", time_in_ms, id);
	return ;
}

int	philosopher_eating(t_philo *philo, int id)
{
	long long	time_in_ms;

	pthread_mutex_lock(&philo->utils.mutex[id]);
	if (philo->isdead == true)
		return (philo_unlock(philo, id, false));
	time_in_ms = get_ms() - philo->time.in_ms_start;
	printf("%lld %d has taken a fork\n", time_in_ms, id);
	if (id == philo->nphilo)
		pthread_mutex_lock(&philo->utils.mutex[1]);
	else
		pthread_mutex_lock(&philo->utils.mutex[id + 1]);
	if (philo->isdead == true)
		return (philo_unlock(philo, id, true));
	time_in_ms = get_ms() - philo->time.in_ms_start;
	printf("%lld %d has taken a fork\n", time_in_ms, id);
	printf("%lld %d is eating\n", time_in_ms, id);
	while (time_in_ms + philo->time.to_eat > get_ms() - philo->time.in_ms_start)
		usleep(10);
	philo_unlock(philo, id, true);
	philo->utils.eat[id]++;
	return (time_in_ms);
}

void	philosopher_sleeping(t_philo *philo, int id)
{
	long long time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == true)
		return ;
	printf("%lld %d is sleeping\n", time_in_ms, id);
	time_in_ms += (long long)philo->time.to_sleep;
	while (time_in_ms > get_ms() - philo->time.in_ms_start)
		usleep(100);
	return ;
}

void	philosopher_died(t_philo *philo, int id)
{
	long long time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == false)
		printf("%lld %d died\n", time_in_ms, id);
	philo->isdead = true;
	return ;
}

long long	get_ms()
{
	struct timeval tv;
	long long ms;

	gettimeofday(&tv, NULL),
	ms = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
	return (ms);
}

int	philo_unlock(t_philo *philo, int id, bool all)
{
	pthread_mutex_unlock(&philo->utils.mutex[id]);
	if (all == true)
	{
		if (id == philo->nphilo)
			pthread_mutex_unlock(&philo->utils.mutex[1]);
		else
			pthread_mutex_unlock(&philo->utils.mutex[id + 1]);
	}
	return (0);
}

void eat_verif(t_philo *philo)
{
	int	i;

	i = 1;
	while (i < philo->nphilo - 1)
	{
		if (philo->utils.eat[i] == philo->utils.eat[i + 1])
			i++;
		else
			break ;
	}
	if ((i == philo->nphilo - 1) && (philo->utils.eat[i] == philo->utils.eat[i + 1]) && (philo->utils.eat[i] != philo->utils.all_eat))
		philo->utils.all_eat++;
	if (philo->utils.all_eat == philo->limit_eat)
		philo->isdead = true;
	return ;
}

void *philosopher(void *void_philo)
{
	int id;
	long long time_in_ms;
	t_philo *philo;

	philo = (t_philo *)void_philo;
	id = philo->utils.id;
	time_in_ms = get_ms() - philo->time.in_ms_start;
	while (philo->isdead == false)
	{
		philosopher_thinking(philo, id);
		if (time_in_ms + philo->time.to_die < get_ms() -  philo->time.in_ms_start && philo->isdead == false)
		{
			philosopher_died(philo, id);
			break ;
		}
		time_in_ms = philosopher_eating(philo, id);
		eat_verif(philo);
		philosopher_sleeping(philo, id);
		if (time_in_ms + philo->time.to_die < get_ms() -  philo->time.in_ms_start && philo->isdead == false)
		{
			philosopher_died(philo, id);
			break ;
		}
	}
	return (NULL);
}

int	thread_create(t_philo *philo)
{
	int	i;

	i = 0;
	philo->time.in_ms_start = get_ms();
	while (i < philo->nphilo)
	{
		philo->utils.id = i + 1;
		pthread_create(&philo->utils.thread[i], NULL, philosopher, (void *)philo);
		usleep(100);
		i += 2;
	}
	usleep(10);
	i = 1;
	while (i < philo->nphilo)
	{
		philo->utils.id = i + 1;
		pthread_create(&philo->utils.thread[i], NULL, philosopher, (void *)philo);
		usleep(100);
		i += 2;
	}
	i = 0;
	while (i < philo->nphilo)
	{
		pthread_join(philo->utils.thread[i], NULL);
		usleep(100);
		i++;
	}
	return (0);
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

static int	whitesp(char *str, int *ptr_i)
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

void	create_mutex(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->nphilo)
	{
		pthread_mutex_init(&philo->utils.mutex[i], NULL);
		usleep(100);
		i++;
	}
	return ;
}

void	destroy_mutex(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->nphilo)
	{
		pthread_mutex_destroy(&philo->utils.mutex[i]);
		usleep(100);
		i++;
	}
	return ;
}

void philo_eat_fill(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nphilo)
		philo->utils.eat[i++] = 0;
	philo->utils.all_eat = 0;
	return ;
}

void philo_main(int argc, char **argv)
{
	t_philo *philo;

	philo = (t_philo *)malloc(1 * sizeof(t_philo));
	if (!philo)
		return ;
	philo->nphilo = ft_atoi(argv[1]);
	philo->time.to_die = ft_atoi(argv[2]);
	philo->time.to_eat = ft_atoi(argv[3]);
	philo->time.to_sleep = ft_atoi(argv[4]);
	philo->isdead = false;
	philo_eat_fill(philo);
	if (argc == 6)
		philo->limit_eat = ft_atoi(argv[5]);
	else
		philo->limit_eat = -1;
	create_mutex(philo);
	thread_create(philo);
	if (philo->isdead == true)
	{
		destroy_mutex(philo);
		free(philo);
	}
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

void *unique_philosopher2(void *void_unique)
{
	t_unique	*unique;

	unique = (t_unique *)void_unique;
	unique->time = get_ms();
	printf("%lld %d is thinking\n", get_ms() - unique->time, 1);
	pthread_mutex_lock(&unique->mutex);
	printf("%lld %d is taking a fork\n", get_ms() - unique->time, 1);
	usleep(ft_atoi(unique->argv[2]) * 1000);
	printf("%lld %d died\n", get_ms() - unique->time, 1);
	pthread_mutex_unlock(&unique->mutex);
	return (NULL);
}

int	unique_case(int argc, char **argv)
{
	t_unique			*unique;
	pthread_t			thread[1];
	int					i;
	
	i = 0;
	unique = (t_unique *)malloc(1 * sizeof(t_unique));
	unique->argc = argc;
	unique->argv = argv;
	pthread_mutex_init(&unique->mutex, NULL);
	while (i < 1)
	{
		pthread_create(&thread[i], NULL, unique_philosopher2, (void *)unique);
		usleep(100);
		i++;
	}
	pthread_join(thread[0], NULL);
	pthread_mutex_destroy(&unique->mutex);
	free(unique);
	return (0);
}