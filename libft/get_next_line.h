/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:27:52 by yloutfi           #+#    #+#             */
/*   Updated: 2023/08/25 02:45:43 by anaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>  
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_len(char *str);
int		m_memchr(char *str, int c, int n);
char	*m_strdup(char *s1);
char	*strjoin(char *s1, char *s2);
char	*substr(char *str, int start, int len);

#endif
