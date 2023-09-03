/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:18:23 by zabdulza          #+#    #+#             */
/*   Updated: 2023/03/09 13:50:32 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_searcherer(char const *s, char c)
{
	int	searcher;

	searcher = 0;
	while (*s != 0)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != 0)
		{
			searcher++;
			s++;
		}
	}
	return (searcher);
}

char	**ft_split(char const *s, char c)
{
	size_t	lenght;
	char	**result;
	size_t	i;	

	if (s == NULL)
		return (NULL);
	i = 0;
	result = malloc(sizeof(char *) * (ft_word_searcherer(s, c) + 1));
	if (result == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			lenght = 0;
			while (*s && *s != c && ++lenght)
				s++;
			result[i] = ft_substr(s - lenght, 0, lenght);
			i++;
		}
		else
			s++;
	}
	result[i] = 0;
	return (result);
}
