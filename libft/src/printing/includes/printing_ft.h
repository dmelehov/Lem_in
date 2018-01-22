/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_ft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:22:31 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/17 20:53:51 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_FT_H
# define PRINTING_FT_H

/*
** print a character to the standart output
*/

void					ft_putchar(char c);

/*
** print a character to the given file descriptor
*/

void					ft_putchar_fd(char c, int fd);

/*
** print a string with a new line at end to the standart output
*/

void					ft_putendl(char const *s);

/*
** print a string with a new line at the end to the standart output
*/

void					ft_putendl_fd(char const *s, int fd);

/*
** print a number to the standart output
*/

void					ft_putnbr(int n);

/*
** print a number to the given file descriptor
*/

void					ft_putnbr_fd(int n, int fd);

/*
** print a string to the standart output
*/

void					ft_putstr(char const *s);

/*
** print a string to the given file descriptor
*/

void					ft_putstr_fd(char const *s, int fd);

/*
** print addres of a pointer
*/

void					ft_putaddr(void *addr);

#endif
