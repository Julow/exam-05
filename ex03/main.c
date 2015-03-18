/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:16:05 by exam              #+#    #+#             */
/*   Updated: 2015/03/18 09:48:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord.h"
#include <unistd.h>

static void		print_words(t_word *words, int count)
{
	int				len;
	int				i;

	i = 0;
	while (i < count)
	{
		len = words[i].length;
		write(1, words[i].str, len);
		while (++i < count && words[i].length == len)
		{
			write(1, " ", 1);
			write(1, words[i].str, words[i].length);
		}
		write(1, "\n", 1);
	}
}

static void		words_fill(const char *str, t_word *words, int count)
{
	int				i;
	t_word			tmp;

	while (ft_isspace(*str))
		str++;
	i = -1;
	while (++i < count)
	{
		tmp = (t_word){str, 0};
		while (!ft_isspace(str[tmp.length]) && str[tmp.length] != '\0')
			tmp.length++;
		words[i] = tmp;
		str += tmp.length;
		while (ft_isspace(*str))
			str++;
	}
}

static void		ord_alphlong(const char *str)
{
	const int		w_count = ft_countword(str);
	t_word			words[w_count];

	words_fill(str, words, w_count);
	sort_words(words, w_count);
	print_words(words, w_count);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		ord_alphlong(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
