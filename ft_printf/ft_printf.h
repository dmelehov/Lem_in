/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:04:31 by dmelehov          #+#    #+#             */
/*   Updated: 2017/10/17 08:21:08 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "../libft/includes/libft.h"

# define RESERVED "# 0-+'*$hljtzLcCsSdDioOuUxXpfFaAeEgGn1234567890."
# define FLAGS "# 0-+'*$"
# define LENGHT "hljtzL"
# define CONVERT "cCsSdDioOuUxXpfFaAeEgGn"
# define ESC_SEQ "\n\t\r\v\b\f\a"
# define NRG {0,"\0",'\0','\0','\0','\0','\0','\0','\0','\0','c','\0',-1,-1,0}

typedef struct	s_argdata
{
	int			arg_num;
	char		*form_input;
	char		hash;
	char		space;
	char		zero;
	char		plus;
	char		minus;
	char		apostrophe;
	char		star;
	char		dollar;
	char		conversion;
	char		lenght;
	int			size;
	int			precision;
	int			ans;
}				t_argdata;

/*
** supported function management
*/

int				ft_printf(const char *format, ...);
int				ft_vprintf(char const *format, va_list ap);
int				ft_dprintf(int fd, char const *format, ...);
int				ft_vdprintf(int fd, char const *format, va_list ap);
int				ft_sprintf(char *s, char const *format, ...);
int				ft_snprintf(char *s, size_t size, char const *format, ...);
int				ft_asprintf(char **ret, char const *format, ...);
int				ft_vsprintf(char *s, char const *format, va_list ap);
int				ft_vsnprintf(char *s, size_t size,
	char const *format, va_list ap);
int				ft_vasprintf(char **s, char const *format, va_list ap);

/*
** ft_fillstruct.c
*/

int				ft_updateprecision(char *s);
char			*ft_updatelenght(char *s, t_argdata *data);
char			*ft_updateflag(char *s, t_argdata *data);
char			*ft_updateints(t_argdata *data, char *s, int i);
void			ft_fillstruct(t_argdata *data);

/*
** ft_support_functions_1.c
*/

char			*ft_append(char *s1, char *s2, int i);
char			*ft_capitalizer(char *s);
int				ft_findintlen(uintmax_t t, int b);
char			*ft_uitoa(uintmax_t t, int b);
char			*ft_checkneg(intmax_t t, int b);

/*
** ft_support_functions_2.c
*/

int				ft_str_isin(char *big, char *little);
int				ft_nonums_after(char *s);
char			*ft_cut_zero(char *s, int len, t_argdata *data);
char			*ft_revstr(char *str);
void			ft_free_2d_arr(char **arr);

/*
** ft_flagmanagement.c
*/

char			*ft_apply_apostrophe(char *str, t_argdata *data);
char			*ft_apply_hash(char *s, t_argdata *data);
char			*ft_apply_zero(char *s, t_argdata *data, int neg);
void			ft_update_flag_values(t_argdata *data, int neg);
char			*ft_apply_flags(char *s, t_argdata *data, int neg);

/*
** ft_modifyers_management.c
*/

char			*ft_apply_lenght_di(intmax_t t, int base, t_argdata *data);
char			*ft_apply_lenght_uox(t_argdata *data, uintmax_t t, int base);
char			*ft_apply_precision(char *s, t_argdata *data);
char			*ft_apply_size(char *s, t_argdata *data, char *t);
char			*ft_apply_modifyers(char *s, t_argdata *data);

/*
** ft_formatparsing_additional.c
*/

void			ft_nullcharprint(char *str, t_argdata *data, char **s);
char			*ft_getformat(char *format, t_argdata *data);
t_argdata		*ft_get_argdata(t_argdata *data,
	char *format, int argnum, int ans);
int				ft_getstarvalue(va_list *ap, t_argdata *data);
void			ft_apply_star(va_list *ap, t_argdata *data);

/*
** ft_parse_colors.c
*/

int				ft_check_color(char *format, char **s, int *ans);
char			**ft_get_color(void);
char			**ft_match_color(void);
void			ft_free_struct(t_argdata *data);

/*
** ft_parse_floats.c
*/

char			*ft_parse_floats(long double d, t_argdata *data);
char			*ft_dtoa(long double d, char *s, t_argdata *data);
char			*ft_exponent(long double d, char *s, t_argdata *data, int exp);
char			*ft_check_infinity(long double f);
char			*g_cv_switcher(long double d,
	t_argdata *data, char *s, int exp);

/*
** ft_formatparsing.c
*/

int				ft_create_func_arr(char *format, va_list ap, char **s);
int				ft_formatparser(char *format,
	va_list ap, char **s, void const *functions[]);
int				ft_get_prefix(char *format, char **s, int *ans);
int				ft_argparser(t_argdata *data,
	va_list *ap, char **s, void const *functions[]);
void			ft_apply_funct(va_list *ap,
	t_argdata *data, char *func(va_list *, t_argdata *), char **s);

/*
** ft_round_floats.c
*/

long double		ft_round_fraction(long double t);
long double		ft_round_down(long double t);
long double		ft_round_up(long double t);
char			*ft_round_dec_string(char *s, int len);
char			*ft_get_rounded_str(long double x, char *s);

/*
** ft_parse_floats2.c
*/

char			*ft_get_whole_part(long double x, char *s, t_argdata *data);
int				ft_check_nine(long double x, int prec);
int				ft_find_exp_value(long double x);
long double		ft_normalize_float(long double x, int exp);
int				ft_check_normalize(long double x, int p);
char			*ft_conv_wchar(wchar_t v);

/*
** ft_parse_a.c
*/

char			*ft_parse_a(long double d, t_argdata *data, char *s);
long double		ft_get_a_exp(long double x, int *exp, int base);
char			*ft_get_fract_part_a(long double x, char *s, t_argdata *data);
char			*ft_round_hexdec(char *s, int i, int j);
void			ft_iter_hexdec(char *s);

/*
** supported conversions
*/

char			*ft_cv_p(va_list *ap, t_argdata *data);
char			*ft_cv_o(va_list *ap, t_argdata *data);
char			*ft_cv_lo(va_list *ap, t_argdata *data);
char			*ft_cv_x(va_list *ap, t_argdata *data);
char			*ft_cv_lx(va_list *ap, t_argdata *data);
char			*ft_cv_d(va_list *ap, t_argdata *data);
char			*ft_cv_ld(va_list *ap, t_argdata *data);
char			*ft_cv_i(va_list *ap, t_argdata *data);
char			*ft_cv_u(va_list *ap, t_argdata *data);
char			*ft_cv_lu(va_list *ap, t_argdata *data);
char			*ft_cv_c(va_list *ap, t_argdata *data);
char			*ft_cv_wc(va_list *ap, t_argdata *data);
char			*ft_cv_s(va_list *ap, t_argdata *data);
char			*ft_cv_ws(va_list *ap, t_argdata *data);
char			*ft_cv_f(va_list *ap, t_argdata *data);
char			*ft_cv_bf(va_list *ap, t_argdata *data);
char			*ft_cv_e(va_list *ap, t_argdata *data);
char			*ft_cv_be(va_list *ap, t_argdata *data);
char			*ft_cv_n(va_list *ap, t_argdata *data);
char			*ft_cv_g(va_list *ap, t_argdata *data);
char			*ft_cv_bg(va_list *ap, t_argdata *data);
char			*ft_cv_a(va_list *ap, t_argdata *data);
char			*ft_cv_ba(va_list *ap, t_argdata *data);
void			ft_printlist(t_argdata *data);

#endif
