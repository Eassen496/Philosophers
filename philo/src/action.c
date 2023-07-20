/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:38:57 by ale-roux          #+#    #+#             */
/*   Updated: 2023/07/20 02:00:24 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	philosopher_thinking(t_philo *philo, int id)
{
	long long	time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == false)
		printf("%lld %d is thinking\n", time_in_ms, id);
	return ;
}

int	philosopher_eating(t_philo *philo, int id, long long last)
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
	if (last + philo->time.to_die < get_ms() - philo->time.in_ms_start
		&& philo->isdead == false)
		philosopher_died(philo, id);
	while (time_in_ms + philo->time.to_eat > get_ms() - philo->time.in_ms_start)
		usleep(10);
	philo_unlock(philo, id, true);
	philo->utils.eat[id]++;
	return (time_in_ms);
}

void	philosopher_sleeping(t_philo *philo, int id, long long last)
{
	long long	time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == true)
		return ;
	printf("%lld %d is sleeping\n", time_in_ms, id);
	time_in_ms += (long long)philo->time.to_sleep;
	while (time_in_ms > get_ms() - philo->time.in_ms_start)
	{
		if (dead_verif(last, philo, id) == 1)
			break ;
		usleep(100);
	}
	return ;
}

void	philosopher_died(t_philo *philo, int id)
{
	long long	time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == false)
		printf("%lld %d died\n", time_in_ms, id);
	philo->isdead = true;
	return ;
}
