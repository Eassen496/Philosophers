/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:38:57 by ale-roux          #+#    #+#             */
/*   Updated: 2023/08/04 03:07:24 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	philosopher_thinking(t_philo *philo, int id)
{
	long long	time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == false)
		talk(philo, id, time_in_ms, 0);
	return ;
}

void	talk(t_philo *philo, int id, long long time_in_ms, int action)
{
	pthread_mutex_lock(&philo->utils.talk);
	if (philo->isdead == false)
	{
		if (action == 0)
			printf("%lld %d is thinking\n", time_in_ms, id);
		else if (action == 1)
			printf("%lld %d has taken a fork\n", time_in_ms, id);
		else if (action == 2)
			printf("%lld %d is eating\n", time_in_ms, id);
		else if (action == 3)
			printf("%lld %d is sleeping\n", time_in_ms, id);
		else if (action == 4)
			printf("%lld %d died\n", time_in_ms, id);
	}
	pthread_mutex_unlock(&philo->utils.talk);
}

void	philosopher_eating(t_philo *philo, int id)
{
	pthread_mutex_lock(&philo->utils.mutex[id]);
	talk(philo, id, get_ms() - philo->time.in_ms_start, 1);
	if (id == philo->nphilo)
		pthread_mutex_lock(&philo->utils.mutex[1]);
	else
		pthread_mutex_lock(&philo->utils.mutex[id + 1]);
	philo->utils.time_in_ms[id] = get_ms() - philo->time.in_ms_start;
	talk(philo, id, philo->utils.time_in_ms[id], 1);
	talk(philo, id, philo->utils.time_in_ms[id], 2);
	while (philo->utils.time_in_ms[id] + philo->time.to_eat
		> get_ms() - philo->time.in_ms_start)
		usleep(10);
	philo_unlock(philo, id, true);
	philo->utils.eat[id]++;
	return ;
}

void	philosopher_sleeping(t_philo *philo, int id, long long last)
{
	long long	time_in_ms;

	time_in_ms = get_ms() - philo->time.in_ms_start;
	if (philo->isdead == true)
		return ;
	talk(philo, id, time_in_ms, 3);
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
		talk(philo, id, time_in_ms, 4);
	pthread_mutex_lock(&philo->utils.die);
	philo->isdead = true;
	pthread_mutex_unlock(&philo->utils.die);
	return ;
}
