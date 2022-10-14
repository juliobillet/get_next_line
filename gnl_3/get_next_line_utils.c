/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:56:53 by jbillet           #+#    #+#             */
/*   Updated: 2022/06/13 23:22:25 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dest_size > 0)
	{
		while (src[i] != '\0' && i < (dest_size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

char	*ft_strjoin(char *temp, char *buf)
{
	char	*ptr;
	size_t	temp_len;
	size_t	buf_len;
	size_t	total_len;

	if (!temp || !buf)
		return (NULL);
	temp_len = ft_strlen(temp);
	buf_len = ft_strlen(buf);
	total_len = temp_len + buf_len + 1;
	ptr = malloc(sizeof(char) * total_len);
	if (!ptr)
		return (NULL);
	ft_strlcpy(&ptr[0], temp, (temp_len + 1));
	ft_strlcpy(&ptr[temp_len], buf, (buf_len + 1));
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*new_str;

	s_len = ft_strlen(s);
	new_str = malloc(sizeof(char) * s_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, s_len);
	new_str[s_len] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c > 255)
		return ((char *)(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if ((s_len - start) < len)
		sub_str = malloc(sizeof(char) * (s_len - start + 1));
	else
		sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, (s + start), (len + 1));
	return (sub_str);
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*dest_char;
// 	unsigned char	*src_char;
// 	size_t			i;

// 	i = 0;
// 	if (n < 1)
// 		return (dest);
// 	dest_char = (unsigned char *)dest;
// 	src_char = (unsigned char *)src;
// 	if (dest > src)
// 		while (n--)
// 			dest_char[n] = src_char[n];
// 	else
// 	{
// 		while (i++ < n)
// 			dest_char[i] = src_char[i];
// 	}
// 	return (dest_char);
// }

// size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
// {
// 	size_t	i;
// 	size_t	dest_len;
// 	size_t	src_len;

// 	i = 0;
// 	dest_len = ft_strlen(dest);
// 	src_len = ft_strlen(src);
// 	if (dest_size > dest_len)
// 	{
// 		while (src[i] != '\0' && dest_len + i < dest_size - 1)
// 		{
// 			dest[dest_len + i] = src[i];
// 			i++;
// 		}
// 		dest[dest_len + i] = '\0';
// 		return (dest_len + src_len);
// 	}
// 	else
// 		return (dest_size + src_len);
// }

// static	char	**ft_split_s(char const *s, char c, 
//char **result, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	word_len;

// 	i = 0;
// 	j = 0;
// 	word_len = 0;
// 	while (i < len + 1)
// 	{
// 		if (s[i] == c || !s[i])
// 		{
// 			if (word_len > 0)
// 			{
// 				result[j] = (char *)malloc(sizeof(char) * (word_len + 1));
// 				if (result[j])
// 					ft_strlcpy(result[j], &s[i - word_len], (word_len + 1));
// 				word_len = 0;
// 				j++;
// 			}
// 		}
// 		else
// 			word_len++;
// 		i++;
// 	}
// 	return (result);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**result;
// 	size_t	i;
// 	size_t	total_words;
// 	size_t	s_len;

// 	if (!s)
// 		return (NULL);
// 	s_len = ft_strlen(s);
// 	i = 0;
// 	total_words = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
// 			++total_words;
// 		++i;
// 	}
// 	result = (char **)malloc(sizeof (char *) * (total_words + 1));
// 	if (!result)
// 		return (NULL);
// 	result = ft_split_s(s, c, result, s_len);
// 	result[total_words] = NULL;
// 	return (result);
// }
