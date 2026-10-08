/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front_bonus_test.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:49:35 by rde-mour          #+#    #+#             */
/*   Updated: 2026/10/04 07:58:25 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "utest.h"

UTEST(ft_list_push_front, null_data)
{
	t_list *list = NULL;

	ft_list_push_front(&list, NULL);
	ASSERT_EQ((int *) list->data, NULL);

	free(list);
}

UTEST(ft_list_push_front, add_elements_order)
{
	const int	values[] = { 1, 2, 3};
	t_list *list = NULL;

	ft_list_push_front(&list, (void *) &values[0]);
	ASSERT_EQ((int *) list->data, &values[0]);

	ft_list_push_front(&list, (void *) &values[1]);
	ASSERT_EQ((int *) list->data, &values[1]);
	ASSERT_EQ((int *) list->next->data, &values[0]);

	ft_list_push_front(&list, (void *) &values[2]);
	ASSERT_EQ((int *) list->data, &values[2]);
	ASSERT_EQ((int *) list->next->data, &values[1]);
	ASSERT_EQ((int *) list->next->next->data, &values[0]);

	t_list	*tmp = NULL;
	for (int i = 0; i < 3; i++)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}

	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_push_front, preserve_existing_list)
{
	const int values[] = { 1, 2 };
	t_list *list = NULL;

	ft_list_push_front(&list, (void *) &values[0]);

	t_list *old_head = list;

	ft_list_push_front(&list, (void *) &values[1]);

	ASSERT_EQ(list->data, (void *) &values[1]);
	ASSERT_EQ(list->next, old_head);
	ASSERT_EQ(old_head->data, (void *) &values[0]);
	ASSERT_EQ(old_head->next, NULL);

	t_list	*tmp = NULL;
	for (int i = 0; i < 2; i++)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}

	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_push_front, many_elements)
{
	int		values[100];
	t_list	*list = NULL;

	for (int i = 0; i < 100; i++)
	{
		values[i] = i;
		ft_list_push_front(&list, &values[i]);
	}

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
