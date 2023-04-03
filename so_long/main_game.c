/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:39:03 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/29 22:52:30 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_10e(int x, int y, t_program *program)
{
	if (program->map[y][x] == '1')
		mlx_put_image_to_window(program->mlx, program->window,
			program->wall, ((1980 - (program->width * 64)) / 2)
			+ x * 64, ((1080 - (program->height * 64)) / 2) + y * 64);
	if (program->map[y][x] == '0')
		mlx_put_image_to_window(program->mlx, program->window,
			program->floor, ((1980 - (program->width * 64)) / 2)
			+ x * 64, ((1080 - (program->height * 64)) / 2) + y * 64);
	if (program->map[y][x] == 'E')
		mlx_put_image_to_window(program->mlx, program->window,
			program->exit, ((1980 - (program->width * 64)) / 2)
			+ x * 64, ((1080 - (program->height * 64)) / 2) + y * 64);
	if (program->map[y][x] == 'V')
	{
		mlx_put_image_to_window(program->mlx, program->window,
			program->floor, ((1980 - (program->width * 64)) / 2)
			+ x * 64, ((1080 - (program->height * 64)) / 2) + y * 64);
		mlx_put_image_to_window(program->mlx, program->window,
			program->enemy, ((1980 - (program->width * 64)) / 2)
			+ x * 64, ((1080 - (program->height * 64)) / 2) + y * 64);
		program->enemy_x = x;
		program->enemy_y = y;
	}
}

int	update_cp(int x, int y, t_program *program)
{
	if (program->map[y][x] == 'P')
	{
		mlx_put_image_to_window(program->mlx, program->window,
			program->floor, ((1980 - (program->width * 64)) / 2)
			+ x * 64, ((1080 - (program->height * 64)) / 2) + y * 64);
		mlx_put_image_to_window(program->mlx, program->window,
			program->player, ((1980 - (program->width * 64)) / 2)
			+ x * 64, ((1080 - (program->height * 64)) / 2) + y * 64);
		program->player_x = x;
		program->player_y = y;
	}
	if (program->map[y][x] == 'C')
	{
		mlx_put_image_to_window(program->mlx, program->window,
			program->floor, ((1980 - (program->width * 64)) / 2)
			+ x * 64, ((1080 - (program->height * 64)) / 2) + y * 64);
		mlx_put_image_to_window(program->mlx, program->window,
			program->spark[program->frame], ((1980 - (program->width
						* 64)) / 2) + x * 64, ((1080 - (program->height
						* 64)) / 2) + y * 64);
		return (1);
	}
	return (0);
}

void	animations(t_program *program, int s)
{
	if (program->time % 20 == 0)
		enemy_move(program);
	if (program->time++ > 900)
		program->time -= 900;
	program->frame = program->time / 10 % 3;
	program->sparks = s;
}

void	main_game(t_program *program)
{
	int	y;
	int	x;
	int	s;

	y = 0;
	x = 0;
	s = 0;
	mlx_clear_window(program->mlx, program->window);
	write_moves(program);
	while (y < program->height)
	{
		x = 0;
		while (x < program->width)
		{
			update_10e(x, y, program);
			s += update_cp(x, y, program);
			x++;
		}
		y++;
	}
	animations(program, s);
}
