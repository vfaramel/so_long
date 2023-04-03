/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:03:40 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/29 22:36:38 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images2(t_program *program)
{
	int	x;
	int	y;

	program->start = mlx_xpm_file_to_image(program->mlx,
			"sprites/start.xpm", &x, &y);
	program->quit = mlx_xpm_file_to_image(program->mlx,
			"sprites/quit.xpm", &x, &y);
	program->game_over = mlx_xpm_file_to_image(program->mlx,
			"sprites/game_over.xpm", &x, &y);
	program->campaign = mlx_xpm_file_to_image(program->mlx,
			"sprites/campaign.xpm", &x, &y);
}

void	get_images(t_program *program)
{
	int			x;
	int			y;

	program->wall = mlx_xpm_file_to_image(program->mlx,
			"sprites/dark.xpm", &x, &y);
	program->floor = mlx_xpm_file_to_image(program->mlx,
			"sprites/floor.xpm", &x, &y);
	program->player = mlx_xpm_file_to_image(program->mlx,
			"sprites/player.xpm", &x, &y);
	program->exit = mlx_xpm_file_to_image(program->mlx,
			"sprites/exit.xpm", &x, &y);
	program->enemy = mlx_xpm_file_to_image(program->mlx,
			"sprites/enemy.xpm", &x, &y);
	program->spark[0] = mlx_xpm_file_to_image(program->mlx,
			"sprites/spark.xpm", &x, &y);
	program->spark[1] = mlx_xpm_file_to_image(program->mlx,
			"sprites/spark1.xpm", &x, &y);
	program->spark[2] = mlx_xpm_file_to_image(program->mlx,
			"sprites/spark2.xpm", &x, &y);
	get_images2(program);
}

int	move_is_possible(t_program *program, int y, int x)
{
	if (program->map[y][x] != '1'
		&& program->map[y][x] != 'C'
		&& program->map[y][x] != 'E')
		return (1);
	if (program->map[y][x] == 'P')
		quit(program);
	return (0);
}

void	enemy_move(t_program *program)
{
	if (program->enemy_x > program->player_x
		&& move_is_possible(program, program->enemy_y, program->enemy_x - 1))
		make_move(&program->map[program->enemy_y][program->enemy_x],
			&program->map[program->enemy_y][program->enemy_x - 1], program);
	else if (program->enemy_x < program->player_x
		&& move_is_possible(program, program->enemy_y, program->enemy_x + 1))
		make_move(&program->map[program->enemy_y][program->enemy_x],
			&program->map[program->enemy_y][program->enemy_x + 1], program);
	else if (program->enemy_y < program->player_y
		&& move_is_possible(program, program->enemy_y + 1, program->enemy_x))
		make_move(&program->map[program->enemy_y][program->enemy_x],
			&program->map[program->enemy_y + 1][program->enemy_x], program);
	else if (program->enemy_y > program->player_y
		&& move_is_possible(program, program->enemy_y - 1, program->enemy_x))
		make_move(&program->map[program->enemy_y][program->enemy_x],
			&program->map[program->enemy_y - 1][program->enemy_x], program);
}
