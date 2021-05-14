/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:30:59 by aalcara-          #+#    #+#             */
/*   Updated: 2021/03/07 12:50:36 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i) != '\0')
		i++;
	return (i);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	unsigned long	i;
	unsigned long	total;

	i = 0;
	total = nmemb * size;
	p = (unsigned char *)malloc(total);
	if (p == NULL)
		return (NULL);
	while (i < total)
	{
		*(p + i) = 0;
		i++;
	}
	return ((void *)p);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		s_len;
	unsigned int		real_len;
	char				*substr;

	if (s != NULL)
	{
		i = 0;
		real_len = len;
		s_len = ft_strlen(s);
		if (start >= s_len)
			return (substr = ft_calloc(1, sizeof(char)));
		if ((s_len - start) < len)
			real_len = (s_len - start);
		substr = ft_calloc(real_len + 1, sizeof(char));
		if (!substr)
			return (0);
		while (*(s + start + i) != '\0' && i < len)
		{
			*(substr + i) = *(s + i + start);
			i++;
		}
		return (substr);
	}
	return (NULL);
}

char		*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t			len;
	char			*substr;
	char			*pointer;
	char			*s1zero;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(substr = malloc((len + 1) * sizeof(char))))
	{
		free(s1);
		return (NULL);
	}
	pointer = substr;
	s1zero = s1;
	if (s1)
		while (*s1)
			*pointer++ = *s1++;
	if (s2)
		while (*s2)
			*pointer++ = *s2++;
	*pointer = '\0';
	free(s1zero);
	return (substr);
}
