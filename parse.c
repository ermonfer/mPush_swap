/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:08:47 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/23 21:46:34 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static int		count_tokens(char *str);
static int		total_tokens(int argc, const char *argv[]);
static int		check_format(const char *token);
static void		free_or_continue(void *condition, int *tokens, char **split);

int	*alloc_tokens(int argc, const char *argv[], int *out_of_range)
{
	int		*tokens;
	char	**split;
	int		i;
	int		j;
	int		k;

	tokens = malloc(sizeof(int) * total_tokens(argc, argv));
	free_or_continue(tokens, NULL, NULL);
	i = 1;
	j = 0;
	while (i++ < argc)
	{
		split = ft_split(argv[i], ' ');
		free_or_continue((void *)split, tokens, NULL);
		k = 0;
		while (split[k] != NULL)
		{
			free_or_continue((void *)check_format(split[k++]), tokens, split);
			tokens[j++] = ft_atoi_signal(*split, out_of_range);
			free_or_continue((void *)out_of_range, tokens, split);
		}
		free(split);
	}
	return (tokens);
}

static void	free_or_continue(void *condition, int *tokens, char **split)
{
	int	i;

	if (condition != 0)
		return ;
	while (split[i] != NULL)
		free(split[i]);
	free(split);
	free(tokens);
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

static int	count_tokens(char *str)
{
	int			counter;

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
	return (counter);
}

static int	total_tokens(int argc, const char *argv[])
{
	int			counter;
	const char	*s;

	counter = 0;
	while (argc-- > 0)
		counter += tokens_count(argv[argc]);
	return (counter);
}
