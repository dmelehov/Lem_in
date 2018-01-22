/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_ft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:57:19 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/05 19:54:40 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_FT_H
# define STRING_FT_H

/*
** convert a digit passed as a string to integer
*/

int						ft_atoi(const char *str);

/*
** convert an integer value to a string
*/

char					*ft_itoa(int n);

/*
** concatenate two strings
*/

char					*ft_strcat(char *s1, const char *s2);

/*
** find occurance of c in s and return a pointer on it. else return NULL
*/

char					*ft_strchr(const char *s, int c);

/*
** fill a string with '\0'
*/

void					ft_strclr(char *s);

/*
** compare two strings. return difference between not equal bytes or
** zero if the strings are equal
*/

int						ft_strcmp(const char *s1, const char *s2);

/*
** copy from src string to dest string
*/

char					*ft_strcpy(char *dst, const char *src);

/*
** free allocated memory and set a pointer to NULL
*/

void					ft_strdel(char **as);

/*
** duplicate and return a fresh string
*/

char					*ft_strdup(const char *s1);

/*
** compare two strings. return 1 if they are equal. else return 0
*/

int						ft_strequ(char const *s1, char const *s2);

/*
** apply given function to each element of a string
*/

void					ft_striter(char *s, void (*f)(char *));

/*
** apply given function to each element of a string
*/

void					ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** return fresh concatenated string
*/

char					*ft_strjoin(char const *s1, char const *s2);

/*
** concatenated strings
*/

size_t					ft_strlcat(char *dst, const char *src, size_t size);

/*
** return length of the string
*/

size_t					ft_strlen(const char *s);

/*
** apply given function to each element of a string
*/

char					*ft_strmap(char const *s, char (*f)(char));

/*
** apply given function to each element of a string
*/

char					*ft_strmapi(char *s, char (*f)(unsigned int, char));

/*
** concatenated strings but not more then n bytes
*/

char					*ft_strncat(char *s1, const char *s2, size_t n);

/*
** compare strings but not more then n bytes
*/

int						ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** copy strings but not more then n bytes
*/

char					*ft_strncpy(char *dst, const char *src, size_t len);

/*
** compare strings but not more then n bytes
*/

int						ft_strnequ(char const *s1, char const *s2, size_t n);

/*
** allocate a fresh string with given size
*/

char					*ft_strnew(size_t size);

/*
** check occurance little in big string but only len bytes
** return a pointer on the first symbol of occurance
*/

char					*ft_strnstr(const char *big, char *little, size_t len);

/*
** return a pointer to first occurance of c in s
** starting from end of the string
*/

char					*ft_strrchr(const char *s, int c);

/*
** create 2d array by spliting s by c symbol
*/

char					**ft_strsplit(char const *s, char c);

/*
** check occurance little in big string.
** return a pointer on the first symbol of occurance
*/

char					*ft_strstr(const char *big, const char *little);

/*
** return fresh substring cuted from s
*/

char					*ft_strsub(char const *s,
							unsigned int start, size_t len);

/*
** cut whitespaces (' ', '\n', '\t') at the start and end of te string
** and return a fresh modified string
*/

char					*ft_strtrim(char const *s);

/*
** copy size bytes from src to dst
*/

size_t					ft_strlcpy(char *dst, const char *src, size_t size);

#endif
