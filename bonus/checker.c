/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:12:57 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/29 21:47:56 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap_bonus.h>

void	exec_mov(t_stacks *s, char *mov);

int	main(int argc, char *argv[])
{
	int			*arr;
	t_stacks	*s;
	int			median;
	int			size;
	char		*mov;

	if (argc < 2)
		return (0);
	arr = parse(argc, (const char **)argv, &size, &median);
	s = init_stacks(arr, size);
	exec_mov(s, mov);	
	free(arr);
	free(s);
	return (0);
}
