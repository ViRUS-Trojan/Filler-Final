/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 03:15:20 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/20 03:15:21 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_c(va_list arg, t_arg *current)
{
	if (!ft_strcmp(current->modif, "l"))
		return (ft_conv_bigc(arg, current));
	current->rslt = ft_memalloc(1);
	current->rslt[0] = (unsigned char)va_arg(arg, int);
	current->conv_len = 1;
	ft_apply_padding(current);
	return (0);
}
