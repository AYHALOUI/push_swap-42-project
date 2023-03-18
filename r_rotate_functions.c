/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:49 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/11 17:41:56 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_list **head_a, int flag)
{
	t_list	*temp;
	t_list	*temp2;

	if (!*head_a || !head_a)
		return ;
	temp = *head_a;
	temp2 = *head_a;
	if (temp->next != NULL)
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = temp2;
		*head_a = temp->next;
		temp->next = NULL;
		if (flag == 1)
			ft_printf("rra\n");
	}
}

void	r_rotate_b(t_list **head_b, int flag)
{
	t_list	*temp;
	t_list	*temp2;

	if (!*head_b || !head_b)
		return ;
	temp = *head_b;
	temp2 = *head_b;
	if (temp->next != NULL)
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = temp2;
		*head_b = temp->next;
		temp->next = NULL;
		if (flag == 1)
			ft_printf("rrb\n");
	}
}

void	r_rotate_r(t_list **head_a, t_list **head_b, int flag)
{
	if (!*head_a || !*head_b || head_a || head_b)
		return ;
	r_rotate_a(head_a, flag);
	r_rotate_b(head_b, flag);
	if (flag == 1)
		ft_printf("rrr\n");
}
