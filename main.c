/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:35:23 by dcastagn          #+#    #+#             */
/*   Updated: 2023/06/30 16:04:13 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_input(char *s)
{
	int	l;

	l = ft_strlen(s);
	if (!(s[l - 1] == 'b' && s[l - 2] == 'u' && s[l - 3]
			== 'c' && s[l - 4] == '.'))
		null_error("Map isnt in .cub format");
}

int	ft_destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(printf("The evil forces reign on\n"));
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		null_error("Inval1d input\n");
	ft_check_input(argv[1]);

	game.readmap = ft_readmap(&game, argv[1]);
	ft_map(&game);
	ft_print_mat(game.readmap);
	ft_print_mat(game.map);

	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 860, 520, "cub3d");
	mlx_hook(game.mlx_win, 17, 0, ft_destroy_window, &game);
	mlx_loop(game.mlx);
}