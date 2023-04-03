/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 04:08:00 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/29 22:53:09 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

int	update(t_program *program)
{
	if (program->level == 0)
	{
		mlx_clear_window(program->mlx, program->window);
		mlx_put_image_to_window(program->mlx, program->window,
			program->start, 740, 100);
		mlx_put_image_to_window(program->mlx, program->window,
			program->campaign, 740, 400);
		mlx_put_image_to_window(program->mlx, program->window,
			program->quit, 740, 700);
		mlx_put_image_to_window(program->mlx, program->window,
			program->player, 400, 150 + (program->menu * 300));
	}
	else if (program->level > 0)
		main_game(program);
	else if (program->level == -1)
	{
		mlx_clear_window(program->mlx, program->window);
		mlx_put_image_to_window(program->mlx, program->window,
			program->game_over, 480, 240);
		mlx_string_put(program->mlx, program->window, 50, 900, 0x00888800,
			"Press Enter to continue... Esc to Quit");
	}
	return (1);
}
