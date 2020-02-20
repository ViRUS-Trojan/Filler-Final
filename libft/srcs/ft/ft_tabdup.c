/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 03:16:34 by vdelsie           #+#    #+#             */
/*   Updated: 2020/02/20 03:16:35 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	char	**rslt;
	int		len;
	int		i;

	if (!tab)
		return (NULL);
	len = ft_tablen(tab);
	if (!(rslt = (char **)malloc(sizeof(*rslt) * (len + 1))))
		ft_exit("malloc error", 1);
	i = 0;
	while (tab[i])
	{
		rslt[i] = ft_strdup(tab[i]);
		i++;
	}
	rslt[len] = NULL;
	return (rslt);
}
