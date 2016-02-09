/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:12:15 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/09 17:26:03 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOM_H
# define ROOM_H
# include "libft.h"

typedef struct		s_room
{
	char			*name;
	char			start_end;
	int				ant;
	int				end_dist;
	struct s_tunnel	*tunnels;
	struct s_room	*next;
}					t_room;

t_room	*get_room(char *name, t_room *room_lst);
t_room	*get_start(t_room *room_lst);
t_room	*get_end(t_room *room_lst);
t_room	*append_new_room(char *name, t_room *room_lst, char start_end);
void	free_rooms(t_room *room_lst);
void	free_tunnels(t_room *room);

#endif
