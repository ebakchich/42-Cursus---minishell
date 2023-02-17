/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:13:31 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/18 00:26:21 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char *p, char **p2)
{
	int	i;

	i = 0;
	i = 0;
	if (p2 != NULL)
	{
		while (p2[i])
			i++;
		if (i == 1)
			free(p2);
		else
		{	
			while (p2[i])
			{
				free(p2[i]);
				i++;
			}
			free(p2);
		}
	}
	if (p != NULL)
		free(p);
}