/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:28:16 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/18 11:22:02 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libasm.h"
#include "utest.h"

static int normalized(const char *s1, const char *s2,
		int (*f)(const char *s1, const char *s2))
{
	const int	value = f(s1, s2);

	if (value < 0)
		return (-1);
	if (value > 0)
		return (1);
	return (0);
}

UTEST(ft_strcmp, empty_string)
{
	const char *s1 = "";
	const char *s2 = "";

	ASSERT_EQ(normalized(s1, s2, ft_strcmp), normalized(s1, s2, strcmp));
	ASSERT_EQ(normalized(s2, s1, ft_strcmp), normalized(s2, s1, strcmp));
}

UTEST(ft_strcmp, empty_with_no_empty_string)
{
	const char *s1 = "";
	const char *s2 = "hello, world";

	ASSERT_EQ(normalized(s1, s2, ft_strcmp), normalized(s1, s2, strcmp));
	ASSERT_EQ(normalized(s2, s1, ft_strcmp), normalized(s2, s1, strcmp));
}

UTEST(ft_strcmp, no_empty_with_empty_string)
{
	const char *s1 = "hello, world";
	const char *s2 = "";

	ASSERT_EQ(normalized(s1, s2, ft_strcmp), normalized(s1, s2, strcmp));
	ASSERT_EQ(normalized(s2, s1, ft_strcmp), normalized(s2, s1, strcmp));
}

UTEST(ft_strcmp, upper_string)
{
	const char *s1 = "SOMETHING";
	const char *s2 = "something";

	ASSERT_EQ(normalized(s1, s2, ft_strcmp), normalized(s1, s2, strcmp));
	ASSERT_EQ(normalized(s2, s1, ft_strcmp), normalized(s2, s1, strcmp));
}

UTEST(ft_strcmp, even_string)
{
	const char *s1 = "HELLO, WORLD";
	const char *s2 = "hello, world";

	ASSERT_EQ(normalized(s1, s2, ft_strcmp), normalized(s1, s2, strcmp));
	ASSERT_EQ(normalized(s2, s1, ft_strcmp), normalized(s2, s1, strcmp));
}

UTEST(ft_strcmp, simple_equal_string)
{
	const char *s1 = "a";
	const char *s2 = "a";

	ASSERT_EQ(normalized(s1, s2, ft_strcmp), normalized(s1, s2, strcmp));
	ASSERT_EQ(normalized(s2, s1, ft_strcmp), normalized(s2, s1, strcmp));
}

UTEST(ft_strcmp, simple_different_string)
{
	const char *s1 = "a";
	const char *s2 = "b";

	ASSERT_EQ(normalized(s1, s2, ft_strcmp), normalized(s1, s2, strcmp));
	ASSERT_EQ(normalized(s2, s1, ft_strcmp), normalized(s2, s1, strcmp));
}

UTEST(ft_strcmp, long_equal_string)
{
	const char *s1 = \
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n";
	const char *s2 = \
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n";


	ASSERT_EQ(normalized(s1, s2, ft_strcmp), normalized(s1, s2, strcmp));
	ASSERT_EQ(normalized(s2, s1, ft_strcmp), normalized(s2, s1, strcmp));
}

UTEST(ft_strcmp, long_different_string)
{
	const char *s1 = \
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n";
	const char *s2 = \
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\n";

	ASSERT_EQ(normalized(s1, s2, ft_strcmp), normalized(s1, s2, strcmp));
	ASSERT_EQ(normalized(s2, s1, ft_strcmp), normalized(s2, s1, strcmp));
}
