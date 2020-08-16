/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:32:18 by torange           #+#    #+#             */
/*   Updated: 2020/08/11 19:45:03 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define BUFF_SIZE 1

# define FT_INT_MAX		((int)(FT_UINT_MAX >> 1))
# define FT_INT_MIN		((int)(~FT_INT_MAX))
# define FT_UINT_MAX	((unsigned)(~0L))
# define IS_NOT_INT 99999

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *dest, int c, size_t len);
char				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nw);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstaddback(t_list **alst, t_list *nw);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
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
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strnew(size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strlwr(char *s);
char				*ft_strupr(char *s);
char				*ft_strrev(char *str);
char				*ft_strchrs(const char *s, int c);
char				*ft_strsubchr(const char *s, char c);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
size_t				ft_strnlen(const char *s, size_t maxlen);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
void				ft_swap(int *a, int *b);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
int					ft_abs(int i);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_arrlen(char **arr);

char				*ft_cap_lftoa(long double n, int precision);
void				ft_cap_lftoa_add_number(int *i, char **result, \
										long double *f_part);
int					ft_cap_lftoa_rounding(long double f_part_c, int precision, \
	long double *f_part, long long *i_part);
void				ft_cap_lftoa_set_other_nums(int i, char **result);
void				ft_strup(char *tmp);
long long			ft_llabs(long long n);
char				*ft_ulltoa_base(unsigned long long value, int base);
char				*ft_lltoa(long long n);
int					get_next_line(const int fd, char **line);
long				ft_isint(char *str);
long				ft_atol(const char *str);
int					ft_isnbr(char *str);
int					ft_numlen(int a);

#endif
