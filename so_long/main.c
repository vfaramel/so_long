/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:19:40 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/29 22:31:22 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_moves(t_program *program)
{
	char	*moves;

	moves = ft_itoa(program->moves);
	mlx_string_put(program->mlx, program->window, 50, 50, 0x00888800, moves);
	free(moves);
}

void	error(t_program *program)
{
	write(1, "Error\n", 6);
	quit(program);
}

void	refresh_map(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->height)
		free(program->map[i++]);
	free(program->map);
	program->map = ft_split(program->o_map, '\n');
	program->moves = 0;
}

int	quit(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->height)
		free(program->map[i++]);
	free(program->map);
	free(program->o_map);
	free(program);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_program	*program;

	(void)argc;
	program = ft_calloc(1, sizeof(t_program));
	open_map(program, argv[1]);
	program->mlx = mlx_init();
	program->window = mlx_new_window(program->mlx, 1980, 1080, "Hello world!");
	get_images(program);
	mlx_key_hook(program->window, get_key, program);
	mlx_loop_hook(program->mlx, update, program);
	mlx_hook(program->window, 17, 0, quit, program);
	mlx_loop(program->mlx);
}
