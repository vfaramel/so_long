/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:11:06 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/29 19:57:41 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_tile(char *map, t_program *program)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P'
			&& map[i] != 'C' && map[i] != 'E' && map[i] != '\n')
			error(program);
		i++;
	}
}

void	check_map(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->width)
	{
		if (program->map[0][i] != '1'
		|| program->map[program->height - 1][i] != '1')
			error(program);
		i++;
	}
	i = 0;
	while (i < program->height)
	{
		if (program->map[i][0] != '1'
		|| program->map[i][program->width - 1] != '1'
		|| (int)ft_strlen(program->map[i]) != program->width)
			error(program);
		i++;
	}
}

void	width_height(t_program *program)

{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (program->map[0][i] != '\0')
		i++;
	program->width = i;
	while (program->map[n] != 0)
		n++;
	program->height = n;
}

void	open_map(t_program *program, char *ber)
{
	int		fd;
	char	*arr;

	program->o_map = malloc(1);
	*program->o_map = '\0';
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		error(program);
	arr = get_next_line(fd);
	while (arr != 0)
	{
		program->o_map = ft_strjoin(program->o_map, arr);
		arr = get_next_line(fd);
	}
	program->map = ft_split(program->o_map, '\n');
	width_height(program);
	free(arr);
	close(fd);
	check_map(program);
}
