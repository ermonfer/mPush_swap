/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontero <fmontero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:26:00 by fmontero          #+#    #+#             */
/*   Updated: 2024/08/08 15:59:50 by fmontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				nb;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stacks
{
	int				capacity;
	int				a_size;
	struct s_node	*a_head;
	struct s_node	*b_head;
	struct s_node	nodes[];
}	t_stacks;