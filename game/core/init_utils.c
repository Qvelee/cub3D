/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 22:24:16 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/21 23:24:02 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_load_tex_images(t_core *game, t_object *object, char *path, \
	int quantity)
{
	int		temp;
	char	*buff_i;
	char	*buff_d_1;
	char	*buff_d_2;

	temp = -1;
	while (++temp < quantity)
	{
		load_image(game, &object->tex[temp], \
			(buff_d_1 = ft_strjoin(path, \
			(buff_d_2 = ft_strjoin(\
			(buff_i = ft_itoa(temp)), ".xpm")))));
		free(buff_i);
		free(buff_d_1);
		free(buff_d_2);
	}
	object->tex[temp].img.image = NULL;
}

void		init_load_anim_images(t_core *game, t_object *object, char *path, \
	int quantity)
{
	int		temp;
	char	*buff_i;
	char	*buff_d_1;
	char	*buff_d_2;
	char	*buff_d_3;

	temp = -1;
	while (++temp < quantity)
	{
		load_image(game, &object->anim[temp], \
			(buff_d_1 = ft_strjoin(path, \
			(buff_d_2 = ft_strjoin("animation/", \
			(buff_d_3 = ft_strjoin(\
			(buff_i = ft_itoa(temp)), ".xpm")))))));
		free(buff_i);
		free(buff_d_1);
		free(buff_d_2);
		free(buff_d_3);
	}
	object->anim[quantity].img.image = NULL;
}

void		create_anim_buff(t_core *game, t_tex *anim, t_list **a_buff, \
	int quant)
{
	t_list	*tmp;
	t_list	*last;
	int		temp;

	temp = -1;
	while (++temp < quant)
	{
		if (!(tmp = ft_lstnew(&anim[temp])))
			error_malloc(game);
		if (temp == quant - 1)
		{
			tmp->next = *a_buff;
			last = ft_lstlast(*a_buff);
			last->next = tmp;
		}
		else
			ft_lstadd_back(a_buff, tmp);
	}
}

void		init_a_buff(t_object *sprite, int quant)
{
	int index;

	index = -1;
	while (++index < quant)
		sprite->pos[index].a_buff = NULL;
}
