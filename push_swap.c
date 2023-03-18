/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:45:16 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/11 17:37:32 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("data=> %d\t index => %d\n", temp->data, temp->index);
		temp = temp->next;
	}
}

void	sort(t_list **head_a, t_list **head_b)
{
	int	size;

	size = ft_lstsize(*head_a);
	if (size == 2)
		swap_a(head_a, 1);
	else if (size == 3)
		sort_3(head_a);
	else if (size <= 5)
		sort_5(head_a, head_b);
	else if (size > 5 && size <= 100)
		sort_all_size(head_a, head_b, 5);
	else
		sort_all_size(head_a, head_b, 8);
}

int	main(int ac, char **av)
{
	t_list	*head_a;
	t_list	*head_b;

	if (ac == 1)
		return (0);
	add_element(&head_a, ac, av);
	sort(&head_a, &head_b);
	free_list(&head_a);
	return (0);
}
