/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:40 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/11 16:06:52 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **head_a, int flag)
{
	t_list	*suiv;
	t_list	*prev;

	if (!*head_a || !head_a)
		return ;
	suiv = *head_a;
	prev = *head_a;
	if (suiv->next != NULL)
	{
		while (suiv->next != NULL)
			suiv = suiv->next;
		suiv->next = prev;
		*head_a = prev->next;
		prev->next = NULL;
		if (flag == 1)
			ft_printf("ra\n");
	}
}

void	rotate_b(t_list **head_b, int flag)
{
	t_list	*suiv;
	t_list	*prev;

	if (!*head_b || !head_b)
		return ;
	suiv = *head_b;
	prev = *head_b;
	if (suiv->next != NULL)
	{
		while (suiv->next != NULL)
			suiv = suiv->next;
		suiv->next = prev;
		*head_b = prev->next;
		prev->next = NULL;
		if (flag == 1)
			ft_printf("rb\n");
	}
}

void	rotate_r(t_list **head_a, t_list **head_b, int flag)
{
	if (!*head_a || !*head_b || head_a || head_b)
		return ;
	rotate_b(head_b, flag);
	rotate_a(head_a, flag);
	if (flag == 1)
		ft_printf("rr\n");
}
