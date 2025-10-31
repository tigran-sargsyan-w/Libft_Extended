/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:10:42 by tsargsya          #+#    #+#             */
/*   Updated: 2025/10/31 23:22:27 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_pow10(int exp)
{
	double	res;

	res = 1.0;
	if (exp > 0)
	{
		while (exp-- > 0)
			res *= 10.0;
	}
	else if (exp < 0)
	{
		while (exp++ < 0)
			res /= 10.0;
	}
	return (res);
}

static const char	*read_digits(
	const char *p,
	long double *m,
	int *cnt,
	int *has)
{
	while (*p && ft_isdigit((unsigned char)*p))
	{
		*m = (*m * 10.0L) + (long double)(*p - '0');
		p++;
		if (cnt)
			(*cnt)++;
		*has = 1;
	}
	return (p);
}

static const char	*read_exp(const char *p, int has_digits, int *exp10)
{
	const char	*save;
	int			expsign;
	int			expval;

	if (!(has_digits && (*p == 'e' || *p == 'E')))
		return (p);
	save = p;
	p++;
	expsign = 1;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			expsign = -1;
		p++;
	}
	expval = 0;
	if (!ft_isdigit((unsigned char)*p))
		return (save);
	while (*p && ft_isdigit((unsigned char)*p))
	{
		expval = (expval * 10) + (*p - '0');
		p++;
	}
	*exp10 += expsign * expval;
	return (p);
}

static const char	*read_ws_sign(const char *p, int *sign)
{
	while (*p && ft_isspace((unsigned char)*p))
		p++;
	*sign = 1;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			*sign = -1;
		p++;
	}
	return (p);
}

double	ft_strtod(const char *nptr, char **endptr)
{
	const char				*p;
	int						sign;
	t_strtod_state			s;

	p = read_ws_sign(nptr, &sign);
	s.m = 0.0L;
	s.frac = 0;
	s.has = 0;
	p = read_digits(p, &s.m, NULL, &s.has);
	if (*p == '.')
	{
		p = read_digits(p + 1, &s.m, &s.frac, &s.has);
	}
	s.exp10 = -s.frac;
	p = read_exp(p, s.has, &s.exp10);
	if (!s.has)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0.0);
	}
	if (endptr)
		*endptr = (char *)p;
	return ((double)(sign * s.m * (long double)ft_pow10(s.exp10)));
}
