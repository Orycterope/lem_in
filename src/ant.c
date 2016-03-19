/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 20:57:21 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/19 14:37:57 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ant.h"

void	print_ant(int ant, t_room *room)
{
	ft_putstr("L\x1B[");
	if (ant % 12 >= 6)
		ft_putchar('0');
	else
		ft_putchar('1');
	ft_putstr(";3");
	ft_putnbr(ant % 6 + 1);
	ft_putchar('m');
	ft_putnbr(ant);
	ft_putstr("\x1B[0m");
	ft_putchar('-');
	ft_putstr(room->name);
	ft_putchar(' ');
}

t_room	*get_ant_position(int ant, t_room *room)
{
	while (room != NULL)
	{
		if (room->ant == ant)
			return (room);
		room = room->next;
	}
	return (NULL);
}

void	move_ant(t_room *room1, t_room *room2)
{
	if (room1->ant == 0 || room2->ant != 0)
		return ;
	room2->ant = room1->ant;
	room1->ant = 0;
	print_ant(room2->ant, room2);
	if (room1->start_end == 's')
		room1->ant = room2->ant + 1;
	if (room2->start_end == 'e')
		room2->ant = 0;
}

int		ant_decide(t_room *location, int rmng_ants, t_room *start)
{
	t_room	*next;
	int		moved;

	moved = 0;
	if (location != start)
		next = location->tunnels->room;
	else
		next = get_resonable_path(location, start, rmng_ants);
	if (next != NULL)
	{
		moved = 1;
		move_ant(location, next);
	}
	return (moved);
}
