/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:04:42 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/06 19:13:53 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static	int		check(char *line, int pos, int mod)
{
	static int	player;
	const int	len = ft_strlen(line);

	if (mod == 1)
		if (pos >= len - 1 || pos == 0 || \
			line[pos - 1] == ' ' || line[pos + 1] == ' ')
			return (0);
	if (mod == 2)
		if (pos >= len || line[pos] == ' ')
			return (0);
	if (mod == 3)
		if (line[pos] != '0' && line[pos] != '2')
		{
			if ((line[pos] == 'N' || line[pos] == 'S' || line[pos] == 'W' || \
				line[pos] == 'E') && !player)
				player = 1;
			else
				return (0);
		}
	if (mod == 4)
		if (!player)
			return (0);
	return (1);
}

static	int		is_valid_map(char **map)
{
	int		index;
	int		sindex;

	index = -1;
	while (map[++index])
	{
		sindex = -1;
		while (map[index][++sindex] != '\0')
			if (map[index][sindex] != '1' && map[index][sindex] != ' ')
			{
				if (!check(map[index], sindex, 1))
					return (0);
				if (!(index && map[index + 1]))
					return (0);
				if ((index && map[index + 1]) && \
					(!check(map[index - 1], sindex, 2) || \
					!check(map[index + 1], sindex, 2)))
					return (0);
				if (!check(map[index], sindex, 3))
					return (0);
			}
	}
	if (!check(NULL, 0, 4))
		return (0);
	return (1);
}

static	int		lst_to_matrix(t_pars *params, t_list **map)
{
	t_list	*lst_to_free;
	int		index;
	int		size;

	index = -1;
	lst_to_free = *map;
	size = ft_lstsize(*map);
	if (!(params->map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (!error_malloc_ltm_map(map));
	while (++index < size)
	{
		if (!(params->map[index] = ft_strdup((*map)->content)))
			return (!error_malloc_ltm_mindex(map, params));
		(*map) = (*map)->next;
	}
	params->map[index] = NULL;
	ft_lstclear(&lst_to_free, free);
	return (0);
}

static	int		get_lines(int fd, char *last_line, t_list **map)
{
	t_list	*tmplst;
	char	*tmplastl;
	char	*tmpdup;
	char	*line;
	int		temp;

	if (!(tmplastl = ft_strdup(last_line)))
		return (!error_malloc_tmplastl());
	if (!(*map = ft_lstnew(tmplastl)))
		return (!error_malloc_map(&tmplastl));
	while ((temp = get_next_line(fd, &line)))
	{
		if (temp == -1)
			return (error_read_file_get_lines(fd, map));
		if (!(tmpdup = ft_strdup(line)))
			return (!error_malloc_tmpdup(&line, map));
		if (!(tmplst = ft_lstnew(tmpdup)))
			return (!error_malloc_tmplst(&line, &tmpdup, map));
		ft_lstadd_back(map, tmplst);
		free(line);
	}
	free(line);
	return (0);
}

int				get_map(int fd, char *last_line, t_pars *params)
{
	int		error;
	t_list	*map;

	if ((error = get_lines(fd, last_line, &map)))
	{
		if (error == 1)
			return (error_get_lines(params));
		if (error == -1)
		{
			error_get_lines(params);
			return (error);
		}
	}
	if (lst_to_matrix(params, &map))
		return (error_get_lines(params));
	if (!is_valid_map(params->map))
		return (error_not_valid_map(params));
	return (1);
}
