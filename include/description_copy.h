/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description_copy.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:26:43 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/18 15:53:56 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESCRIPTION_COPY_H
# define DESCRIPTION_COPY_H

typedef struct			s_desc_lst
{
	char				*desc_line;
	struct s_desc_lst	*next;
}						t_desc_lst;

t_desc_lst				*init_desc_lst(void);
void					save_desc_line(char *line, t_desc_lst *lst);
void					repeat_desc_lines(t_desc_lst *lst);

#endif
