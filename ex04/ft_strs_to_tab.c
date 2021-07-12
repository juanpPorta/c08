/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:13:37 by jporta            #+#    #+#             */
/*   Updated: 2021/07/12 20:10:53 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"
int	ft_len(char *p)
{
	int	i;
	int a;

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
	if (!(dest = malloc(ft_len(str) + 1)))
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

	if (!(list = malloc(sizeof(struct s_stock_str) * (ac + 1))))
		return (0);
	while (i < ac)
	{
		list[i].size = ft_len(av[i]);
		list[i].str = av[i];
		list[i].copy = ft_dup(av[i]);
	}
	list[i].str = "\0";
	return (list);
}

int main()
{
	char *lol[3];
	int i = 0;
	lol[0] = "yes";
	lol[1] = "yessaie";
	lol[2] = "hon hon gaston";
	t_stock_str *prout = ft_strs_to_tab(3, lol);
	while (prout[i].str)
	{
		printf("%d, %s, %s\n", prout[i].size, prout[i].str, prout[i].copy);
		i++;
	}
}