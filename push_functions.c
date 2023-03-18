/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:59 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/06 15:52:53 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **head_a, t_list **head_b, int flag)
{
	t_list	*temp;

	temp = *head_b;
	if (temp != NULL)
	{
		*head_b = temp->next;
		temp->next = *head_a;
		*head_a = temp;
		if (flag == 1)
			ft_printf("pa\n");
	}
}

void	push_b(t_list **head_a, t_list **head_b, int flag)
{
	t_list	*temp;

	temp = *head_a;
	if (temp != NULL)
	{
		*head_a = temp->next;
		temp->next = *head_b;
		*head_b = temp;
		if (flag == 1)
			ft_printf("pb\n");
	}
}
