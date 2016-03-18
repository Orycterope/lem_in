/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:43:28 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/18 16:02:30 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "get_next_line.h"
# include "libft.h"
# include "room.h"
# include "graph.h"
# include "path.h"
# include "tunnel.h"
# include "ant.h"
# include "description_copy.h"

void	error(void);
int		get_lem_nbr(t_desc_lst *desc_lst);
t_room	*save_rooms(t_desc_lst *desc_lst);

#endif
