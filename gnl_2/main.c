/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbillet <jbillet@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:47:05 by jbillet           #+#    #+#             */
/*   Updated: 2022/06/27 08:56:46 by jbillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;

	printf("=== clarice.txt Test ===\n");
	fd = open("./clarice.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("\n");
	printf("=== arquivo.txt Test ===\n");
	fd = open("./arquivo.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("\n");
	return (0);
}
// int	main(void)
// {
// 	size_t	i;
// 	char	*str = "\n\0";

// 	i = -1;
// 	while (++i < 2)
// 		if (!str[i])
// 			printf("entrou com i = %ld\n", i);
// 	return (0);
// }
