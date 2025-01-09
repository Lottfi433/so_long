/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasserlotfi <yasserlotfi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:03:01 by yasserlotfi       #+#    #+#             */
/*   Updated: 2025/01/09 09:47:25 by yasserlotfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
int		ft_strchr(char *str);
int		ft_strlen(char *str);
char	*after_newline(char *str);
char	*before_newline(char *str);
int		count_chars(char *filename);
int		count_lines(char *filename);
char	**map_two_d(char **hold, char *mapname);
void	memmory_free(char **hold, int lines);
int		starting_ending_colect_checker(char **hold, char *mapname);
int		player_position_i(char **hold, char *mapname);
int		player_position_j(char **hold, char *mapname);
char	**flood(char **hold, int i, int j);
int		last_map_checking(char **hold, char *mapname);
int		map_checker(char *mapname);
#endif