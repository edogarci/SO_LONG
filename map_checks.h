/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:04:40 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/11 12:15:57 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECKS_H
# define MAP_CHECKS_H

# include "structs_definitions.h"

# include "include/memory_leaks.h"



int		f_check_cep_amount(char *map);
int		f_check_cell_values(char *map);
int		f_get_first_line_len(char *map);
int		f_check_is_rectangular(char *map);
int		f_check_map_integrity(char *map);
int		f_check_map_is_closed(char *map);
int		f_check_first_last_closed(char **map, int *h);
int		f_check_middle_lines_closed(char **map, int *h);
int		f_check_map_is_closed(char *map);
void	f_get_new(t_cell *curr, t_cell **new, t_cell *data, int move);
void	f_explore_paths(t_cell *curr, t_map *o_map, int *elmnts, t_cell **seen);
void	f_free_seen(t_cell **seen);
int		f_check_valid_paths(t_map *o_map);
int		f_is_move_possible(int move, t_cell *curr, t_map *o_map);
int		f_check_if_seen(t_cell *curr, t_cell **seen, int move);
void	f_add_to_seen(t_cell *curr, t_cell **seen);
void	f_check_valid_textures(t_mlx_data *data);

#endif