/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:53:48 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/04 20:20:11 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//DATA RACE = two or more threads want to access a shared resource at the same time.
/* ac 1 = num of PHILOSOPHERS( same as forks)
ac 2 = The time a philosopher will die if he doesn’t eat
ac 3 = The time it takes a philosopher to eat
ac 4 = The time it takes a philosopher to sleep
ac 5 = OPZIONALE Number of times all the philosophers need to eat before terminating the program */

int main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	philo_init(av);
}
