/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:28:00 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/18 11:02:56 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "utest.h"
#include <asm-generic/errno-base.h>
#include <string.h>
#include <stdlib.h>

UTEST(ft_strcpy, empty_string)
{
	const char		*src = "";
	const size_t	size = ft_strlen(src) + 1;
	char			dst1[size];
	char			dst2[size];

	ASSERT_EQ(ft_strcpy(dst1, src), dst1);
	ASSERT_EQ(strcpy(dst2, src), dst2);
	ASSERT_STREQ(dst1, dst2);
}

UTEST(ft_strcpy, simple_string)
{
	const char		*src = "a";
	const size_t	size = ft_strlen(src) + 1;
	char			dst1[size];
	char			dst2[size];

	ASSERT_EQ(ft_strcpy(dst1, src), dst1);
	ASSERT_EQ(strcpy(dst2, src), dst2);
	ASSERT_STREQ(dst1, dst2);
}

UTEST(ft_strcpy, odd_string)
{
	const char		*src = "hello, world!";
	const size_t	size = ft_strlen(src) + 1;
	char			dst1[size];
	char			dst2[size];

	ASSERT_EQ(ft_strcpy(dst1, src), dst1);
	ASSERT_EQ(strcpy(dst2, src), dst2);
	ASSERT_STREQ(dst1, dst2);
}

UTEST(ft_strcpy, even_string)
{
	const char		*src = "hello, world";
	const size_t	size = ft_strlen(src) + 1;
	char			dst1[size];
	char			dst2[size];

	ASSERT_EQ(ft_strcpy(dst1, src), dst1);
	ASSERT_EQ(strcpy(dst2, src), dst2);
	ASSERT_STREQ(dst1, dst2);
}

UTEST(ft_strcpy, long_string)
{
	const char		*src = \
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n";
	const size_t	size = ft_strlen(src) + 1;
	char			dst1[size];
	char			dst2[size];

	ASSERT_EQ(ft_strcpy(dst1, src), dst1);
	ASSERT_EQ(strcpy(dst2, src), dst2);
	ASSERT_STREQ(dst1, dst2);
}

UTEST(ft_strcpy, special_chars)
{
	const char		*src = \
		"\n\r\t\v\f!@#$%¨&*()`{}^~´[].,<>;:\\|\"'?+_-=";
	const size_t	size = ft_strlen(src) + 1;
	char			dst1[size];
	char			dst2[size];

	ASSERT_EQ(ft_strcpy(dst1, src), dst1);
	ASSERT_EQ(strcpy(dst2, src), dst2);
	ASSERT_STREQ(dst1, dst2);
}

