/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 04:23:26 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/29 19:54:46 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	menu(int key, t_program *program)
{
	if (key == UP || key == 126)
	{
		program->menu--;
		if (program->menu < 0)
			program->menu += 3;
	}
	else if (key == DOWN || key == 125)
	{
		program->menu++;
		if (program->menu > 2)
			program->menu -= 3;
	}
	else if (key == ENTER)
	{
		if (program->menu == 0)
			program->level = 1;
		if (program->menu == 2)
			quit(program);
	}
	else if (key == KEY_ESC)
		quit(program);
}

void	game_over(int key, t_program *program)
{
	if (key == 36)
		program->level = 0;
	else if (key == KEY_ESC)
		quit(program);
}

void	commands(int key, t_program *program)
{
	if (key == UP || key == 126)
		make_move(&program->map[program->player_y][program->player_x],
			&program->map[program->player_y - 1][program->player_x], program);
	else if (key == DOWN || key == 125)
		make_move(&program->map[program->player_y][program->player_x],
			&program->map[program->player_y + 1][program->player_x], program);
	else if (key == LEFT || key == 123)
		make_move(&program->map[program->player_y][program->player_x],
			&program->map[program->player_y][program->player_x - 1], program);
	else if (key == RIGHT || key == 124)
		make_move(&program->map[program->player_y][program->player_x],
			&program->map[program->player_y][program->player_x + 1], program);
	else if (key == KEY_ESC)
		quit(program);
}

int	get_key(int key, t_program *program)
{
	if (program->level == 0)
		menu(key, program);
	else if (program->level > 0)
		commands(key, program);
	else if (program->level == -1)
		game_over(key, program);
	return (0);
}
