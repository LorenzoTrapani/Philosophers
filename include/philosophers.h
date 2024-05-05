/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:27 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/05 17:18:54 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
//////////
//STRUCT//
//////////

typedef struct s_data
{
	int		nbr_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nbr_eat;
}	t_data;

typedef struct s_philo
{
	bool		is_dead;
	int			id;
	pthread_t	philo;
	pthread_mutex_t *fork;
	t_data		*data;
}	t_philo;

/////////////
//FUNCTIONS//
/////////////

/*INIT*/
int		ft_atoi(const char *str);
bool	syntax_check(char *str);
int	data_init(char **av, t_philo *philo);
void	philo_init(t_philo *philo);
/*ROUTINE*/
void	*routine(t_philo *philo);
int		philo_eat(t_philo *philo);

#endif