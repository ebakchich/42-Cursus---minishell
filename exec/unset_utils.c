/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyahya <yoyahya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:03:21 by yoyahya           #+#    #+#             */
/*   Updated: 2023/02/28 14:38:13 by yoyahya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (1);
	while (str[i])
	{
		if (str[i] != '_')
		{
			if (i == 0 && (ft_isdigit(str[i])))
				return (1);
			if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	unset_err(char *str, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("minishell: unset: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	else if (flag == 2)
		ft_putstr_fd("minishell: error in malloc\n", 2);
	return (1);
}
