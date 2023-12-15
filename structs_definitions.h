/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_definitions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:04:47 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:31 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_DEFINITIONS_H
# define STRUCTS_DEFINITIONS_H

typedef struct s_cell
{
	int				x;
	int				y;
	char			status;
	struct s_cell	*next;
}	t_cell;

typedef struct s_map
{
	int				num_collect;
	int				map_w;
	int				map_h;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	struct s_cell	*data;
}	t_map;

typedef struct s_mlx_data
{
	void	*conn;
	void	*win;
	int		win_w;
	int		win_h;
	int		moves_count;
	t_map	**map;
}	t_mlx_data;

#endif