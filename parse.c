/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:08:47 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/19 09:56:54 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static int	tokens_count(int argc, const char *argv[]);
static int	check_token_format(const char *token);

int	*normalize_inputs(int argc, const char *argv[])
{
	
}

static int	check_token_format(const char *token)
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

static int	tokens_count(int argc, const char *argv[])
{
	int			counter;
	const char	*s;

	counter = 0;
	while(argc-- > 0)
	{
		s = argv[argc];
		while (*s != '\0')
		{
			while (*s == ' ')
				s++;
			if (*s != '\0')
			{
				counter++;
				while (*s != ' ' && *s != '\0')
					s++;
			}
		}
	}
	return (counter);
}