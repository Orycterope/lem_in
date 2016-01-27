/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:12:15 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/27 20:37:52 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H

typedef struct		s_room
{
	char			*name;
	char			start_end;
	int				neighbors_nbr;
	struct s_room	**neighbors
	struct s_room	*next;
}					t_room;

t_room	*get_room(char *name, t_room *room_lst);
t_room	*append_new_room(char *name, t_room *room_lst, char start_end);
void	free_rooms(t_room *room_lst);

#endif
