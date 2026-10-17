/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_bonus_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:49:35 by rde-mour          #+#    #+#             */
/*   Updated: 2026/10/17 16:06:47 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "utest.h"
#include <string.h>

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

UTEST(ft_list_remove_if, empty_list)
{
    t_list *list = NULL;
    const char *value = "remove";

    ft_list_remove_if(&list, (void *) value, &strcmp, NULL);

    ASSERT_EQ(list, NULL);
    ASSERT_EQ(ft_list_size(list), 0);
}

UTEST(ft_list_remove_if, one_element_match)
{
    t_list *list = NULL;
    const char *value = "remove";

    ft_list_push_front(&list, (void *) value);

    ft_list_remove_if(&list, (void *) value, &strcmp, NULL);

    ASSERT_EQ(list, NULL);
    ASSERT_EQ(ft_list_size(list), 0);
}

UTEST(ft_list_remove_if, one_element_no_match)
{
    t_list *list = NULL;
    const char *value = "keep";
    const char *target = "remove";

    ft_list_push_front(&list, (void *) value);

    ft_list_remove_if(&list, (void *) target, &strcmp, NULL);

    ASSERT_EQ(ft_list_size(list), 1);
    ASSERT_EQ(list->data, (void *) value);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_remove_if, remove_head)
{
    t_list *list = NULL;
    const char *a = "remove";
    const char *b = "keep";
    const char *target = "remove";

    ft_list_push_front(&list, (void *) b);
    ft_list_push_front(&list, (void *) a);

    ft_list_remove_if(&list, (void *) target, &strcmp, NULL);

    ASSERT_EQ(ft_list_size(list), 1);
    ASSERT_EQ(list->data, (void *) b);
    ASSERT_EQ(list->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_remove_if, remove_tail)
{
    t_list *list = NULL;
    const char *a = "remove";
    const char *b = "keep";
    const char *target = "remove";

    ft_list_push_front(&list, (void *) a);
    ft_list_push_front(&list, (void *) b);

    ft_list_remove_if(&list, (void *) target, &strcmp, NULL);

    ASSERT_EQ(ft_list_size(list), 1);
    ASSERT_EQ(list->data, (void *) b);
    ASSERT_EQ(list->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_remove_if, remove_middle)
{
    t_list *list = NULL;
    const char *a = "remove";
    const char *b = "keep";
    const char *c = "remove";
    const char *target = "remove";

    ft_list_push_front(&list, (void *) a);
    ft_list_push_front(&list, (void *) b);
    ft_list_push_front(&list, (void *) c);

    ft_list_remove_if(&list, (void *) target, &strcmp, NULL);

    ASSERT_EQ(ft_list_size(list), 1);
    ASSERT_EQ(list->data, (void *) b);
    ASSERT_EQ(list->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_remove_if, remove_all_elements)
{
    t_list *list = NULL;
    const char *value = "remove";
    const char *target = "remove";

    for (int i = 0; i < 10; i++)
        ft_list_push_front(&list, (void *) value);

    ASSERT_EQ(ft_list_size(list), 10);

    ft_list_remove_if(&list, (void *)target, &strcmp, NULL);

    ASSERT_EQ(list, NULL);
    ASSERT_EQ(ft_list_size(list), 0);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_remove_if, no_matching_elements)
{
    t_list *list = NULL;
    const char *a = "alpha";
    const char *b = "beta";
    const char *c = "gamma";
    const char *target = "remove";

    ft_list_push_front(&list, (void *) c);
    ft_list_push_front(&list, (void *) b);
    ft_list_push_front(&list, (void *) a);

    ft_list_remove_if(&list, (void *) target, &strcmp, NULL);

    ASSERT_EQ(ft_list_size(list), 3);
    ASSERT_EQ(list->data, (void *) a);
    ASSERT_EQ(list->next->data, (void *) b);
    ASSERT_EQ(list->next->next->data, (void *) c);
    ASSERT_EQ(list->next->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_remove_if, consecutive_matches)
{
    t_list *list = NULL;
    const char *remove = "remove";
    const char *keep = "keep";
    const char *target = "remove";

    ft_list_push_front(&list, (void *) keep);
    ft_list_push_front(&list, (void *) remove);
    ft_list_push_front(&list, (void *) remove);
    ft_list_push_front(&list, (void *) remove);
    ft_list_push_front(&list, (void *) keep);

    ft_list_remove_if(&list, (void *) target, &strcmp, NULL);

    ASSERT_EQ(ft_list_size(list), 2);
    ASSERT_EQ(list->data, (void *) keep);
    ASSERT_EQ(list->next->data, (void *) keep);
    ASSERT_EQ(list->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_remove_if, alternating_matches)
{
    t_list *list = NULL;
    const char *remove = "remove";
    const char *keep = "keep";
    const char *target = "remove";

    ft_list_push_front(&list, (void *) remove);
    ft_list_push_front(&list, (void *) keep);
    ft_list_push_front(&list, (void *) remove);
    ft_list_push_front(&list, (void *) keep);
    ft_list_push_front(&list, (void *) remove);

    ft_list_remove_if(&list, (void *) target, &strcmp, NULL);

    ASSERT_EQ(ft_list_size(list), 2);
    ASSERT_EQ(list->data, (void *) keep);
    ASSERT_EQ(list->next->data, (void *) keep);
    ASSERT_EQ(list->next->next, NULL);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}

UTEST(ft_list_remove_if, many_elements)
{
    t_list *list = NULL;
    const char *value = "remove";
    const char *value2 = "surprise";

    for (int i = 0; i < 100; i++)
        ft_list_push_front(&list, (void *) value);

    ft_list_push_front(&list, (void *) value2);
    ft_list_push_front(&list, (void *) value);

    ASSERT_EQ(ft_list_size(list), 102);

    ft_list_remove_if(&list, (void *) value, &strcmp, NULL);

    ASSERT_EQ(ft_list_size(list), 1);
    ASSERT_EQ(list->data, (void *) value2);
    ASSERT_EQ(list->next, NULL);

    ft_list_remove_if(&list, (void *) value2, &strcmp, NULL);

    ASSERT_EQ(list, NULL);
    ASSERT_EQ(ft_list_size(list), 0);

	free_list(&list);
	ASSERT_EQ(list, NULL);
}
