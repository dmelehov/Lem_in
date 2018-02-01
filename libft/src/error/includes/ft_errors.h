/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:19:14 by dmelehov          #+#    #+#             */
/*   Updated: 2018/01/30 18:07:34 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# define M_ERROR(er_code, er_msg) ft_error_mngr(er_code, er_msg)
# define D_ERROR(er_code, er_msg) ft_debug_error_mngr(er_code, er_msg)

void	ft_error_mngr(int num, char *error_msg);
void	ft_debug_error_mngr(int er_code, char *error_msg);

#endif
