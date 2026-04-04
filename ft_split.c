/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesgari <mmesgari@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:38:38 by mmesgari          #+#    #+#             */
/*   Updated: 2026/04/04 20:01:12 by mmesgari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	w;
	int	in;

	i = 0;
	w = 0;
	in = 0;
	while (s[i])
	{
		if (s[i] == c)
			in = 0;
		else if (!in)
		{
			w++;
			in = 1;
		}
		i++;
	}
	return (w);
}

static char	*add(char const *s, char c)
{
	int		len;
	int		i;
	char	*w;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	w = malloc((len + 1) * sizeof(char));
	if (!w)
		return (NULL);
	i = 0;
	while (i < len)
	{
		w[i] = s[i];
		i++;
	}
	w[len] = '\0';
	return (w);
}

static int	process_word(char **r, char const *s, char c, int *j)
{
	r[*j] = add(s, c);
	if (!r[*j])
	{
		free_split(r);
		return (0);
	}
	(*j)++;
	return (1);
}

static int	split_fill(char **r, char const *s, char c)
{
	int	i;
	int	j;
	int	in;

	i = -1;
	j = 0;
	in = 0;
	while (s[++i])
	{
		if (s[i] != c && !in)
		{
			if (!process_word(r, &s[i], c, &j))
				return (0);
			in = 1;
		}
		else if (s[i] == c)
			in = 0;
	}
	r[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**r;
	int		w;

	if (!s)
		return (NULL);
	w = count_words(s, c);
	r = malloc((w + 1) * sizeof(char *));
	if (!r)
		return (NULL);
	if (!split_fill(r, s, c))
		return (NULL);
	return (r);
}
