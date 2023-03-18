/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:31:45 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/07 19:40:16 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	index_list(t_list **head)
{
	t_list	*prev;
	t_list	*suiv;
	int		index_element;
	int		index;

	prev = *head;
	index = 0;
	while (prev != NULL)
	{
		suiv = *head;
		index_element = 0;
		while (suiv != NULL)
		{
			if (prev->data > suiv->data)
				index_element++;
			suiv = suiv->next;
		}
		prev->index = index_element;
		prev = prev->next;
	}
}

int	get_position(t_list **head, int index)
{
	t_list	*temp;
	int		position;

	temp = *head;
	position = 0;
	while (temp != NULL)
	{
		if (temp->index == index)
			return (position);
		position++;
		temp = temp->next;
	}
	return (position);
}

void	free_list(t_list **head)
{
	t_list	*prev;
	t_list	*suiv;

	prev = *head;
	while (prev != NULL)
	{
		suiv = prev->next;
		free(prev);
		prev = suiv;
	}
	*head = NULL;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
