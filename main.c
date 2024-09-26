/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:50:02 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/26 20:48:04 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void print_arr(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("%d ", arr[i++]);
}

int	main(int argc, char *argv[])
{
	int			*arr;
	t_stacks	*s;
	int			size;
	int			out_of_range;

	if (argc < 2)
		return (0);
	arr = parse(argc, (const char **)argv, &out_of_range, &size);
	print_arr(arr, size);
	s = init_stacks(arr, size);
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
