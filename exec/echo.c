/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:10:28 by yoyahya           #+#    #+#             */
/*   Updated: 2023/03/02 18:44:15 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	countn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
			i++;
		if (str[i] != 'n')
			return (i);
		i++;
	}
	return (i);
}

void	echo_print(char **str, int i)
{
	while (str[i])
	{
		if (str[i][0])
			write(1, str[i], ft_strlen(str[i]));
		if (str[i + 1])
			write(1, " ", 1);
		i++;
	}
}

int	echo(char **str)
{
	int	i;
	int	line;

	line = 1;
	i = 1;
	while (str[i])
	{
		if (ft_strncmp(str[i], "-n", 2) == 0 && \
					(countn(str[i]) == (int)ft_strlen(str[i])))
			line = 0;
		else
		{
			echo_print(str, i);
			break ;
		}
		i++;
	}
	if (line == 1)
		write(1, "\n", 1);
	return (0);
}
