/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:27 by lotrapan          #+#    #+#             */
/*   Updated: 2024/05/08 16:45:09 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

//////////
//STRUCT//
//////////
typedef struct s_philo	t_philo;
typedef struct s_data
{
	int		nbr_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nbr_meals;
	struct s_philo *philo;
	pthread_mutex_t *fork;
	pthread_mutex_t print;
	bool		is_dead;
}	t_data;

struct s_philo
{
	int			id;
	int 		r_fork;
	int			l_fork;
	pthread_t	philo;
	t_data		*table;
};

/////////////
//FUNCTIONS//
/////////////

/*INIT*/
int		ft_atoi(const char *str);
bool	syntax_check(char *str);
int		data_init(char **av, t_data *data);
int		philo_init(t_data *data);
/*ROUTINE*/
void	*routine(t_philo *philo);
int		philo_print(t_philo *philo, int action);
int		philo_eat(t_philo *philo);
/*MUTEX*/
int		mutex_init(t_data *table);
void	mutex_destroy(t_data *table);

#endif