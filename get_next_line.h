/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:05:10 by apylypen          #+#    #+#             */
/*   Updated: 2023/05/29 19:17:13 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*read_file(int fd, char *str);
char	*get_line(char *str);
char	*next_line(char *str);
char	*get_next_line(int fd);

#endif
