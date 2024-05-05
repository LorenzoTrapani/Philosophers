/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:50:45 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/05 17:20:09 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	printf("philo is eating\n");
	pthread_mutex_unlock(philo->fork);
	return (0);
}

/* int philo_sleep(t_philo *philo)
{

}

int	philo_think(t_philo *philo)
{

} */

void *routine(t_philo *philo)
{
	philo_eat(philo);
	/* philo_sleep(philo);
	philo_think(philo); */
	return (NULL);
}