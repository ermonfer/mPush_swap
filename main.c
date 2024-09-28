/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:50:02 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/28 15:59:34 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	print_arr(int arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("%d ", arr[i++]);
}

void	frees(int *arr, t_stacks *s)
{
	free(arr);
	free(s);
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
	s = init_stacks(arr, size);
	if (size == 2)
	{
		sort_2(&s->a);
		return (0);
	}
	if (size == 3)
	{
		sort_3(&s->a, &(t_ord){greater, {NULL, 0}}, 0);
		return (0);
	}
	else
		turk(s);
	frees(arr, s);
	return (0);
}
