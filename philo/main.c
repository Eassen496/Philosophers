/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <ale-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:58:46 by ale-roux          #+#    #+#             */
/*   Updated: 2023/08/04 02:55:47 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/philo.h"

void	philo_eat_fill(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nphilo)
		philo->utils.eat[i++] = 0;
	philo->utils.all_eat = 0;
	return ;
}

void	philo_main(int argc, char **argv)
{
	t_philo	*philo;

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
	thread_create(philo, 0);
	if (philo->isdead == true)
	{
		destroy_mutex(philo);
		free(philo);
	}
}

int	main(int argc, char	**argv)
{
	if (argc < 5 || argc > 6)
		return (arg_error_0());
	if (arg_verif(argv, argc) != 0)
		return (1);
	if (ft_atoi(argv[1]) == 1)
		unique_case(argc, argv);
	else
		philo_main(argc, argv);
	return (0);
}
