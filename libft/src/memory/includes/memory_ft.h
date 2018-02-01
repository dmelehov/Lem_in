/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_ft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:25:08 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/30 15:39:56 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_FT_H
# define MEMORY_FT_H

/*
** fill with 0 a memory area of size n bytes from pointer s
*/

void					ft_bzero(void *s, size_t n);

/*
** allocates an initialized to 0 memory and return a pointer to it
*/

void					*ft_memalloc(size_t size);

/*
** copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char)
** occurs in the string src,
** the copy stops and a pointer to the byte after the copy of c
** in the string dst is returned.
** Otherwise, n bytes are copied, and a NULL pointer is returned.
*/

void					*ft_memccpy(void *d, const void *s, int c, size_t n);

/*
** locates the first occurrence of c (converted to an unsigned char) in string s
** returns a pointer to the byte located,
** or NULL if no such byte exists within n bytes.
*/

void					*ft_memchr(const void *s, int c, size_t n);

/*
** compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
** returns zero if the two strings are identical,
** otherwise returns the difference between
** the first two differing bytes
*/

int						ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** function copies n bytes from memory area src to memory area dst
*/

void					*ft_memcpy(void *dst, const void *src, size_t n);

/*
** free the memory area and set it pointer to NULL
** overlap is undefined
*/

void					ft_memdel(void **ap);

/*
** function copies len bytes from string src to string dst
** overlap supported
*/

void					*ft_memmove(void *dst, const void *src, size_t len);

/*
** writes len bytes of value c (converted to an unsigned char) to the string b
*/

void					*ft_memset(void *b, int c, size_t len);

/*
** change the size of the allocation pointed to by ptr to size, and returns ptr
*/

void					*ft_realloc(void *ptr, size_t size);

/*
** allocate a memory for nbr elements of choosen size
*/

void					*ft_malloc_s(size_t nbr, size_t size);

/*
** reallocate a memory for nbr elements of choosen size
*/

void					*ft_realloc_s(void *ptr, size_t nbr, size_t size);

/*
** free allocated memory
*/

void					ft_free_s(void **ptr);

/*
** free 2d array
*/

void					ft_free_2d_array(void **data);

#endif
