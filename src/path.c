/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:34:25 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/28 18:44:23 by tvermeil         ###   ########.fr       */
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
	return (n);
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
