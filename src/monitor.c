/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:21:49 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/09 13:26:39 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* int monitor(t_data *table)
{} */

bool	is_full(t_data *table)
{
	int i;

	i = 0;
	while (i < table->nbr_philo)
	{
		if (table->nbr_meals != table->philo[i].personal_meals)
			return (false);
		else
			return (true);
		i++;
	}
	return (false);
}
