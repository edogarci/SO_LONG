/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:04:38 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:17 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_MAP_UTILS_H
# define LOAD_MAP_UTILS_H

void	f_read_map_file(char **file_path, char **map_data, int map_size);
int		f_get_map_size(char **file_path);
void	f_fill_path(char *map_name, char *file_path);
void	f_malloc_path(char *map_name, char **file_path);
char	*f_load_map_file(char *map_name);
char	*f_load_map(int argc, char **params);
int		f_is_ber_file(char *file);
void	f_clean_newlines_at_end(char *data, int *size);

#endif