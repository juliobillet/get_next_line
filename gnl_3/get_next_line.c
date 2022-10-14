/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:56:34 by jbillet           #+#    #+#             */
/*   Updated: 2022/06/14 02:32:46 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_is_temp_empty(char *temp, char *buf)
// {
// 	if (ft_strlen(temp) < 1)
// 	{
// 		free(temp);
// 		// printf("temp content: %s\n", temp);
// 		// printf("temp len: %ld\n", ft_strlen(temp));
// 		// printf("buf content: %s\n", buf);
// 		// printf("buf len: %ld\n", ft_strlen(buf));
// 		temp = malloc((ft_strlen(buf) + 1) * sizeof(char));
// 		if (!temp)
// 			return (NULL);
// 		ft_strlcpy(temp, buf, 2);
// 		// printf("temp content: %s\n", temp);
// 		// printf("temp len: %ld\n", ft_strlen(temp));
// 		return (temp);
// 	}
// 	else
// 		temp = ft_strjoin(temp, buf);
// 	// printf("temp content: %s\n", temp);
// 	// printf("temp len: %ld\n", ft_strlen(temp));
// 	return (temp);
// }

// char	*ft_is_end_of_line(char *temp, char *new_line)
// {
// 	size_t	i;

// 	i = 0;
// 	// printf("temp content: %s\n", temp);
// 	// printf("pré while EOL\n");
// 	while (temp[i])
// 	{
// 		// printf("dentro while EOL pré if\n");
// 		if (temp[i] == '\n')
// 		{
// 			// printf("pré free\n");
// 			free(new_line);
// 			// printf("pos free pré malloc new line\n");
// 			new_line = malloc((ft_strlen(temp) - 1) * sizeof(char));
// 			if (!new_line)
// 				return (NULL);
// 			else
// 			{
// 				// printf("se entrar, strlcpy\n");
// 				ft_strlcpy(new_line, temp, ft_strlen(temp));
// 			}
// 			// printf("pós malloc e strlcpy e pré free\n");
// 			free(temp);
// 			// printf("pos free e pré return new line\n");
// 			return (new_line);
// 		}
// 		i++;
// 	}
// 	return (new_line);
// }

static char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

static char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}

// char	*get_next_line(int fd)
// {
// 	char	*buf;
// 	char	*temp;
// 	char	*new_line;

// 	temp = malloc(0);
// 	new_line = malloc(0);
// 	buf = malloc(2 * sizeof(char));
// 	if (!buf)
// 		return (NULL);
// 	// printf("pré get while\n");
// 	// printf("new_line len: %ld\n",ft_strlen(new_line));
// 	while (!ft_strlen(new_line))
// 	{
// 		// printf("pré read\n");
// 		if (read(fd, buf, 1) < 1)
// 			return (NULL);
// 		buf[ft_strlen(buf) + 1] = '\0';
// 		// if (buf[0] == '\n')
// 		// 	read(fd, buf, 1);
// 		// else if (read(fd, buf, 1) == 0)
// 		// 	return ("");
// 		// printf("pos read e pré temp empty\n");
// 		temp = ft_is_temp_empty(temp, buf);
// 		if (!temp)
// 			return (NULL);
// 		// printf("temp content: %s\n", temp);
// 		// printf("pos temp empty e pré EOL\n");
// 		new_line = ft_is_end_of_line(temp, new_line);
// 		if (!new_line)
// 			return (NULL);
// 		// printf("pos EOL\n");
// 	}
// 	// printf("pós get while\n");
// 	free(buf);
// 	return (new_line);
// }

/*
read prototype:
ssize_t read(int fd, void *buf, size_t count);

ft_is_temp_empty summary:
verify if temp already has content, if not, allocates space for it and fill
it with buf's content

ft_is_end_of_line summary:
verify for New Line character and if so, copy new line to new_live variable,
allocating mem and returning it
*/
