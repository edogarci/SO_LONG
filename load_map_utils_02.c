/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:10 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/12 19:24:40 by edogarci         ###   ########.fr       */
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
Clean \n at end of file, it there are any
this way map will finish will 1 always
*/
void	f_clean_newlines_at_end(char *data, int *size)
{
	while (data[*size - 1] == '\n' && *size > 0)
	{
		data[*size - 1] = '\0';
		(*size)--;
	}
}

/*
check if given map name is a *.BER file
*/
int	f_is_ber_file(char *file)
{
	int	len;

	len = 0;
	while (file[len] != '\0')
		len++;
	len--;
	if (file[len - 3] != '.' || file[len - 2] != 'b'
		|| file[len - 1] != 'e' || file[len] != 'r')
		return (1);
	return (0);
}

/*
Load map file (*.ber)
If it is not possible to load file, returns NULL
*/
char	*f_load_map(int argc, char **params)
{
	char	*map;

	map = NULL;
	if (argc == 2)
	{
		if (f_is_ber_file(params[1]) == 0)
		{
			map = f_load_map_file(params[1]);
		}
		else
		{
			f_show_error(18);
		}
	}
	else
		f_show_error(2);
	return (map);
}
