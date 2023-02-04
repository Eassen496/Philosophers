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

t_philo	fill_struct(char **argv, int opt)
{
	t_philo philo;

	philo = malloc(sizeof(t_philo));
	philo.nphilo = atoi(argv[1]);
	philo.ttd = atoi(argv[2]);
	philo.tte = atoi(argv[3]);
	philo.tts = atoi(argv[4]);
	if (opt == 1)
		philo.eat = atoi(argv[5]);
	else
		philo.eat = 0;	
	return (philo);
}

void	philosopher(char **argv, int opt)
{
	t_philo	philo;
	int		eat;

	philo = fill_struct(argv, opt);
}

void	arg_error(void)
{
	printf("need 5 arguments\n");
	printf("You need to put all arguments :\n");
	printf("./philo <time_to_death> <time_to_eat> <time_to_sleep> <eat> (optional)");
}

int	main(int argc, char	**argv)
{
	if (argc == 5 || argc == 6)
	{
		philosopher(argv, argv - 5)
	}
	else
		arg_error();
	return (0);
}
