/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size_bonus_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:49:35 by rde-mour          #+#    #+#             */
/*   Updated: 2026/10/06 22:24:05 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "utest.h"

static void	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

UTEST(ft_list_size, null_list)
{
	ASSERT_EQ(ft_list_size(NULL), 0);
}

UTEST(ft_list_size, empty_list)
{
	t_list	*list = NULL;

	ASSERT_EQ(ft_list_size(list), 0);
}

UTEST(ft_list_push_front, list_three_size)
{
	const int	values[] = { 1, 2, 3};
	t_list *list = NULL;

	ft_list_push_front(&list, (void *) &values[0]);
	ft_list_push_front(&list, (void *) &values[1]);
	ft_list_push_front(&list, (void *) &values[2]);

	ASSERT_EQ(ft_list_size(list), 3);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_push_front, list_hundred_size)
{
	int		values[100];
	t_list	*list = NULL;

	for (int i = 0; i < 100; i++)
	{
		values[i] = i;
		ft_list_push_front(&list, &values[i]);
	}

	ASSERT_EQ(ft_list_size(list), 100);

	t_list	*tmp = NULL;
	for (int i = 0; i < 100; i++)
	{
		ASSERT_NE(list, NULL);
		ASSERT_EQ(list->data, &values[99 - i]);
		tmp = list->next;
		free(list);
		list = tmp;
	}

	ASSERT_EQ(list, NULL);
}
