/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:50:45 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/14 17:17:26 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (mutex_int_value(&philo->table->end, &philo->table->is_ended) == 0)
	{
		philo_eat(philo);
		if (philo->table->nbr_philo == 1)
			break ;
		philo_sleep(philo);
		philo_think(philo);
		if (philo->personal_meals >= philo->table->nbr_meals && mutex_int_value(&philo->status, (int *)&philo->table->count_meals) != 0)
			break ;
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->r_fork]);
	philo_print(philo, FORK);
	if (philo->table->nbr_philo == 1)
	{
		pthread_mutex_unlock(&philo->table->fork[philo->r_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->table->fork[philo->l_fork]);
	philo_print(philo, FORK);
	philo_print(philo, EAT);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_lock(&philo->status);
	philo->last_meal = get_time();
	philo->personal_meals++;
	pthread_mutex_unlock(&philo->status);
	pthread_mutex_unlock(&philo->table->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->l_fork]);
}

void philo_print(t_philo *philo, char *action)
{
	unsigned long time;

	time = get_time();
	pthread_mutex_lock(&philo->table->print);
	if ((mutex_int_value(&philo->table->end, &philo->table->is_ended) == 0) || action[0] == 'd')
	{
		printf("%s", CYAN);
		printf("%lu ", time - philo->table->start_time);
		printf("%s", GREEN);
		printf("%d ", philo->id);
		printf("%s", RESET);
		printf("%s", action);
	}
	pthread_mutex_unlock(&philo->table->print);
}

void philo_sleep(t_philo *philo)
{
	philo_print(philo, SLEEP);
	ft_usleep(philo->table->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	philo_print(philo, THINK);
}
