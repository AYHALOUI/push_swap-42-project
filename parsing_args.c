/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:15:26 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/11 17:30:59 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_is_empty_string(char *str)
{
	return (!(*str));
}

int	check_if_plus_mins(char *str)
{
	if (!ft_strncmp(str, "-", 2) || !ft_strncmp(str, "+", 2))
		return (1);
	return (0);
}

int	check_is_contain_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (!ft_isdigit(str[i]) && str[i] != '\0' && str[i] != ' ')
		return (1);
	else
		return (0);
}

void	check_is_valide_string(int ac, char *str)
{
	if (ac < 2)
		quit();
	if (check_is_empty_string(str))
		quit();
	else if (check_is_contain_all_space(str))
		quit();
	else if (check_if_plus_mins(str))
		quit();
	else if (check_is_digit(str))
		quit();
}
