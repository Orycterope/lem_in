/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 21:12:16 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/28 22:25:37 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANT_H
# define ANT_H

t_room	*get_ant_position(int n, t_room *room);
void	*move_ant(t_room *room1, t_room *room2);
int		ant_decide(t_room *location, int rmng_ants, t_room *rooms, t_path *s);

#endif
