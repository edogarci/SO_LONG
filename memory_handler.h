/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:04:45 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/04 16:07:14 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_HANDLER_H
# define MEMORY_HANDLER_H

# include "structs_definitions.h"

void	f_free_omap(t_map **o_map);
void	f_free_map(char **map);

#endif