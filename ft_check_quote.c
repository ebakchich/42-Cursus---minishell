/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:48:03 by ebakchic          #+#    #+#             */
/*   Updated: 2023/02/02 20:34:23 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quote(char **full_cmd)
{
	int	i;
	int	j;

	i = 0;
	while (full_cmd[i])
	{
		if (ft_chrafterr(full_cmd[i], ft_strlen(full_cmd[i])) == 0)
		{
			printf("Parse error: Unclosed Quotes\n");
			return (1);
		}
		i++;
	}
	return (0);
}
