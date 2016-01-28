/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:31:01 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/28 18:11:32 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"

static void	print_ant(int ant, t_room *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room->name);
	ft_putchar(' ');
}


void		display_ants(t_room *rooms, int ant_nbr)
{
	int	ant;
	t_room	room_parser;

	ant = 1;
	while (ant <= ant_nbr)
	{
		room_parser = rooms;
		while (room_parser != NULL)
		{
			if (room_parser->ant == i && room_parser->has_moved)
			{
				print_ant(ant, room_parser);
				break;
			}
			room_parser = room_parser->next;
		}
		ant++;
	}
	ft_putchar('\n');
}
