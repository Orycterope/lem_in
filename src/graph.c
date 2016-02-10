/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 15:26:52 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/10 18:29:59 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void	block_tunnel(t_room *room1, t_room *room2)
{
	t_tunnel	*t;
	t_tunnel	*bckp_t;

	if (room1->tunnels->room == room2)
	{
		bckp_t = room1->tunnels;
		room1->tunnels = room1->tunnels->next;
	}
	else
	{
		t = room1->tunnels;
		while (t->next->room != room2)
			t = t->next;
		bckp_t = t->next;
		t->next = t->next->next;
	}
	free(bckp_t);
}

static void	check_room(t_room *room, t_room *previous)
{
	t_tunnel	*t;
	t_room		*room2;

	if (room->start_end == 'e')
		return;
	t = room->tunnels->next;
	while (get_tunnel_nbr(room) > 2)
	{
		if (t->room != previous)
		{
			room2 = t->room;
			block_tunnel(room, room2);
			block_tunnel(room2, room);
			t = room->tunnels;
		}
		t = t->next;
	}
	if (get_tunnel_nbr(room) != 1)
		check_room(room->tunnels->room, room);
}

void		remove_dead_tunnels(t_room *rooms)
{
	t_tunnel	*bckp_t;

	while (rooms != NULL)
	{
		while (rooms->tunnels != NULL && rooms->tunnels->room->end_dist == -1)
		{
			bckp_t = rooms->tunnels;
			rooms->tunnels = rooms->tunnels->next;
			block_tunnel(bckp_t->room, rooms);
			free(bckp_t);
		}
		rooms = rooms->next;
	}
}

void	cut_branches(t_room *rooms, t_room *start)
{
	t_tunnel	*tunnel;

	tunnel = start->tunnels;
	while (tunnel != NULL)
	{
		check_room(tunnel->room, start);
		tunnel = tunnel->next;
	}
	while (rooms != NULL)
	{
		rooms->end_dist = -1;
		rooms = rooms->next;
	}
}

void	save_distances(t_room *room, int end_dist)
{
	t_tunnel	*tunnel;

	if (room == NULL)
		return;
	room->end_dist = end_dist;
	if (room->start_end != 's')
	{
		tunnel = room->tunnels;
		while (tunnel != NULL)
		{
			if (tunnel->room->end_dist == -1
					|| tunnel->room->end_dist > end_dist + 1)
				save_distances(tunnel->room, end_dist + 1);
			tunnel = tunnel->next;
		}
	}
	sort_tunnels_by_dist(room);
}
