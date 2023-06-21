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

int	main(int argc, char	**argv)
{
	if (argc < 5 || argc > 6)
		return (arg_error_0());
	if (arg_verif(argv, argc) != 0)
		return (1);
	if (ft_atoi(argv[1]) == 1)
		return (unique_case(argc, argv));
    philo_main(argc, argv);
	return (0);
}
