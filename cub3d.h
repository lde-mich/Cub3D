/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:39:41 by dcastagn          #+#    #+#             */
/*   Updated: 2023/06/30 15:58:44 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx-linux/mlx.h"
# include "libft/libft.h"
# include "errors/errors.h"
# include "gnl/gnl.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>

// GAME

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**readmap;
	char	**map;
	int		x;
	int		y;

}		t_game;

//temp

char	**ft_readmap(t_game *game, char *path);
void	ft_print_mat(char **mat);
void	ft_check_texture(t_game *game);
void	ft_map(t_game *game);

#endif