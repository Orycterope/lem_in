/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:34:25 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/10 00:17:23 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

int		is_dead_end(t_room *room, t_tunnel *tunnel)
{
	t_room	*next;

	next = tunnel->room;
	if (next->start_end == 'e')
		return (0);
	if (next->tunnels->room == room)
	{
		if (next->tunnels->next == NULL)
			return (1);
		return (next->tunnels->next->room->end_dist > room->end_dist);
	}
	else
		return (0);
}

t_room	*get_resonable_path(t_room *room, t_room *start, int ants)
{
	int			max_turns;
	t_tunnel	*tunnel;

	max_turns = ants + start->end_dist - 1; // -2 ?
	tunnel = room->tunnels;
	while (tunnel != NULL)
	{
		if (tunnel->room->ant == 0 && tunnel->room->end_dist <= max_turns
				&& !(is_dead_end(room, tunnel)))
			return (tunnel->room);
		else if (tunnel->room->ant != 0)
			max_turns -= 1;
		tunnel = tunnel->next;
	}
	return (NULL);
}

void	save_distances(t_room *room, int end_dist)
{
	t_tunnel	*tunnel;

	if (room == NULL)
		return;
	room->end_dist = end_dist;
	tunnel = room->tunnels;
	while (tunnel != NULL)
	{
		if (tunnel->room->end_dist == -1
				|| tunnel->room->end_dist > end_dist + 1)
			save_distances(tunnel->room, end_dist + 1);
		tunnel = tunnel->next;
	}
	sort_tunnels_by_dist(room);
}
