/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:43:25 by tvermeil          #+#    #+#             */
/*   Updated: 2016/03/23 16:51:41 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_str(char	*str)
{
	int		i;
	int		dot;

	dot = 1;
	if (str[0] == '-' || str[0] == '+')
		str++;
	if (str[0] == '\0')
		return  (0);
	while (str[0] == '0')
		str++;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.' && dot)
			dot = 0;
		else if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	if (ft_strlen(str) > 10
		|| (ft_strlen(str) == 10 && ft_strcmp(str, "2147483647") > 0))
		return (0);
	return (1);
}
