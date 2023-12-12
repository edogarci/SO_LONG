/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:04:25 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/04 16:04:26 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include "include/memory_leaks.h"

void	f_show_error(int msg);
void	f_show_error_continued(int msg);
void	f_print_msg(char *msg);

#endif