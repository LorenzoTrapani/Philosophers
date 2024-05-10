/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:21:49 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/10 22:35:44 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int monitor(t_data *table)
{
	int i;

	i = 0;
	if (is_full(table))
		return (1);
	while (i < table->nbr_philo)
	{
		if (is_dead(&table->philo[i]))
			return (1);
		i++;
	}
	return (0);
}

bool is_dead(t_philo *philo)
{
	int death_gap;
	int time;

	time = get_time() - philo->table->start_time;
	death_gap = time - philo->last_meal;
	if (death_gap >= philo->table->time_to_die)
	{
		
		pthread_mutex_lock(&philo->table->death);
		philo->is_dead = true;
		philo->table->is_ended = true;
		pthread_mutex_unlock(&philo->table->death);
		philo_print(philo, DEAD);
		return (true);
	}
	return (false);
}

bool	is_full(t_data *table)
{
	int i;

	i = 0;
	while (i < table->nbr_philo)
	{
		if (table->philo[i].personal_meals >= table->nbr_meals)
		{
			i = 0;
			while (i < table->nbr_philo && (table->philo[i + 1].personal_meals >= table->nbr_meals))
			{
				i++;
				if (table->philo[i].id == table->nbr_philo)
				{
					pthread_mutex_lock(&table->death);
					table->is_ended = true;
					pthread_mutex_unlock(&table->death);
					return (true);
				}
			}
			break;
		}
		i++;
	}
	return (false);
}
