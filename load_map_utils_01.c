/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:06 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/12 19:25:20 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include "load_map_utils.h"
#include "error_handler.h"
#include "map_checks.h"
#include "map_handler.h"
#include "memory_handler.h"
#include "game_handler.h"
#include "structs_definitions.h"
#include "itoa.h"

/*
Read map file data into memory
*/
void	f_read_map_file(char **file_path, char **map_data, int map_size)
{
	int	fd;

	fd = open((*file_path), O_RDONLY);
	if (fd != 0)
	{
		read(fd, *map_data, map_size);
		close(fd);
	}
	else
	{
		f_show_error(4);
	}
	(*map_data)[map_size] = '\0';
}

/*
Get map size (expressed in characters)
If file can not be opened, return 0
*/
int	f_get_map_size(char **file_path)
{
	char	*temp_data;
	int		last_read;
	int		total_read;
	int		fd;

	fd = open((*file_path), O_RDONLY);
	if (fd <= 0)
		return (f_show_error(4), -1);
	temp_data = (char *)malloc(1024 * sizeof(char));
	if (temp_data == NULL)
		return (close(fd), f_show_error(5), -2);
	total_read = 0;
	last_read = 0;
	last_read = read(fd, temp_data, 1024);
	total_read = total_read + last_read;
	while (last_read > 0)
	{
		last_read = read(fd, temp_data, 1024);
		total_read = total_read + last_read;
	}
	close(fd);
	free(temp_data);
	if (total_read <= 0)
		f_show_error(6);
	return (total_read);
}

/*
Generate map file relative path
*/
void	f_fill_path(char *map_name, char *file_path)
{
	char	*path;
	int		pos1;
	int		pos2;

	path = "./maps/";
	pos1 = 0;
	while (path[pos1] != '\0')
	{
		file_path[pos1] = path[pos1];
		pos1++;
	}
	pos2 = 0;
	while (map_name[pos2] != '\0')
	{
		file_path[pos1] = map_name[pos2];
		pos2++;
		pos1++;
	}
	file_path[pos1] = '\0';
}

/*
Allocate memory to generate map file path.
*/
void	f_malloc_path(char *map_name, char **file_path)
{
	int		len;
	int		cont;
	char	*path;

	path = "./maps/";
	cont = 0;
	len = 0;
	while (map_name[cont] != '\0')
	{
		len++;
		cont++;
	}
	cont = 0;
	while (path[cont] != '\0')
	{
		len++;
		cont++;
	}
	*file_path = malloc((len + 1) * sizeof(char));
	if (*file_path == NULL)
		f_show_error(3);
}

/*
Generate relative path to map FILE
Malloc necessary memory
Read map file into memory
If map size is 0, returns NULL
If file can not be read, returns NULL
*/
char	*f_load_map_file(char *map_name)
{
	char	*file_path;
	char	*map_data;
	int		map_size;

	file_path = NULL;
	map_data = NULL;
	map_size = 0;
	f_malloc_path(map_name, &file_path);
	if (file_path == NULL)
		return (NULL);
	f_fill_path(map_name, file_path);
	map_size = f_get_map_size(&file_path);
	if (map_size <= 0)
		return (free(file_path), NULL);
	map_data = NULL;
	map_data = malloc((map_size + 1) * sizeof(char));
	if (map_data == NULL)
		return (free(file_path), f_show_error(5), NULL);
	f_read_map_file(&file_path, &map_data, map_size);
	f_clean_newlines_at_end(map_data, &map_size);
	free(file_path);
	return (map_data);
}
