/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:42:04 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/09 18:22:49 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(0);
}

void	execute_turn(t_room *rooms, int *first_ant, int last_ant)
{
	t_room	*room;
	t_room	*start;
	int		ant;
	int		moved;

	start = get_start(rooms);
	ant = *first_ant;
	while (ant <= last_ant)
	{
		room = get_ant_position(ant, rooms);
		if (room != NULL)
		{
			moved = ant_decide(room, last_ant - ant + 1, rooms, start);
			if (room == start && moved == 0)
				break;
			else if (get_ant_position(ant, rooms) == NULL)
			{
				*first_ant += 1;
				if (room == start)
					break;
			}
		}
		ant++;
	}
}

void	lem_in(t_room *rooms, int ants, t_room *start, t_room *end)
{
	int		first_ant;
	int		i;

	i = 0;
	first_ant = 1;
	save_distances(end, 0);
	if (start->end_dist == -1)
		error();
	while (start->ant < ants || get_ant_position(ants, rooms) != NULL)
	{
		execute_turn(rooms, &first_ant, ants);
		ft_putchar('\n');
	}
}

int	main(void)
{
	int		ant_nbr;
	t_room	*rooms;
	t_room	*start;
	t_room	*end;

	ant_nbr = get_lem_nbr();
	if (ant_nbr <= 0)
		error();
	rooms = save_rooms();
	start = get_start(rooms);
	end = get_end(rooms);
	if (start == NULL || end == NULL || start == end)
		error();
	start->ant = 1;
	lem_in(rooms, ant_nbr, start, end);
}
