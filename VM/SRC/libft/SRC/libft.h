/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:35:19 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/29 07:21:10 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "./files.h/get_next_line.h"

unsigned char		*ft_strcpy_until_unsigned(unsigned char *dst, unsigned char *str, size_t i);
char				*ft_strcpy_unt_char(char *src, char c);
unsigned char		*ft_strcpy_unsigned(unsigned char *dst, unsigned char *src);
int					ft_strcmp_until(char *s1, char *s2, int lim);
void				ft_clean(char *str);
char				*ft_insert(char *str, int i, char *addon);
char				*ft_capitalize(char *str);
char				*ft_replace_char(char *str, int i, char c);
char				*ft_add_1stcharbool(char *str, int i, char c, char d);
char				*ft_add_1stchar(char *str, char c);
int					ft_pow(int value, int pow);
char				*ft_utoa_base(unsigned int value, int base);
char				*ft_itoa_base(int value, int base);
char				*ft_strdup_until(const char *s1, int i);
char				*ft_strcpy_until(char *str, size_t i);
size_t				ft_strchr_count(char *str, char c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst,
						const void *src, size_t n);
void				*ft_memccpy(void *dst,
						const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, char *src);
char				*ft_strncpy(char *dst, char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1,
						const char *s2, size_t n);
size_t				ft_strlcat(char *dst,
						const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_litoa(long long int n);
char				*ft_llitoa(long long int n);
char				*ft_sitoa(short int n);
char				*ft_ssitoa(char n);
char				*ft_ssutoa(unsigned char value, int base);
char				*ft_lutoa(unsigned long int value, int base);
char				*ft_llutoa(unsigned long long int value, int base);
char				*ft_sutoa(unsigned short int value, int base);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strjoinfree(char *s1, char *s2);
char				*ft_strclr_until(char *str, char c);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
#endif
