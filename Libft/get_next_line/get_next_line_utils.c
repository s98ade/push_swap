/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:20:51 by sade              #+#    #+#             */
/*   Updated: 2023/12/15 14:46:35 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	str = (char *) malloc (len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		++i;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	ptr = (char *)s1;
	i = 0;
	ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *b_s, char const *a_s)
{
	char	*r_s;
	char	*r_p;
	char	*b_p;

	if (b_s == NULL)
		return (ft_strdup(a_s));
	r_s = malloc(sizeof(char) * (ft_strlen(b_s) + ft_strlen(a_s) + 1));
	if (!r_s)
	{
		free(b_s);
		return (NULL);
	}
	b_p = b_s;
	r_p = r_s;
	while (*b_p)
		*r_p++ = *b_p++;
	while (*a_s)
		*r_p++ = *a_s++;
	*r_p = '\0';
	free(b_s);
	return (r_s);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char) c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)str);
	return (NULL);
}
