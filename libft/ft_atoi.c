/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 13:22:33 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/05 18:07:22 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include "../push_swap.h"

static int	is_white_space(char c)
{
	if ((c >= '\t' && c <= '\r' ) || c == ' ' )
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	unsigned int		i;
	int					signe;
	unsigned long int	result;

	i = 0;
	result = 0;
	signe = 1;
	while (is_white_space(str[i]))
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			quit();
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	if ((result > 2147483648 && signe == -1)
		|| (result > 2147483647 && signe == 1))
		quit();
	return (result * signe);
}
