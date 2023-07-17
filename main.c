/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:35:23 by dcastagn          #+#    #+#             */
/*   Updated: 2023/07/17 16:25:52 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_input(char *s)
{
	int	l;

	l = ft_strlen(s);
	if (!(s[l - 1] == 'b' && s[l - 2] == 'u' && s[l - 3]
			== 'c' && s[l - 4] == '.'))
		exit(write(2, "Error: Map isnt in .cub format\n", 24));
}

int	ft_destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(write(2, "Error: The evil forces reign on\n", 25));
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_parser	parser;

	parser.map = NULL;
	parser.readmap = NULL;
	if (argc != 2)
		exit(write(2, "Error: Inval1d input\n", 21));
	ft_check_input(argv[1]);

	ft_check_size(&parser, argv[1]);
	parser.readmap = ft_readmap(&parser, argv[1]);
	ft_map(&parser);
	ft_size_map(&parser);
	ft_check_fc(&parser);
	ft_check_texture(&parser);
	ft_check_lmap(&parser);
	ft_check_map(&parser);
	ft_check_symbol_map(&parser);

	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 860, 520, "cub3d");
	mlx_hook(game.mlx_win, 17, 0, ft_destroy_window, &game);
	mlx_loop(game.mlx);
}