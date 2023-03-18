/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:24:19 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/06 14:43:00 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **head_a, int flag)
{
	int	temp;

	if (ft_lstsize(*head_a) < 2)
		return ;
	if ((*head_a)->next != NULL)
	{
		temp = (*head_a)->data;
		(*head_a)->data = (*head_a)->next->data;
		(*head_a)->next->data = temp;
		if (flag == 1)
			ft_printf("sa\n");
	}
}

void	swap_b(t_list **head_b, int flag)
{
	int	temp;

	if (ft_lstsize(*head_b) < 2)
		return ;
	if ((*head_b)->next != NULL)
	{
		temp = (*head_b)->data;
		(*head_b)->data = (*head_b)->next->data;
		(*head_b)->next->data = temp;
		if (flag == 1)
			ft_printf("sb\n");
	}
}

void	swap_a_swap_b(t_list **head_a, t_list **head_b, int flag)
{
	if (!*head_a || !*head_b || head_a || head_a)
		return ;
	swap_a(head_a, flag);
	swap_b(head_b, flag);
	if (flag == 1)
		ft_printf("ss\n");
}
