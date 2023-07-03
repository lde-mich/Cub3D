/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:04:26 by lde-mich          #+#    #+#             */
/*   Updated: 2023/06/30 16:13:36 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_readmap(t_game *game, char *path)
{
	char	**mat;
	char	*l;
	int		fd;
	int		j;

	mat = (char **)malloc((game->y + 1) * sizeof(char *));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(write(1, "Error\nMap not found\n", 20));
	l = get_next_line(fd);
	game->x = ft_strlen(l) - 1;
	j = 0;
	while (l)
	{
		if (l[ft_strlen(l) - 1] == '\n')
			l[ft_strlen(l) - 1] = 0;
		mat[j] = l;
		l = get_next_line(fd);
		j++;
	}
	mat[game->y] = 0;
	close(fd);
	return (mat);
}

void	ft_map(t_game *game)
{
	int	y;
	int	j;

	game->map = (char **)malloc((game->y + 1) * sizeof(char *));
	y = 8;
	j = 0;
	while (game->readmap[y])
	{
		game->map[j] = ft_strdup(game->readmap[y]);
		j++;
		y++;
	}
	
}
