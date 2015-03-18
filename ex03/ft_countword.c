/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:20:20 by exam              #+#    #+#             */
/*   Updated: 2015/03/18 09:25:54 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord.h"

int				ft_countword(const char *str)
{
	int				count;

	count = 0;
	while (ft_isspace(*str))
		str++;
	while (*str != '\0')
	{
		count++;
		while (!ft_isspace(*str) && *str != '\0')
			str++;
		while (ft_isspace(*str))
			str++;
	}
	return (count);
}
