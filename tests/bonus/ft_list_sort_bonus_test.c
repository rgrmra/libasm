/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort_bonus_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:49:35 by rde-mour          #+#    #+#             */
/*   Updated: 2026/10/06 22:21:32 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libasm.h"
#include "utest.h"

static int	asc(int a, int b)
{
	return a - b;
}

static int	desc(int a, int b)
{
	return b - a;
}

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

UTEST(ft_list_sort, null_list)
{
	ft_list_sort(NULL, &asc);

	ASSERT_TRUE(1);
}

UTEST(ft_list_sort, null_cmp)
{
	t_list	*list = NULL;

	ft_list_sort(&list, NULL);

	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, empty_list)
{
	t_list	*list = NULL;

	ft_list_sort(&list, &asc);

	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, one_element)
{
	const int	values[] = { 42 };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) &values[0]);

	ft_list_sort(&list, &asc);

	ASSERT_EQ(list->data, (void *) &values[0]);
	ASSERT_EQ(list->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, one_element_string)
{
	const char	*values[] = { "a" };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) values[0]);

	ft_list_sort(&list, &strcmp);

	ASSERT_EQ(list->data, (void *) values[0]);
	ASSERT_EQ(list->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, already_sorted)
{
	const int	values[] = { 1, 2, 3, 4, 5 };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) &values[4]);
	ft_list_push_front(&list, (void *) &values[3]);
	ft_list_push_front(&list, (void *) &values[2]);
	ft_list_push_front(&list, (void *) &values[1]);
	ft_list_push_front(&list, (void *) &values[0]);

	ft_list_sort(&list, &asc);

	ASSERT_EQ(list->data, (void *) &values[0]);
	ASSERT_EQ(list->next->data, (void *) &values[1]);
	ASSERT_EQ(list->next->next->data, (void *) &values[2]);
	ASSERT_EQ(list->next->next->next->data, (void *) &values[3]);
	ASSERT_EQ(list->next->next->next->next->data, (void *) &values[4]);
	ASSERT_EQ(list->next->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, already_sorted_string)
{
	const char	*values[] = { "a", "b", "c", "d", "e" };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) values[4]);
	ft_list_push_front(&list, (void *) values[3]);
	ft_list_push_front(&list, (void *) values[2]);
	ft_list_push_front(&list, (void *) values[1]);
	ft_list_push_front(&list, (void *) values[0]);

	ft_list_sort(&list, &strcmp);

	ASSERT_EQ(list->data, (void *) values[0]);
	ASSERT_EQ(list->next->data, (void *) values[1]);
	ASSERT_EQ(list->next->next->data, (void *) values[2]);
	ASSERT_EQ(list->next->next->next->data, (void *) values[3]);
	ASSERT_EQ(list->next->next->next->next->data, (void *) values[4]);
	ASSERT_EQ(list->next->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, reverse_order)
{
	const int	values[] = { 1, 2, 3, 4, 5 };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) &values[0]);
	ft_list_push_front(&list, (void *) &values[1]);
	ft_list_push_front(&list, (void *) &values[2]);
	ft_list_push_front(&list, (void *) &values[3]);
	ft_list_push_front(&list, (void *) &values[4]);

	ft_list_sort(&list, &asc);

	ASSERT_EQ(list->data, (void *) &values[0]);
	ASSERT_EQ(list->next->data, (void *) &values[1]);
	ASSERT_EQ(list->next->next->data, (void *) &values[2]);
	ASSERT_EQ(list->next->next->next->data, (void *) &values[3]);
	ASSERT_EQ(list->next->next->next->next->data, (void *) &values[4]);
	ASSERT_EQ(list->next->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, reverse_order_string)
{
	const char	*values[] = { "a", "b", "c", "d", "e" };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) values[0]);
	ft_list_push_front(&list, (void *) values[1]);
	ft_list_push_front(&list, (void *) values[2]);
	ft_list_push_front(&list, (void *) values[3]);
	ft_list_push_front(&list, (void *) values[4]);

	ft_list_sort(&list, &strcmp);

	ASSERT_EQ(list->data, (void *) values[0]);
	ASSERT_EQ(list->next->data, (void *) values[1]);
	ASSERT_EQ(list->next->next->data, (void *) values[2]);
	ASSERT_EQ(list->next->next->next->data, (void *) values[3]);
	ASSERT_EQ(list->next->next->next->next->data, (void *) values[4]);
	ASSERT_EQ(list->next->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, insert_at_head)
{
	const int	values[] = { 1, 2, 3 };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) &values[0]);
	ft_list_push_front(&list, (void *) &values[2]);
	ft_list_push_front(&list, (void *) &values[1]);

	ft_list_sort(&list, &asc);

	ASSERT_EQ(list->data, (void *) &values[0]);
	ASSERT_EQ(list->next->data, (void *) &values[1]);
	ASSERT_EQ(list->next->next->data, (void *) &values[2]);
	ASSERT_EQ(list->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, insert_at_head_string)
{
	const char	*values[] = { "a", "b", "c" };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) values[0]);
	ft_list_push_front(&list, (void *) values[2]);
	ft_list_push_front(&list, (void *) values[1]);

	ft_list_sort(&list, &strcmp);

	ASSERT_EQ(list->data, (void *) values[0]);
	ASSERT_EQ(list->next->data, (void *) values[1]);
	ASSERT_EQ(list->next->next->data, (void *) values[2]);
	ASSERT_EQ(list->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, insert_in_middle)
{
	const int	values[] = { 1, 2, 3, 4 };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) &values[3]);
	ft_list_push_front(&list, (void *) &values[0]);
	ft_list_push_front(&list, (void *) &values[2]);
	ft_list_push_front(&list, (void *) &values[1]);

	ft_list_sort(&list, &asc);

	ASSERT_EQ(list->data, (void *) &values[0]);
	ASSERT_EQ(list->next->data, (void *) &values[1]);
	ASSERT_EQ(list->next->next->data, (void *) &values[2]);
	ASSERT_EQ(list->next->next->next->data, (void *) &values[3]);
	ASSERT_EQ(list->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, insert_in_middle_string)
{
	const char	*values[] = { "a", "b", "c", "d" };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) values[3]);
	ft_list_push_front(&list, (void *) values[0]);
	ft_list_push_front(&list, (void *) values[2]);
	ft_list_push_front(&list, (void *) values[1]);

	ft_list_sort(&list, &strcmp);

	ASSERT_EQ(list->data, (void *) values[0]);
	ASSERT_EQ(list->next->data, (void *) values[1]);
	ASSERT_EQ(list->next->next->data, (void *) values[2]);
	ASSERT_EQ(list->next->next->next->data, (void *) values[3]);
	ASSERT_EQ(list->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, insert_at_end)
{
	const int	values[] = { 1, 2, 3, 4 };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) &values[1]);
	ft_list_push_front(&list, (void *) &values[0]);
	ft_list_push_front(&list, (void *) &values[3]);
	ft_list_push_front(&list, (void *) &values[2]);

	ft_list_sort(&list, &asc);

	ASSERT_EQ(list->data, (void *) &values[0]);
	ASSERT_EQ(list->next->data, (void *) &values[1]);
	ASSERT_EQ(list->next->next->data, (void *) &values[2]);
	ASSERT_EQ(list->next->next->next->data, (void *) &values[3]);
	ASSERT_EQ(list->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, insert_at_end_string)
{
	const char	*values[] = { "a", "b", "c", "d" };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) values[1]);
	ft_list_push_front(&list, (void *) values[0]);
	ft_list_push_front(&list, (void *) values[3]);
	ft_list_push_front(&list, (void *) values[2]);

	ft_list_sort(&list, &strcmp);

	ASSERT_EQ(list->data, (void *) values[0]);
	ASSERT_EQ(list->next->data, (void *) values[1]);
	ASSERT_EQ(list->next->next->data, (void *) values[2]);
	ASSERT_EQ(list->next->next->next->data, (void *) values[3]);
	ASSERT_EQ(list->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, duplicates)
{
	const int	values[] = { 1, 2, 2, 3, 3 };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) &values[3]);
	ft_list_push_front(&list, (void *) &values[4]);
	ft_list_push_front(&list, (void *) &values[1]);
	ft_list_push_front(&list, (void *) &values[2]);
	ft_list_push_front(&list, (void *) &values[0]);

	ft_list_sort(&list, &asc);

	ASSERT_EQ(*(int *) list->data, 1);
	ASSERT_EQ(*(int *) list->next->data, 2);
	ASSERT_EQ(*(int *) list->next->next->data, 2);
	ASSERT_EQ(*(int *) list->next->next->next->data, 3);
	ASSERT_EQ(*(int *) list->next->next->next->next->data, 3);
	ASSERT_EQ(list->next->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, duplicates_string)
{
	const char	*values[] = { "a", "b", "b", "c", "c" };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) values[3]);
	ft_list_push_front(&list, (void *) values[4]);
	ft_list_push_front(&list, (void *) values[1]);
	ft_list_push_front(&list, (void *) values[2]);
	ft_list_push_front(&list, (void *) values[0]);

	ft_list_sort(&list, &strcmp);

	ASSERT_EQ((char *) list->data, "a");
	ASSERT_EQ((char *) list->next->data, "b");
	ASSERT_EQ((char *) list->next->next->data, "b");
	ASSERT_EQ((char *) list->next->next->next->data, "c");
	ASSERT_EQ((char *) list->next->next->next->next->data, "c");
	ASSERT_EQ(list->next->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_sort, descending)
{
	const int	values[] = { 1, 2, 3, 4, 5 };
	t_list		*list = NULL;

	ft_list_push_front(&list, (void *) &values[0]);
	ft_list_push_front(&list, (void *) &values[1]);
	ft_list_push_front(&list, (void *) &values[2]);
	ft_list_push_front(&list, (void *) &values[3]);
	ft_list_push_front(&list, (void *) &values[4]);

	ft_list_sort(&list, &desc);

	ASSERT_EQ(*(int *) list->data, 5);
	ASSERT_EQ(*(int *) list->next->data, 4);
	ASSERT_EQ(*(int *) list->next->next->data, 3);
	ASSERT_EQ(*(int *) list->next->next->next->data, 2);
	ASSERT_EQ(*(int *) list->next->next->next->next->data, 1);
	ASSERT_EQ(list->next->next->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}
