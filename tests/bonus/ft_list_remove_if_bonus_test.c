/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_bonus_test.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:49:35 by rde-mour          #+#    #+#             */
/*   Updated: 2026/10/06 08:27:12 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "utest.h"
#include <string.h>

UTEST(ft_list_remove_if, many_elements)
{
	t_list	*list = NULL;
	const char	*value = "remove";
	const char	*value2 = "surprise";

	for (int i = 0; i < 100; i++)
	{
		ft_list_push_front(&list, &value);
	}

	ft_list_push_front(&list, &value2);
	ft_list_push_front(&list, &value);

	ASSERT_EQ(ft_list_size(list), 102);
	ft_list_remove_if(&list, &value, &strcmp, NULL);
	ASSERT_EQ(ft_list_size(list), 1);

	ft_list_remove_if(&list, &value2, &strcmp, NULL);
	ASSERT_EQ(list, NULL);
}
