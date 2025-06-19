/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:01:58 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/19 15:43:04 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// note: This function does not support scientific notation yet.

#include "ft_atof.h"

static void	init_atof_data(t_atof *data)
{
	data->result = 0;
	data->frac = 0.0;
	data->divider = 1.0;
	data->sign = 1;
	data->i = 0;
}

static double	check_overflow(double nbr, int sign)
{
	if (nbr > DBL_MAX)
	{
		if (sign == 1)
			return (INFINITY);
		else
			return (-INFINITY);
	}
	return (nbr);
}

static void	handle_frac(t_atof *data, const char *nbr)
{
	if (nbr[data->i] == '.')
	{
		data->i++;
		while (nbr[data->i] && ft_isdigit(nbr[data->i]))
		{
			data->frac = data->frac * 10.0 + (nbr[data->i++] - '0');
			data->divider *= 10.0;
		}
	}
}

double	ft_atof(const char *nbr)
{
	t_atof	data;

	init_atof_data(&data);
	while (ft_isspace(nbr[data.i]))
		data.i++;
	if (nbr[data.i] == '+' || nbr[data.i] == '-')
	{
		if (nbr[data.i] == '-')
			data.sign = -1;
		data.i++;
	}
	while (ft_isdigit(nbr[data.i]))
	{
		data.result = data.result * 10.0 + (nbr[data.i] - '0');
		data.result = check_overflow(data.result, data.sign);
		data.i++;
	}
	handle_frac(&data, nbr);
	data.frac /= data.divider;
	data.result += data.frac;
	data.result = check_overflow(data.result, data.sign);
	return (data.result * data.sign);
}
