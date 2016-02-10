/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:42:04 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/10 17:06:49 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(0);
}

void	execute_turn(t_room *rooms, t_room *start, int first_ant, int tt_ants)
{
	t_room		*room;
	t_tunnel	*first_tunnel;
	int			ant;
	int			moved;

	ant = first_ant;
	first_tunnel = start->tunnels;
	while (ant <= tt_ants)
	{
		room = get_ant_position(ant, rooms);
		if (room != NULL)
		{
			moved = ant_decide(room, tt_ants - ant + 1, start);
			if (room == start && moved == 0)
				break ;
			else if (get_ant_position(ant, rooms) == NULL)
			{
				if (room == start)
					start->tunnels = start->tunnels->next;
			}
		}
		ant++;
	}
	start->tunnels = first_tunnel;
}

void	lem_in(t_room *rooms, int ants, t_room *start)
{
	int		first_ant;
	int		i;

	i = 0;
	first_ant = 1;
	while (start->ant < ants || get_ant_position(first_ant, rooms) != NULL)
	{
		execute_turn(rooms, start, first_ant, ants);
		while (get_ant_position(first_ant, rooms) == NULL && first_ant < ants)
				first_ant++;
		ft_putchar('\n');
	}
}

int		main(void)
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
	save_distances(end, 0);
	remove_dead_tunnels(rooms);
	if (start->end_dist == -1)
		error();
	cut_branches(rooms, start);
	save_distances(end, 0);
	remove_dead_tunnels(rooms);
	lem_in(rooms, ant_nbr, start);
}
