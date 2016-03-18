/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description_copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:30:04 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/18 18:01:17 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "description_copy.h"

t_desc_lst	*init_desc_lst(void)
{
	t_desc_lst	*n;

	n = (t_desc_lst *)ft_memalloc(sizeof(t_desc_lst));
	n->next = NULL;
	n->desc_line = NULL;
	return (n);
}

void		save_desc_line(char *line, t_desc_lst *lst)
{
	t_desc_lst	*n;

	if (line == NULL)
		return ;
	while (lst->next != NULL)
		lst = lst->next;
	n = (t_desc_lst *)ft_memalloc(sizeof(t_desc_lst));
	n->desc_line = ft_strdup(line);
	n->next = NULL;
	lst->next = n;
}

void		repeat_desc_lines(t_desc_lst *lst)
{
	t_desc_lst	*n;

	while (lst != NULL)
	{
		n = lst->next;
		if (lst->desc_line != NULL)
			ft_putendl(lst->desc_line);
		free(lst->desc_line);
		free(lst);
		lst = n;
	}
}
