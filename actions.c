/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:02:07 by mlongo            #+#    #+#             */
/*   Updated: 2023/06/13 14:32:23 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

void	died(t_philo *philo)
{
	printf("%lu %d is died\n", get_time(), philo->id);
}

void	eat(t_philo *philo)
{
	thinking(philo);
	pthread_mutex_lock(philo->r_fork);
	has_taken_a_fork(philo);
	pthread_mutex_lock(philo->l_fork);
	has_taken_a_fork(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eat_cont++;
	philo->eating = 1;
	pthread_mutex_unlock(&philo->lock);
	printf("%lu %d is eating\n", get_time(), philo->id);
	ft_usleep(philo->data->eat_time);
	philo->eating = 0;
	philo->time_to_die = get_time() + philo->data->death_time;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	has_taken_a_fork(t_philo *philo)
{
	printf("%lu %d has taken a fork\n", get_time(), philo->id);
}

void	mine_sleep(t_philo *philo)
{
	printf("%lu %d is sleeping\n", get_time(), philo->id);
	ft_usleep(philo->data->sleep_time);
}

void	thinking(t_philo *philo)
{
	printf("%lu %d is thinking\n", get_time(), philo->id);
}
