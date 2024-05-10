/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:21:49 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/10 16:35:54 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* int monitor(t_data *table)
{
	int i;

	i = 0;
	while (i < table->nbr_philo)
	{
		if (
		i++;
	}
	return (0);
} */

/* bool	is_full(t_philo *philo)
{
	if (philo->table->nbr_philo == 1)
		return (false);
	if (philo->personal_meals >= philo->table->nbr_meals)
		return (true);
	return (false);
}*/

bool is_dead(t_philo *philo)
{
	int death_gap;
	int time;

	time = get_time() - philo->table->start_time;
	death_gap = time - philo->last_meal;
	if (death_gap >= philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->death);
		philo_print(philo, DEAD);
		philo->is_dead = true;
		pthread_mutex_unlock(&philo->table->death);
		return (true);
	}
	return (false);
}
