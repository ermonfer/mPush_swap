/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:43:33 by fmontero          #+#    #+#             */
/*   Updated: 2024/10/01 18:32:34 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_bonus.h"
#include <stdio.h>

static bool	exec_rot(t_stacks *s, const char *mov);
static bool	exec_p_s(t_stacks *s, const char *mov);
static bool	exec_mov(t_stacks *s, const char *mov);

int	main(int argc, char *argv[])
{
	int			*arr;
	t_stacks	*s;
	int			sz;
	char		*mov;

	if (argc < 2)
		return (0);
	arr = parse(argc, (const char **)argv, &sz);
	s = init_stacks(arr, sz);
	mov = ft_get_next_line(0);
	while (mov)
	{
		if (!exec_mov(s, mov))
		{
			write(2, "Error\n", 6);
			return (free(s), free(mov), 1);
		}
		free(mov);
		mov = ft_get_next_line(0);
	}
	if (s->a.size == sz && stack_sorted(&s->a, &(t_ord){greater, {NULL, 0}}, 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free(arr), free(s), 0);
}

static bool	exec_mov(t_stacks *s, const char *mov)
{
	return (exec_rot(s, mov) || exec_p_s(s, mov));
}

static bool	exec_rot(t_stacks *s, const char *mov)
{
	if (!ft_strncmp(mov, "ra\n", 4))
		return (rot(&s->a, false), true);
	else if (!ft_strncmp(mov, "rb\n", 4))
		return (rot(&s->b, false), true);
	else if (!ft_strncmp(mov, "rr\n", 4))
	{
		rot(&s->a, false);
		return (rot(&s->b, false), true);
	}
	else if (!ft_strncmp(mov, "rra\n", 5))
		return (rev(&s->a, false), true);
	else if (!ft_strncmp(mov, "rrb\n", 5))
		return (rev(&s->b, false), true);
	else if (!ft_strncmp(mov, "rrr\n", 5))
	{
		rev(&s->a, false);
		return (rev(&s->b, false), true);
	}
	return (false);
}

static bool	exec_p_s(t_stacks *s, const char *mov)
{
	if (!ft_strncmp(mov, "pa\n", 4))
		return (push(&s->b, &s->a, false), true);
	else if (!ft_strncmp(mov, "pb\n", 4))
		return (push(&s->a, &s->b, false), true);
	else if (!ft_strncmp(mov, "sa\n", 4))
		return (swap(&s->a, false), true);
	else if (!ft_strncmp(mov, "sb\n", 4))
		return (swap(&s->b, false), true);
	else if (!ft_strncmp(mov, "ss\n", 4))
	{
		swap(&s->a, false);
		return (swap(&s->b, false), true);
	}
	return (false);
}
