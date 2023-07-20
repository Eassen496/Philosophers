/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:41:09 by ale-roux          #+#    #+#             */
/*   Updated: 2023/07/20 02:00:51 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	eat_verif(t_philo *philo)
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
	if ((i == philo->nphilo - 1)
		&& (philo->utils.eat[i] == philo->utils.eat[i + 1])
		&& (philo->utils.eat[i] != philo->utils.all_eat))
		philo->utils.all_eat++;
	if (philo->utils.all_eat == philo->limit_eat)
		philo->isdead = true;
	return ;
}

int	dead_verif(long long time_in_ms, t_philo *philo, int id)
{
	if (time_in_ms + philo->time.to_die < get_ms() - philo->time.in_ms_start
		&& philo->isdead == false)
	{
		philosopher_died(philo, id);
		return (1);
	}
	return (0);
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
