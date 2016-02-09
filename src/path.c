/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:34:25 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/09 18:27:04 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

/*t_room	*get_shortest_path(t_room *start)  //Still used ?
{
	t_tunnel	*tunnel;
	t_room		*best_room;
	int			best_dist;

	tunnel = start->tunnels;
	if (tunnel == NULL)
		return (NULL);
	best_room = tunnel->room;
	best_dist = tunnel->room->end_dist;
	while (tunnel != NULL)
	{
		if (tunnel->room->end_dist < best_dist)
		{
			best_room = tunnel->room;
			best_dist = tunnel->room->end_dist;
		}
		tunnel = tunnel->next;
	}
	return (best_room);
}*/

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
}
