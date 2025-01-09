/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserlotfi <yasserlotfi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:02:21 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/01/08 10:59:53 by yasserlotfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*before_newline(char *str)
{
	int		i;
	char	*n_str;

	i = 0;
	if (str[i] == '\0' || !str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	n_str = malloc(i + 1);
	if (n_str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}

char	*after_newline(char *str)
{
	int		i;
	char	*n_str;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), str = NULL);
	if (str[i] == '\n')
		i++;
	n_str = ft_strdup(&str[i]);
	free (str);
	return (n_str);
}

char	*get_next_line(int fd)
{
	static char	*hold;
	char		*buffer;
	int			b_readed;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(hold), hold = NULL);
	buffer = malloc (BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (free(hold), hold = NULL);
	b_readed = 1;
	while (b_readed > 0 && ft_strchr(hold) != 1)
	{
		b_readed = read(fd, buffer, BUFFER_SIZE);
		if (b_readed == -1)
			return (free(hold), free (buffer), buffer = NULL, hold = NULL);
		buffer[b_readed] = '\0';
		hold = ft_strjoin(hold, buffer);
	}
	free (buffer);
	line = before_newline(hold);
	hold = after_newline(hold);
	return (line);
}

int	count_chars(char *filename)
{
	int		fd;
	int		char_num;
	int		byte_r;
	char	buffer[1024];

	fd = open ("map.ber", O_RDONLY);
	if (fd < 0)
		return (0);
	byte_r = 1;
	char_num = 0;
	while (byte_r >= 1)
	{
		byte_r = read (fd, buffer, 1);
		char_num += byte_r;
	}
	return (char_num);
}

int	count_lines(char *filename)
{
	int		fd;
	char	*buffer;
	int		i;
	int		x;
	int		byte_read;

	buffer = malloc (count_chars(filename));
	if (buffer == NULL)
		return (0);
	fd = open ("map.ber", O_RDONLY);
	i = 0;
	x = 1;
	byte_read = read(fd, buffer, count_chars(filename));
	if (byte_read <= 0)
	{
		free (buffer);
		return (0);
	}
	while (buffer[i] != '\0')
	{
		if (buffer[i++] == '\n')
			x += 1;
	}
	free (buffer);
	return (x);
}

// int main ()
// {
// 	printf("%d", count_lines("map.ber"));
// }
// int main ()
// {
// 	int fd = open ("map.ber", O_RDWR);
// 	char	**buffer;
// 	int		i;
// 	int		x;

// 	i = 0;
// 	x = 0;
// 	while (get_next_line(fd) != NULL)
// 	{
// 		i++;
// 	}
// 	buffer = malloc (i * (sizeof(char *)));
// 	if (buffer == NULL)
// 		return (NULL);
// 	while (get_next_line(fd) != NULL)
// 	{
// 		buffer[x] = get_next_line(fd);
// 		x++;
// 	}
// }

// char test()
// {
// 	char	**buffer;
// 	int		i;
// 	int		x;

// 	i = 0;
// 	x = 0;
// 	while (get_next_line(fd) != NULL)
// 	{
// 		i++;
// 	}
// 	buffer = malloc (i * (sizeof(char *)));
// 	if (buffer == NULL)
// 		return (NULL);
// 	while (get_next_line(fd) != NULL)
// 	{
// 		buffer[x] = get_next_line(fd);
// 		x++;
// 	}
// }