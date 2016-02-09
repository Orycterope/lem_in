/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:34:25 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/09 19:23:00 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

t_room	*get_resonable_path(t_room *room, t_room *start, int ants) //ants are ants at start
{
	int			max_turns;
	t_tunnel	*tunnel;

	max_turns = ants + start->end_dist - 1; // -2 ?
	tunnel = room->tunnels;
	while (tunnel != NULL)
	{
		if (tunnel->room->ant == 0 && tunnel->room->end_dist <= max_turns)
			return (tunnel->room);
		tunnel = tunnel->next;
	}
	return (NULL);
}

void	save_distances(t_room *room, int end_dist)
{
	t_tunnel	*tunnel;

	if (room == NULL)
		return ;
	room->end_dist = end_dist;
	tunnel = room->tunnels;
	while (tunnel != NULL)
	{
		if (tunnel->room->end_dist == -1 || tunnel->room->end_dist > end_dist + 1)
			save_distances(tunnel->room, end_dist + 1);
		tunnel = tunnel->next;
	}
	sort_tunnels_by_dist(room);
}
