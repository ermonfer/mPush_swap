/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:50:02 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/23 18:40:29 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int argc, char *argv[])
{
	int			*arr;
	int 		i;
	t_stacks	*s;
	
	if (argc < 2)
		return (0);
	arr = malloc((argc - 1) * sizeof (int));
	i = 1;
	while (i < argc)
	{
		arr[i - 1] = atoi(argv[i]);
		i++;
	}
	s = init_stacks(arr, argc - 1);
	if (argc == 2)
		sort_2(&s->a);
	if (argc == 3)
		sort_3(&s->b);
	else
		turk(s);
	free(arr);
	free(s);
	return (0);
}
