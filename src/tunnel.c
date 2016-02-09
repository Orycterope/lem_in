/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunnel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:49:06 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/09 19:50:05 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tunnel.h"


void		*append_new_tunnel_to_room(t_room *room, t_room *neighbor)
{
	t_tunnel	*new;

	new = (t_tunnel*)malloc(sizeof(t_tunnel));
	if (new == NULL)
		return (NULL);
	new->room = neighbor;
	new->next = room->tunnels;
	room->tunnels = new;
	return (new);
}

static int	tunnels_are_sorted(t_room *room)
{
	t_tunnel	*tunnel;

	tunnel = room->tunnels;
	while (tunnel->next != NULL)
	{
		if (tunnel->room->end_dist > tunnel->next->room->end_dist)
			return (0);
		tunnel = tunnel->next;
	}
	return (1);
}

static void	swap_tunnels(t_room *room, t_tunnel *first)
{
	t_tunnel	*second;
	t_tunnel	*parser;

	second = first->next;
	if (first == room->tunnels)
		room->tunnels = second;
	else
	{
		parser = room->tunnels;
		while (parser->next != first)
			parser = parser->next;
		parser->next = second;
	}
	first->next = second->next;
	second->next = first;
}


void		sort_tunnels_by_dist(t_room *room)
{
	t_tunnel	*tunnel;

	if (room->tunnels == NULL)
		return ;
	while (!(tunnels_are_sorted(room)))
	{
		tunnel = room->tunnels;
		while (tunnel != NULL && tunnel->next != NULL)
		{
			if (tunnel->room->end_dist > tunnel->next->room->end_dist)
				swap_tunnels(room, tunnel);
			tunnel = tunnel->next;
		}
	}
}

void		free_tunnels(t_room *room)
{
	t_tunnel	*next;
	t_tunnel	*tunnel;

	tunnel = room->tunnels;
	while (tunnel != NULL)
	{
		next = tunnel->next;
		free(tunnel);
		tunnel = next;
	}
}
