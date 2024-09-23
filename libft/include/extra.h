/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:15:55 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/23 16:18:45 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
# define EXTRA_H
# include <limits.h>

void	ft_insertionsort(int arr[], int n);
void	ft_quicksort(int array[], int low, int high);
int		ft_maxint(int a, int b);
int		ft_minint(int a, int b);
int		ft_mod(int a, int b);
int		ft_atoi_signal(const char *str, int *out_of_range);
#endif
