/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:30:20 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/12 14:09:26 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../core/cub3d.h"

int		upd_pars(int type, char *component, t_pars *params);
int		get_map(int fd, char *last_line, t_pars *params);
int		error_wrong_filename();
int		error_open_file();
int		error_invalid_file(t_pars *params);
int		error_nswes_malloc(t_pars *params, int error);
int		error_get_pars(char **line, int fd);
int		error_read_file_pars(int fd, t_pars *params);
int		error_invalid_params(t_pars *params);
int		error_r_par_not_correct(char *line);
int		error_color_par_not_correct(char *line, t_pars *params);
int		error_malloc_tmpdup(char **line, t_list **map);
int		error_get_lines(t_pars *params);
int		error_get_map(char **line, int fd, int error);
int		error_malloc_tmplst(char **line, char **tmpdup, t_list **map);
int		error_read_file_get_lines(int fd, t_list **map);
int		error_malloc_tmplastl(void);
int		error_malloc_map(char **tmplastl);
int		error_malloc_ltm_map(t_list **map);
int		error_malloc_ltm_mindex(t_list **map, t_pars *params);
int		error_not_valid_map(t_pars *params);
int		check_color_valid(t_pars *params, int type);
int		error_in_params(t_pars *params);
int		free_struct(t_pars *params);

#endif
