/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:34:25 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/08 14:27:42 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

t_path	*append_new_room_to_path(t_room *room, t_path *path)
{
	t_path	*new;

	new = (t_path*)malloc(sizeof(t_path));
	if (new == NULL)
		return (NULL);
	new->room = room;
	new->next = path;
	return (new);
}

int		path_length(t_path *path)
{
	int	n;

	n = 0;
	while (path != NULL)
	{
		n++;
		path = path->next;
	}
	return (n - 2);
}

t_path	*get_shortest_path(t_room *start, t_room *end, int depth, int ignore)
{
	t_tunnel	*tunnel;
	t_path		*path;

	if (depth < 0)
		return (NULL);
	if (start == end)
		return (append_new_room_to_path(start, NULL));
	tunnel = start->tunnels;
	while (tunnel != NULL)
	{
		if (!(ignore == 1 && tunnel->room->ant != 0))
		{
			path = get_shortest_path(tunnel->room, end, depth - 1, 0);
			if (path != NULL)
				return (append_new_room_to_path(start, path));
		}
		tunnel = tunnel->next;
	}
	return (NULL);
}

t_path	*get_resonable_path(t_room *s, t_room *e, int ants, t_path *shortest) //ants are ants at start
{
	int		max_turns;
	int		i;
	t_path	*p;

	max_turns = ants + path_length(shortest);
	i = 0;
	while (i < max_turns)
	{
		p = get_shortest_path(s, e, i, 1);
		if (p != NULL)
			return (p);
		i++;
	}
	return (NULL);
}

void	free_path(t_path *path)
{
	t_path	*next;

	while (path != NULL)
	{
		next = path->next;
		free(path);
		path = next;
	}
}
