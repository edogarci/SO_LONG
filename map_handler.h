/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:04:43 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:24 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HANDLER_H
# define MAP_HANDLER_H

# include "structs_definitions.h"

t_map	*f_create_object_map(char *map);
void	f_get_exit(char *map, int *x, int *y);
void	f_get_player(char *map, int *x, int *y);
void	f_get_map_w_h(char *map, int *w, int *h);
void	f_get_num_collect(char *map, int *amount);
void	f_get_cells(char *map, t_cell **data);
void	f_clear_omap_data(t_cell ***head);

#endif