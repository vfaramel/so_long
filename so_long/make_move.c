/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:45:11 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/29 19:49:30 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_move2(char *current, char *next, t_program *program)
{
	if (*next == 'E' && program->sparks == 0)
	{
		refresh_map(program);
		program->level = 0;
	}
	else if ((*next == 'P' && *current == 'V')
		|| (*next == 'V' && *current == 'P'))
	{
		refresh_map(program);
		program->level = -1;
	}
	else if (*next == 'P')
		update(program);
}

void	make_move(char *current, char *next, t_program *program)
{
	if (*next == '0')
	{
		*next = *current;
		*current = '0';
		if (*next == 'P')
			program->moves++;
	}
	else if (*next == 'C')
	{
		*next = *current;
		*current = '0';
		if (*next == 'P')
			program->moves++;
	}
	else
		make_move2(current, next, program);
}
