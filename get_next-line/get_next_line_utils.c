/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:26:19 by zabdulza          #+#    #+#             */
/*   Updated: 2023/06/06 17:11:55 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*original_dst;
	char	*dst1;
	char	*src2;

	dst1 = (char *)dst;
	src2 = (char *)src;
	if (!dst && !src)
		return (NULL);
	original_dst = dst;
	while (n--)
		*((char *)dst1++) = *((char *)src2++);
	return (original_dst);
}

int	ft_find_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		len1;
	size_t		len2;
	char		*strg;

	len1 = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len1 = ft_len(s1);
	len2 = ft_len(s2);
	strg = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!strg)
		return (NULL);
	ft_memcpy(strg, s1, len1);
	ft_memcpy(strg + len1, s2, len2 + 1);
	free(s1);
	return (strg);
}

size_t	ft_strcspn(const char *str, const char *charset)
{
	size_t	index;
	size_t	charset_index;

	index = 0;
	while (str[index] != '\0')
	{
		charset_index = 0;
		while (charset[charset_index] != '\0')
		{
			if (str[index] == charset[charset_index])
				return (index);
			charset_index++;
		}
		index++;
	}
	return (index);
}
