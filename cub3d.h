/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:39:41 by dcastagn          #+#    #+#             */
/*   Updated: 2023/07/17 12:05:41 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>

// GAME

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;

}		t_game;

//PARSER

typedef struct parser
{
	char	**readmap;
	char	**map;
	int		inimap;
	int		inidata;
	int		x;
	int		y;
	int		mwidth;
	int		mheight;
	int		f[3];
	int		c[3];

}		t_parser;

//TEMP

char	**ft_readmap(t_parser *parser, char *path);
void	ft_map(t_parser *parser);
void	ft_print_mat(char **mat);
void	ft_free_mat(char **mat);
void	ft_free_err(t_parser *parser, char *s);
void	ft_inimap(t_parser *parser);
void	ft_inidata(t_parser *parser);
void	ft_size_map(t_parser *parser);
void	ft_check_texture(t_parser *parser);
void	ft_check_size(t_parser *parser, char *path);
void	ft_check_fc(t_parser *parser);
void	ft_check_map(t_parser *parser);
void	ft_check_lmap(t_parser *parser);
void	ft_check_symbol_map(t_parser *parser);
void	ft_check_rgb(int y, t_parser *parser);

#endif