/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:20:00 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/27 19:43:54 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "room.h"

t_room	*get_room(char *name, t_room *room_lst)
{
	while (room_lst != NULL && ft_strcmp(room_lst->name, name) != 0)
		room_lst = room_lst->next;
	return (room_lst);
}

t_room	*get_start(t_room *room_lst)
{
	while (room_lst != NULL && room_lst->start_end != 's')
		room_lst = room_lst->next;
	return (room_lst);
}

t_room	*get_end(t_room *room_lst)
{
	while (room_lst != NULL && room_lst->start_end != 'e')
		room_lst = room_lst->next;
	return (room_lst);
}

t_room	*append_new_room(char *name, t_room *room_lst, char s_e)
{
	t_room	*new;
	t_room	*parser;

	new = (t_room*)malloc(sizeof(t_room));
	if (new == NULL)
		return (NULL);
	new->name = name;
	new->start_end = s_e;
	new->next = NULL;
	new->neighbors = NULL;
	if (room_lst == NULL)
		return (new);
	parser = *room_lst;
	while (parser->next != NULL)
		parser = parser->next;
	parser->next = new;
	return (room_lst);
}

void	free_rooms(t_room *room_lst)
{
	t_pendant	*next;

	while (room_lst != NULL)
	{
		next = room_lst->next;
		free(room_lst->neighbors);
		free(room_lst->name);
		free(room_lst);
		room_lst = next;
	}
}
