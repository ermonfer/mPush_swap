/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:08:47 by fmontero          #+#    #+#             */
/*   Updated: 2024/09/18 12:40:37 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	*normalize_inputs(int argc, const char *argv[])
{
	
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