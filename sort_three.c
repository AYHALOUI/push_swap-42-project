/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:33:57 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/11 17:40:42 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list **head)
{
	t_list	*temp;
	int		result;

	temp = *head;
	result = temp->data;
	while (temp != NULL)
	{
		if (result < temp->data)
			result = temp->data;
		temp = temp->next;
	}
	return (result);
}

int	get_index_max(t_list **head, int max)
{
	t_list	*temp;
	int		i;

	temp = *head;
	i = 0;
	while (temp != NULL)
	{
		if (temp->data == max)
			return (i);
		temp = temp->next;
		i++;
	}
	return (0);
}

void	help_sort_three_1(t_list **head_a)
{
	if ((*head_a)->data > (*head_a)->next->data
		&& (*head_a)->next->data > (*head_a)->next->next->data)
	{
		swap_a(head_a, 1);
		r_rotate_a(head_a, 1);
	}
	else if ((*head_a)->data > (*head_a)->next->data
		&& (*head_a)->next->next->data > (*head_a)->next->data)
		rotate_a(head_a, 1);
}

void	help_sort_three(t_list **head_a, int index_node)
{
	if (index_node == 0)
		help_sort_three_1(head_a);
	else if (index_node == 1)
	{
		if ((*head_a)->data < (*head_a)->next->data
			&& (*head_a)->next->next->data < (*head_a)->next->data
			&& (*head_a)->next->next->data > (*head_a)->data)
		{
			r_rotate_a(head_a, 1);
			swap_a(head_a, 1);
		}
		else if ((*head_a)->data < (*head_a)->next->data
			&& (*head_a)->next->next->data < (*head_a)->next->data
			&& (*head_a)->data > (*head_a)->next->next->data)
			r_rotate_a(head_a, 1);
	}
	else if (index_node == 2)
		swap_a(head_a, 1);
}

void	sort_3(t_list **head_a)
{
	int	max;
	int	index_node;

	max = find_max(head_a);
	index_node = get_index_max(head_a, max);
	if (!is_nbr_sorted(head_a))
		help_sort_three(head_a, index_node);
}
