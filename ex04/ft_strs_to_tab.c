/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:13:37 by jporta            #+#    #+#             */
/*   Updated: 2021/07/14 16:24:18 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_len(char *p)
{
	int	i;
	int	a;

	i = 0;
	while (p[i] != '\0')
	{
		a++;
		i++;
	}
	return (a);
}

char	*ft_dup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(ft_len(str) + 1);
	if (!dest)
		return (dest);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*list;
	int			i;

	list = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!list)
		return (0);
	while (i < ac)
	{
		list[i].size = ft_len(av[i]);
		list[i].str = av[i];
		list[i].copy = ft_dup(av[i]);
		i++;
	}
	list[i].str = 0;
	return (list);
	free(list);
}
