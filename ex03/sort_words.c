/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:31:14 by exam              #+#    #+#             */
/*   Updated: 2015/03/18 09:55:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord.h"

static int		alpha_cmp(t_word *w1, t_word *w2)
{
	int				i;

	i = 0;
	while (i <= w1->length && i <= w2->length)
	{
		if (LOWER(w1->str[i]) != LOWER(w2->str[i]))
			break ;
		i++;
	}
	return (LOWER(w1->str[i]) - LOWER(w2->str[i]));
}

static int		len_cmp(t_word *w1, t_word *w2)
{
	return (w1->length - w2->length);
}

static void		words_swap(t_word *words, int i, int j)
{
	t_word			tmp;

	tmp = words[i];
	words[i] = words[j];
	words[j] = tmp;
}

static void		sort(t_word *words, int count, int (*cmp)(t_word*, t_word*))
{
	int				i;
	int				j;
	int				min;

	i = -1;
	while (++i < count)
	{
		j = i;
		min = i;
		while (++j < count)
		{
			if (cmp(words + min, words + j) > 0)
				min = j;
		}
		if (min != i)
			words_swap(words, min, i);
	}
}

void			sort_words(t_word *words, int count)
{
	sort(words, count, &alpha_cmp);
	sort(words, count, &len_cmp);
}
