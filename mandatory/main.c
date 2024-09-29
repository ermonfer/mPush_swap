/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:50:02 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/29 19:32:16 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	main(int argc, char *argv[])
{
	int			*arr;
	t_stacks	*s;
	int			median;
	int			size;

	if (argc < 2)
		return (0);
	arr = parse(argc, (const char **)argv, &size, &median);
	s = init_stacks(arr, size);
	if (size == 2)
		sort_2(&s->a);
	else if (size == 3)
		sort_3(&s->a, &(t_ord){greater, {NULL, 0}}, 0);
	else
		turk(s, median, size);
	free(arr);
	free(s);
	return (0);
}
