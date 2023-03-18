/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:39:20 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/06 15:07:24 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_list **head_a, t_list **head_b)
{
	int	mid;
	int	i;

	i = 0;
	while (ft_lstsize(*head_a) > 3)
	{
		mid = ft_lstsize(*head_a) / 2;
		while (get_position(head_a, i) > mid && get_position(head_a, i) != 0)
			r_rotate_a(head_a, 1);
		while (get_position(head_a, i) <= mid && get_position(head_a, i) != 0)
			rotate_a(head_a, 1);
		if (get_position(head_a, i) == 0)
			push_b(head_a, head_b, 1);
		i++;
	}
	if (ft_lstsize(*head_a) == 3)
		sort_3(head_a);
	push_a(head_a, head_b, 1);
	push_a(head_a, head_b, 1);
}
