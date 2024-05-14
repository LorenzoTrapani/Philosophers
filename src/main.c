/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:53:48 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/14 22:07:08 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_data	table;

	table = (t_data){0};
	if (ac == 6)
		table.count_meals = true;
	if (ac != 5 && ac != 6)
		return (1);
	if (data_init(av, &table) == 1)
		return (1);
	if (philo_init(&table) == 1)
		return (1);
	mutex_destroy(&table);
	return (0);
}
