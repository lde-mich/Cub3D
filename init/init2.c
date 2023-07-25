/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:49:57 by dcastagn          #+#    #+#             */
/*   Updated: 2023/07/25 14:23:28 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_square(t_data *img, t_vectors start, int side, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < side)
	{
		x = -1;
		while (++x < side)
			my_mlx_pixel_put(img, x + start.x, y + start.y, color);
	}
}

void draw_minimap(t_game *game)
{
	int			x;
	int			y;
	t_vectors	start;

	y = -1;
	while (game->parser.map[++y])
	{
		x = -1;
		while (game->parser.map[y][++x])
		{
			start.x = x * MINIMAP_SCALE;
			start.y = y * MINIMAP_SCALE;
			if (game->parser.map[y][x] == '1')
				draw_square(&game->mini.data, start, MINIMAP_SCALE, 0x00FFFFFF);
			else
				draw_square(&game->mini.data, start, MINIMAP_SCALE, 0x00000000);
		}
	}
	start.x = (game->player.pos.x * MINIMAP_SCALE);
	start.y = (game->player.pos.y * MINIMAP_SCALE) - 2;
	draw_square(&game->mini.data, start, 5, 0x00FF0000);
}

void	init_minimap(t_game *game)
{
	game->mini.width = game->parser.mwidth * 15;
	game->mini.height = game->parser.mheight * 25;
	game->mini.x = 0;
	game->mini.y = 0;
	game->mini.data.img = mlx_new_image(game->mlx, game->mini.width,
			game->mini.height);
	game->mini.data.addr = mlx_get_data_addr(game->mini.data.img,
			&game->mini.data.bits_per_pixel, &game->mini.data.line_length,
			&game->mini.data.endian);
}

void	init_game(t_game *game)
{
	// game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "cub3d");
	game->data.img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	game->data.addr = mlx_get_data_addr(game->data.img,
			&game->data.bits_per_pixel, &game->data.line_length,
			&game->data.endian);
	init_minimap(game);
}
