/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:09:11 by fmontero          #+#    #+#             */
/*   Updated: 2024/10/02 09:41:31 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
#include <stdio.h>
#include <stdint.h>

int			*parse(int argc, const char *argv[], int *size, int *median);
static int	*alloc_tokens(int argc, const char *argv[], int *out, int *size);
static int	total_tokens(int argc, const char *argv[]);
static int	check_format(const char *token);
static void	check(uintptr_t condition, int *tokens, char **split);

int	*parse(int argc, const char *argv[], int *size, int *median)
{
	int	*tokens;
	int	*copy;
	int	i;
	int	out_of_range;

	tokens = alloc_tokens(argc, argv, &out_of_range, size);
	copy = (int *)malloc(sizeof(int) * *size);
	ft_memcpy(copy, tokens, sizeof(int) * *size);
	ft_quicksort(copy, 0, *size - 1);
	i = 0;
	while (i < *size - 1)
	{
		if (copy[i] >= copy[i + 1])
		{
			free(copy);
			check(0, tokens, NULL);
		}
		i++;
	}
	*median = copy[(*size) / 2];
	free(copy);
	return (tokens);
}

static int	*alloc_tokens(int argc, const char *argv[], int *out, int *size)
{
	int		*tokens;
	char	**split;
	int		i;
	int		j;
	int		k;

	*size = total_tokens(argc, argv);
	tokens = malloc(sizeof(int) * (*size));
	check((uintptr_t)tokens, NULL, NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		check((uintptr_t)split, tokens, NULL);
		k = 0;
		while (split[k] != NULL)
		{
			check((uintptr_t)check_format(split[k]), tokens, split);
			tokens[j++] = ft_atoi_signal(split[k++], out);
			check((uintptr_t) !*out, tokens, split);
		}
		ft_free_split(split);
	}
	return (tokens);
}

static void	check(uintptr_t condition, int *tokens, char **split)
{
	if (condition != 0)
		return ;
	ft_free_split(split);
	free(tokens);
	write(2, "Error\n", 6);
	exit(1);
}

static int	check_format(const char *token)
{
	int	i;

	i = 0;
	if (*token == '+' || *token == '-')
		token++;
	while (ft_isdigit(token[i]) && i < 10)
		i++;
	if (token[i] == '\0')
		return (1);
	return (0);
}

static int	total_tokens(int argc, const char *argv[])
{
	int			counter;
	int			total;
	const char	*str;

	total = 0;
	while (--argc > 0)
	{
		str = (const char *)argv[argc];
		counter = 0;
		while (*str != '\0')
		{
			while (*str == ' ')
				str++;
			if (*str != '\0')
			{
				counter++;
				while (*str != ' ' && *str != '\0')
					str++;
			}
		}
		check(counter, NULL, NULL);
		total += counter;
	}
	return (total);
}
