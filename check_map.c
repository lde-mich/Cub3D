/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:59:32 by lde-mich          #+#    #+#             */
/*   Updated: 2023/07/10 17:18:34 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_inidata(t_game *game)
{
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (game->readmap[y] && count <= 4)
	{
		if (game->readmap[y] && game->readmap[y][0] != 0)
		{
			count++;
			y++;
		}
		else
			y++;
	}
	game->inidata = y - 1;
}

void	ft_check_rgb(int y, t_game *game)
{
	char	**temp;
	char	**temp1;
	int		i;

	temp = ft_split(game->readmap[y], 32);
	i = -1;
	while (temp[++i])
		temp1 = ft_split(temp[i], 44);
	i = 0;
	while (temp1[i])
	{
		if (temp[0][0] == 70)
			game->f[i] = ft_atoi(temp1[i]);
		else
			game->c[i] = ft_atoi(temp1[i]);
		if (ft_atoi(temp1[i]) < 0 || ft_atoi(temp1[i]) > 255)
			exit(write(2, "Error\nRgb not supported\n", 24) * 0 + 1);
		i++;
	}
	ft_free_mat(temp);
	ft_free_mat(temp1);
}

void	ft_check_fc(t_game *game)
{
	int		x;
	int		y;
	int		count;

	ft_inidata(game);
	y = game->inidata;
	count = 0;
	while (game->readmap[y] && count < 2)
	{
		x = 0;
		while (game->readmap[y][x] == 32)
			x++;
		if (game->readmap[y][x] == 70 || game->readmap[y][x] == 67)
			ft_check_rgb(y, game);
		else
			exit(write(2, "Error\nRgb not supported\n", 24) * 0 + 1);
		y++;
		count++;
	}
}

void	ft_check_texture(t_game *game)
{
	int		x;
	int		y;
	int		count;
	char	*temp;

	y = 0;
	temp = NULL;
	count = 0;
	while (game->readmap[y] && count < 4)
	{
		x = 0;
		while (game->readmap[y][x] == 32)
			x++;
		temp = ft_substr(game->readmap[y], x, 2);
		if (ft_strncmp(temp, "NO", 2) && ft_strncmp(temp, "SO", 2)
			&& ft_strncmp(temp, "WE", 2) && ft_strncmp(temp, "EA", 2))
			exit(write(2, "Error\nTexture not supported\n", 28) * 0 + 1);
		count++;
		free(temp);
		y++;
	}
}
