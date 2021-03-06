/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:58:25 by edjavid           #+#    #+#             */
/*   Updated: 2021/06/28 16:21:08 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

void		ft_bzero(void *s, size_t n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strcat(char *dest, const char *src);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_itoa(int n);
#endif
