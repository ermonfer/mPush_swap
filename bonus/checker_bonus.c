/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:43:33 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/30 11:24:34 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"

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
	free(arr);
	while (true)
	{
		mov = ft_get_next_line(0);
		if (mov == NULL)
			break ;
		exec_mov(s, mov);
	}
	if (stack_sorted(s, &(t_ord){greater, NULL}, false))
		write(1, (char[]){'O', 'K', '\0'}, 2);
	else
		write(1, (char[]){'K', 'O', '\0'}, 2);
	free(s);
	return (0);
}

void	exec_mov(t_stacks *s, char *mov)
{
	if (ft_strncmp(s, "pa\n", 4))
		push(&s->b, &s->a, false);
	else if (ft_strncmp(s, "pb\n", 4))
		push(&s->a, &s->b, false);
	else if (ft_strncmp(s, "ra\n", 4))
		rot(&s->a, true);
}
