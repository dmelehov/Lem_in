/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype_ft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 17:07:06 by dmelehov          #+#    #+#             */
/*   Updated: 2017/12/29 09:33:30 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTYPE_FT_H
# define CTYPE_FT_H

/*
** return 1 if argument is a digit or letter
** else returned 0
*/

int						ft_isalnum(int c);

/*
** return 1 if argument is a letter
** else returned 0
*/

int						ft_isalpha(int c);

/*
** return 1 if argument is an ascii character
** else returned 0
*/

int						ft_isascii(int c);

/*
** return 1 if argument is a digit
** else returned 0
*/

int						ft_isdigit(int c);

/*
** return 1 if argument is a printable ascii character
** else returned 0
*/

int						ft_isprint(int c);

/*
** return 1 if argument is an uppercase letter
** else returned 0
*/

int						ft_isupper(int c);

/*
** return 1 if argument is an lowercase letter
** else returned 0
*/

int						ft_islower(int c);

/*
** if argument is uppercase letter
** set it to lowercase and return it
*/

int						ft_tolower(int c);

/*
** if argument is lowercase letter
** set it to uppercase and return it
*/

int						ft_toupper(int c);

#endif
