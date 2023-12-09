/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:10 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/07 13:12:10 by edogarci         ###   ########.fr       */
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

/*
Load map file (*.ber)
If it is not possible to load file, returns NULL
	map = NULL; <---
	map was not initialize
*/
char	*f_load_map(int argc, char **params)
{
	char	*map;

	map = NULL;
	if (argc == 2)
		map = f_load_map_file(params[1]);
	else
		f_show_error(2);
	return (map);
}
