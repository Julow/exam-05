/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:18:02 by exam              #+#    #+#             */
/*   Updated: 2015/03/18 09:47:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORD_H
# define ORD_H

typedef struct	s_word
{
	const char		*str;
	int				length;
}				t_word;

# define LOWER(c)		(((c) >= 'A' && (c) <= 'Z') ? (c) + 32 : (c))

void			sort_words(t_word *words, int count);

int				ft_countword(const char *str);
int				ft_isspace(char c);

#endif
