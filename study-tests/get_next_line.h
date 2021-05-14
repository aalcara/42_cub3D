/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:30:47 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/08 21:13:34 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE	1

# include <unistd.h>
# include <stdlib.h>

size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin_gnl(char *s1, char *s2);
char			*first_line(char *buffer);
char			*new_buffer(char *buffer);
int				has_new_line(char *marker);
int				get_next_line(int fd, char **line);

#endif
