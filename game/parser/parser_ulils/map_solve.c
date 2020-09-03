/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 16:04:42 by nelisabe          #+#    #+#             */
/*   Updated: 2020/09/03 14:18:29 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static	int		check(char *line, int pos, int mod)
{
	static int	player;
	const int	len = ft_strlen(line);
	
	if (mod == 1)
		if (pos >= len - 1 || pos == 0 || line[pos - 1] == ' ' || line[pos + 1] == ' ')
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
	int 	sindex;

	index = -1;
	while (map[++index])
	{
		sindex = -1;
		while (map[index][++sindex] != '\0')
			if (map[index][sindex] != '1' && map[index][sindex] != ' ')
			{
				if (!check(map[index], sindex, 1))
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

static	int		lst_to_matrix(t_pars *params, t_list *map)
{
	int index;
	int size;

	index = -1;
	size = ft_lstsize(map);
	params->map=(char**)malloc(sizeof(char*) * (size + 1));
	while (++index < size)
	{
		params->map[index] = ft_strdup(map->content);
		map = map->next;
	}
	params->map[index] = NULL;
	return (0);
}

static	int		get_lines(int fd, char *last_line, t_list **map)
{
	char	*line;
	int		temp;

	*map = ft_lstnew(last_line);
	while ((temp = get_next_line(fd, &line)))
	{
		if (temp == -1)	
			return (1);
		ft_lstadd_back(map, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	free(line);
	return (0);
}

int				map_solve(int fd, char *last_line, t_pars *params)
{
	int		error;
	t_list	*map;

	get_lines(fd, last_line, &map);
	lst_to_matrix(params, map);
	if (is_valid_map(params->map))
		printf("valid map\n");
	else
		printf("not valid map\n");
	return (1);
}