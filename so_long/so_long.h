/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:19:28 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/29 22:53:24 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

# define UP		13
# define DOWN		1
# define LEFT		0
# define RIGHT		2
# define ENTER		36
# define KEY_ESC	53

typedef struct s_program {
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	int		moves;
	int		time;
	int		frame;
	int		menu;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*enemy;
	void	*start;
	void	*quit;
	void	*campaign;
	void	*game_over;
	void	*spark[3];
	int		sparks;
	void	*player;
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	char	**map;
	char	*o_map;
	int		level;
}				t_program;

void	write_moves(t_program *program);
void	open_map(t_program *program, char *ber);
int		update(t_program *program);
int		get_key(int key, t_program *program);
void	get_images(t_program *program);
void	error(t_program *program);
void	refresh_map(t_program *program);
int		quit(t_program *program);
void	width_height(t_program *program);
void	make_move(char *current, char *next, t_program *program);
void	enemy_move(t_program *program);
void	main_game(t_program *program);

#endif
