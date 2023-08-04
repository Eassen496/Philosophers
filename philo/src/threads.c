/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:42:56 by ale-roux          #+#    #+#             */
/*   Updated: 2023/08/04 03:18:29 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*p(void *void_philo)
{
	int			id;
	t_philo		*philo;

	philo = (t_philo *)void_philo;
	id = philo->utils.id;
	philo->utils.time_in_ms[id] = get_ms() - philo->time.in_ms_start;
	while (philo->isdead == false)
	{
		philosopher_thinking(philo, id);
		if (philo->isdead == true)
			break ;
		philosopher_eating(philo, id);
		if ((id == philo->nphilo || id == philo->nphilo - 1) && id % 2 == 0)
			eat_verif(philo, id);
		if (philo->isdead == true)
			break ;
		philosopher_sleeping(philo, id, philo->utils.time_in_ms[id]);
		if (philo->isdead == true)
			break ;
	}
	return (NULL);
}

void	thread_join(t_philo *philo)
{
	int	i;

	i = 1;
	while (i < philo->nphilo + 1)
	{
		pthread_join(philo->utils.thread[i], NULL);
		usleep(100);
		i++;
	}
}

int	thread_create(t_philo *philo, int i)
{
	philo->time.in_ms_start = get_ms();
	while (i < philo->nphilo)
	{
		philo->utils.id = i + 1;
		pthread_create(&philo->utils.thread[i += 2], NULL, p, (void *)philo);
		usleep(50);
	}
	i = 1;
	while (i < philo->nphilo)
	{
		philo->utils.id = i + 1;
		pthread_create(&philo->utils.thread[i += 2], NULL, p, (void *)philo);
		usleep(50);
	}
	while (philo->isdead == false)
	{
		i = 1;
		while (dead_verif(philo->utils.time_in_ms[i], philo, i) == 0
			&& i < philo->nphilo)
			i++;
	}
	thread_join(philo);
	return (0);
}

void	*unique_philosopher2(void *void_unique)
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
