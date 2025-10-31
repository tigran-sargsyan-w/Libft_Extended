/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsargsya <tsargsya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:10:42 by tsargsya          #+#    #+#             */
/*   Updated: 2025/11/01 00:03:13 by tsargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_pow10(int exponent)
{
	double	result;

	result = 1.0;
	if (exponent > 0)
	{
		while (exponent-- > 0)
			result *= 10.0;
	}
	else if (exponent < 0)
	{
		while (exponent++ < 0)
			result /= 10.0;
	}
	return (result);
}

static const char	*read_digits(const char *str_pointer,
								long double *mantissa,
								int *count, int *has_digits)
{
	while (*str_pointer && ft_isdigit((unsigned char)*str_pointer))
	{
		*mantissa = (*mantissa * 10.0L) + (long double)(*str_pointer - '0');
		str_pointer++;
		if (count)
			(*count)++;
		*has_digits = 1;
	}
	return (str_pointer);
}

static const char	*read_exp(const char *pointer, int has_digits, int *exp10)
{
	const char	*save;
	int			exponent_sign;
	int			exponent_value;

	if (!(has_digits && (*pointer == 'e' || *pointer == 'E')))
		return (pointer);
	save = pointer;
	pointer++;
	exponent_sign = 1;
	if (*pointer == '+' || *pointer == '-')
	{
		if (*pointer == '-')
			exponent_sign = -1;
		pointer++;
	}
	exponent_value = 0;
	if (!ft_isdigit((unsigned char)*pointer))
		return (save);
	while (*pointer && ft_isdigit((unsigned char)*pointer))
	{
		exponent_value = (exponent_value * 10) + (*pointer - '0');
		pointer++;
	}
	*exp10 += exponent_sign * exponent_value;
	return (pointer);
}

static const char	*read_ws_sign(const char *pointer, int *sign)
{
	while (*pointer && ft_isspace((unsigned char)*pointer))
		pointer++;
	*sign = 1;
	if (*pointer == '+' || *pointer == '-')
	{
		if (*pointer == '-')
			*sign = -1;
		pointer++;
	}
	return (pointer);
}

double	ft_strtod(const char *nptr, char **endptr)
{
	const char		*pointer;
	int				sign;
	t_strtod_state	state;

	pointer = read_ws_sign(nptr, &sign);
	state.m = 0.0L;
	state.frac = 0;
	state.has = 0;
	pointer = read_digits(pointer, &state.m, NULL, &state.has);
	if (*pointer == '.')
	{
		pointer = read_digits(pointer + 1, &state.m, &state.frac, &state.has);
	}
	state.exp10 = -state.frac;
	pointer = read_exp(pointer, state.has, &state.exp10);
	if (!state.has)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0.0);
	}
	if (endptr)
		*endptr = (char *)pointer;
	return ((double)(sign * state.m * (long double)ft_pow10(state.exp10)));
}
