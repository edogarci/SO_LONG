/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:04:30 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/05 19:49:36 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HANDLER_H
# define GAME_HANDLER_H

# include "structs_definitions.h"

# define XK_ESCAPE	53
# define XK_W		13
# define XK_A		0
# define XK_S		1
# define XK_D		2
# define XK_LEFT	123
# define XK_UP		126
# define XK_RIGHT	124
# define XK_DOWN	125

void	f_init_game(t_mlx_data *data, t_map *map);
void	f_get_win_size(t_map *map, int *w, int *h);
void	f_move_player(int key, t_map **map, t_mlx_data *data);
int		f_handle_input(int keysym, t_mlx_data *data);
void	f_start_game(t_map	*o_map);
void	f_put_img_in_win(t_mlx_data *data, t_cell *cell, char cell_type);
int		f_close_window(t_mlx_data *data);
void	f_set_player_xy(int *player_x, int *player_y, int key, t_map **map);
void	f_destroy_everything(t_mlx_data *data);
void	f_set_cells_new_values(t_cell *curr, t_cell *new, t_map **map);

#endif