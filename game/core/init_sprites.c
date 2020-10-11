/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:00:56 by nelisabe          #+#    #+#             */
/*   Updated: 2020/10/11 15:19:48 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//add malloc protect

void	set_spr(t_sprite *sprite, double x, double y, double z)
{
	sprite->x = x;
	sprite->y = y;
	sprite->z = z;
}

void	init_devil(t_core *game, char *path)
{
	int			quantity;
	
	quantity = -1;
	game->devil.tex = (t_tex*)malloc(sizeof(t_tex) * 8);
	while (++quantity < 8)
		load_image(game, &game->devil.tex[quantity], \
			ft_strjoin(path, ft_strjoin(ft_itoa(quantity), ".xpm")));
	game->devil.quantity = 3;
	game->devil.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->devil.quantity);
	game->devil.pos[0].volume = 1;
	game->devil.pos[0].condition = 1;
	// game->devil.pos[0].animation = 0;
	game->devil.pos[0].type = 'd';
	game->devil.pos[0].scale = 1;
	set_spr(&game->devil.pos[0], 2.5, 1.5, 0.5);
	game->devil.pos[1].volume = 1;
	game->devil.pos[1].condition = 1;
	// game->devil.pos[1].animation = 0;
	game->devil.pos[1].type = 'd';
	game->devil.pos[1].scale = 0.3;
	set_spr(&game->devil.pos[1], 6.1, 2.9, 0.5);
	game->devil.pos[2].volume = 1;
	game->devil.pos[2].condition = 1;
	// game->devil.pos[2].animation = 0;
	game->devil.pos[2].type = 'd';
	game->devil.pos[2].scale = 1;
	set_spr(&game->devil.pos[2], 13.5, 3.7, 0.5);
}

void	create_anim_buff(t_tex *anim, t_list **a_buff, int quant)
{
	t_list	*tmp;
	t_list	*last;
	int		temp;

	temp = -1;
	while (++temp < quant)
	{
		tmp = ft_lstnew(&anim[temp]);
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

void	init_pin(t_core *game, char *path)
{
	int		quantity;
 	int		temp;

	quantity = 1;
	temp = -1;
	game->pin.tex = (t_tex*)malloc(sizeof(t_tex) * quantity);
	while (++temp < quantity)
		load_image(game, &game->pin.tex[temp], \
			ft_strjoin(path, ft_strjoin(ft_itoa(temp), ".xpm")));
	temp = -1;
	game->pin.anim = (t_tex*)malloc(sizeof(t_tex) * 8);
	while (++temp < 8)
		load_image(game, &game->pin.anim[temp], \
			ft_strjoin(path, ft_strjoin("animation/", \
			ft_strjoin(ft_itoa(temp), ".xpm"))));
	game->pin.quantity = 4;
	game->pin.pos = (t_sprite*)malloc(sizeof(t_sprite) * \
		game->pin.quantity);
	game->pin.pos[0].condition = 1;
	game->pin.pos[0].volume = 0;
	game->pin.pos[0].a_tmp = 0;
	game->pin.pos[0].a_speed = 5;
	game->pin.pos[0].type = 'p';
	game->pin.pos[0].scale = 1;
	set_spr(&game->pin.pos[0], 7.5, 3.5, 0.5);
	create_anim_buff(game->pin.anim, &game->pin.pos[0].a_buff, 8);
	game->pin.pos[1].condition = 1;
	game->pin.pos[1].volume = 0;
	game->pin.pos[1].a_tmp = 0;
	game->pin.pos[1].a_speed = 4;
	game->pin.pos[1].type = 'p';
	game->pin.pos[1].scale = 0.9;
	set_spr(&game->pin.pos[1], 7.5, 4.5, 0.5);
	create_anim_buff(game->pin.anim, &game->pin.pos[1].a_buff, 8);
	game->pin.pos[2].condition = 1;
	game->pin.pos[2].volume = 0;
	game->pin.pos[2].a_tmp = 0;
	game->pin.pos[2].a_speed = 3;
	game->pin.pos[2].type = 'p';
	game->pin.pos[2].scale = 0.6;
	set_spr(&game->pin.pos[2], 7.5, 5.5, 0.5);
	create_anim_buff(game->pin.anim, &game->pin.pos[2].a_buff, 8);
	game->pin.pos[3].condition = 1;
	game->pin.pos[3].volume = 0;
	game->pin.pos[3].a_tmp = 0;
	game->pin.pos[3].a_speed = 2;
	game->pin.pos[3].type = 'p';
	game->pin.pos[3].scale = 0.4;
	set_spr(&game->pin.pos[3], 7.5, 6.5, 0.5);
	create_anim_buff(game->pin.anim, &game->pin.pos[3].a_buff, 8);
}

void	init_sprites(t_core *game)
{
	init_basic(game, game->params->s);
	init_devil(game, "./sprites/devil/");
	init_pin(game, "./sprites/pin/");
	game->objects = (t_object**)malloc(sizeof(t_object*) * 4);
	game->objects[0] = &game->basic;
	game->objects[1] = &game->devil;
	game->objects[2] = &game->pin;
	game->objects[3] = NULL;
}