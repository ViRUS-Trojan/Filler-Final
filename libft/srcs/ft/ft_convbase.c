/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:08:44 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/28 18:19:02 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_convbase(char *value, int old_base, int new_base)
{
	int		power;
	int		value_10;
	int		i;
	int		tmp;

	if (old_base < 2 || old_base > 16 || !value)
		return (NULL);
	power = 1;
	value_10 = 0;
	tmp = 0;
	i = ft_strlen(value) - 1;
	while (i >= 0)
	{
		tmp = value[i] - 48;
		if (value[i] >= 'A' && value[i] <= 'F')
			tmp = value[i] - 55;
		else if (value[i] == '-')
			tmp = 0;
		value_10 = value_10 + tmp * power;
		power = power * old_base;
		i--;
	}
	if (value[0] == '-')
		return (ft_itoa_base((-1) * value_10, new_base));
	return (ft_itoa_base(value_10, new_base));
}
