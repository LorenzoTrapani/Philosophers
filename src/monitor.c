/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:21:49 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/14 22:06:22 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int monitor(t_data *table)
{
	int i;

	while (mutex_int_value(&table->end, &table->is_ended) == 0)
	{
		i = 0;
		if (table->count_meals && is_full(table))
			return (1);
		while (i < table->nbr_philo)
		{
			if (is_dead(&table->philo[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

bool is_dead(t_philo *philo)
{
	long int death_gap;
	long int time;
	
	time = get_time() - philo->table->start_time;
	death_gap = time - mutex_ulong_value(&philo->status, &philo->last_meal);
	if (death_gap > philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->end);
		philo->table->is_ended = true;
		pthread_mutex_unlock(&philo->table->end);
		philo_print(philo, DEAD);
		return (true);
	}
	return (false);
}

bool	is_full(t_data *table)
{
	int i;
	int meals_counter;

	i = 0;
	meals_counter = 0;
	while (i < table->nbr_philo)
	{
		if (mutex_int_value(&table->philo[i].status, &table->philo[i].personal_meals) >= table->nbr_meals)
		{
			meals_counter++;
			if (meals_counter == table->nbr_philo)
			{
				pthread_mutex_lock(&table->end);
				table->is_ended = true;
				pthread_mutex_unlock(&table->end);
				return (true);
			}
		}
		i++;
	}
	return (false);
}
