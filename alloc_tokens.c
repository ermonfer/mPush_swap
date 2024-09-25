/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:09:11 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/25 13:41:13 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
#include <stdio.h>
#include <stdint.h>

static int		*alloc_tokens(int argc, const char *argv[], int *out_of_range, int *size);
static int		total_tokens(int argc, const char *argv[]);
static int		check_format(const char *token);
static void		check(uintptr_t condition, int *tokens, char **split);

int	*parse(int argc, const char *argv[], int *out_of_range, int *size)
{
	int *tokens;
	int *copy;
	int	i;

	tokens = alloc_tokens(argc, argv, out_of_range, size);
	copy = (int *)malloc(sizeof(int) * *size);
	ft_memcpy(copy, tokens, sizeof(int) * *size);
	ft_quicksort(copy, 0, *size - 1);
	i = 0;
	while (i + 1 < *size)
	{
		if (copy[i] >= copy[i + 1])
		{
			free(copy);
			check(0, tokens, NULL);	
		}
	}
	return (tokens);	
}

static int	*alloc_tokens(int argc, const char *argv[], int *out_of_range, int *size)
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
			tokens[j++] = ft_atoi_signal(split[k++], out_of_range);
			check((uintptr_t)out_of_range, tokens, split);
		}
		ft_free_split(split);
	}
	return (tokens);
}

static void	check(uintptr_t condition, int *tokens, char **split)
{
	int	i;

	if (condition != 0)
		return ;
	ft_free_split(split);
	free(tokens);
	write(1, "Error\n", 6);
	error(1);
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
	while (argc-- > 1)
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
		total += counter;
	}
	return (counter);
}

int	main(int argc, char *argv[])
{
	int	*arr;
	int out_of_range;
	int size;
	int	i;

	arr = alloc_tokens(argc, (const char **)argv, &out_of_range, &size);
	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
