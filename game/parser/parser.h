/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:30:20 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/03 20:38:35 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "../core/cub3D.h"

int		upd_pars(int type, char *component, t_pars *params);
int		map_solve(int fd, char *last_line, t_pars *params);
int		error_nswes_malloc(t_pars *params);
int		error_get_pars(char **line, int fd);
int		error_reading_file(char **line, int fd, t_pars *params);
int		error_invalid_params(t_pars *params);
int		error_r_par_not_correct(char *line);
int		error_color_par_not_correct(char *line, t_pars *params);
int		free_struct(t_pars *params);

#endif