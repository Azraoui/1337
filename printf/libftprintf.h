/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:37:48 by ael-azra          #+#    #+#             */
/*   Updated: 2019/12/15 20:29:50 by ael-azra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

struct					s_flags
{
	int					zero;
	long				digits;
	int					precision;
	int					width;
	int					align;
	char				conversion;
};

int						ft_printf(const char *str, ...);
void					ft_putstr(char *str);
int						ft_putchar(char c, int d);
size_t					ft_strlen(const char *str);
char					ft_strchr(const char *s, int c);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2);
int						ft_printconversion(const char *str, va_list args,
						int i);
struct s_flags			ft_findflagsandconversion(const char *str,
						int *i, va_list args);
char					ft_isdigit(char c);
int						ft_atoi(const char *str);
char					*ft_itoa(long n);
char					dec_hex(char s, char c, unsigned long nb);
char					*ft_itoa_hexa(char c, unsigned long nb,
						char (*dec_hex)(char, char, unsigned long));
int						ft_hexa(unsigned int nb, char c);
void					ft_putnbr(int n);
void					u_putnbr(unsigned int nb);
int						flagzero(const char *str, int *i);
int						flagalign(const char *str, int *i);
int						flagdigits(const char *str, int *i);
int						flagwidth(const char *str, int *i, va_list args);
int						flagprecision(const char *str, int *i, va_list args);
char					find_conversion(const char *str, int *i);
int						print_format(struct s_flags flag, va_list args);
void					print_space(int *x, long nb, char *s, char c);
int						c_format(struct s_flags flag, va_list args);
int						s_format(struct s_flags flag, va_list args);
int						d_format(struct s_flags flag, va_list args);
int						i_format(struct s_flags flag, va_list args);
int						u_format(struct s_flags flag, va_list args);
int						x_format(struct s_flags flag, va_list args);
int						p_format(struct s_flags flag, va_list args);
int						print_precision(char **s, int p, size_t len);
void					print_space_2(struct s_flags flag, long i,
						char *s, char c);
int						print_precision_2(long nb, int pr);
int						percent_format(struct s_flags flag);
int						print_precision_hexa(unsigned long nb, int pr, char c);
int						cheack_flag_hexa(int i, struct s_flags flag,
						unsigned long nb, char c);
int						cheack_flag1_hexa(struct s_flags flag,
						unsigned long nb, char c);
int						cheack_flag(int i, struct s_flags flag,
						unsigned long nb, int sign);
char					*ft_strcat(char *dest, char *src);
int						cheack_flag_1(struct s_flags flag, long nb, int sign);

#endif
