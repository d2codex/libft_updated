/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:58:52 by diade-so          #+#    #+#             */
/*   Updated: 2025/06/19 15:04:33 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOF_H
# define FT_ATOF_H

#include "libft.h"
#include <math.h>
#include <float.h>

typedef struct	s_atof
{
	double	result;
	double	frac;
	double	divider;
	int	sign;
	int	i;
}	t_atof;

# endif
