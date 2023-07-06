/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:59:32 by lde-mich          #+#    #+#             */
/*   Updated: 2023/07/06 15:07:52 by lde-mich         ###   ########.fr       */
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

void	ft_check_rgb(t_game *game)
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
		{
			printf("giusto2\n");
		}
		else
			printf("sbagliato2\n");
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
		if (!ft_strncmp(temp, "NO", 2) || !ft_strncmp(temp, "SO", 2)
			|| !ft_strncmp(temp, "WE", 2) || !ft_strncmp(temp, "EA", 2))
			printf("giusto1\n");
		else
			printf("sbagliato1\n");
		x++;
		count++;
		free(temp);
		y++;
	}
}
