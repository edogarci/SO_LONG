/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:57:46 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/07 13:16:15 by edogarci         ###   ########.fr       */
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
Game's main function :)
*/
int	main(int argc, char *argv[])
{
	char	*map;
	t_map	*o_map;

	map = f_load_map(argc, argv);
	if (map == NULL)
		return (f_show_error (1), 0);
	printf("2\n");
	if (f_check_map_integrity(map) != 1)
	{
		printf("1\n");
		o_map = f_create_object_map(map);
		f_free_map(&map);
		if (o_map == NULL)
			f_show_error (1);
		else
			if (f_check_valid_paths(o_map) == 0)
				f_start_game(o_map);
	}
	f_free_omap(&o_map);
	f_free_map(&map);
	return (0);
}
