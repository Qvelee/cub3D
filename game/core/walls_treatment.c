/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:26:17 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 20:23:57 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	add_wall_to_list(t_list **walls, t_ray_cast *wall, \
	t_list *tmplst)
{
	t_ray_cast	*temp;
	t_list		*first;
	void		*link;

	first = *walls;
	if (*walls)
	{
		while ((*walls)->next)
		{
			temp = (*walls)->content;
			if (wall->depth >= temp->depth)
				break ;
			*walls = (*walls)->next;
		}
		tmplst->next = (*walls)->next;
		link = (*walls)->content;
		(*walls)->content = tmplst->content;
		tmplst->content = link;
		(*walls)->next = tmplst;
		*walls = first;
	}
	else
		*walls = tmplst;
}

int				sort_walls(t_core *game, t_ray_cast **buffer, t_list **walls)
{
	t_list	*tmplst;
	int		temp;

	temp = 0;
	while (temp < game->player.num_rays)
	{
		if (!(tmplst = ft_lstnew(&(*buffer)[temp])))
			return (1);
		add_wall_to_list(walls, &(*buffer)[temp], tmplst);
		temp++;
	}
	return (0);
}
