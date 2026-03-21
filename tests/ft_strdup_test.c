/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 07:20:59 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/18 09:23:39 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */


#include "libasm.h"
#include "utest.h"

UTEST(ft_strdup, empty_string)
{
	const char	*src;
	char		*dst;

	src = "";
	dst = ft_strdup(src);
	ASSERT_STREQ(src, dst);
	free(dst);
}

UTEST(ft_strdup, simple_string)
{
	const char	*src;
	char		*dst;

	src = "a";
	dst = ft_strdup(src);
	ASSERT_STREQ(src, dst);
	free(dst);
}

UTEST(ft_strdup, odd_string)
{
	const char	*src;
	char		*dst;

	src = "hello, world!";
	dst = ft_strdup(src);
	ASSERT_STREQ(src, dst);
	free(dst);
}

UTEST(ft_strdup, even_string)
{
	const char	*src;
	char		*dst;

	src = "hello, world";
	dst = ft_strdup(src);
	ASSERT_STREQ(src, dst);
	free(dst);
}

UTEST(ft_strdup, long_string)
{
	const char	*src;
	char		*dst;

	src = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n";
	dst = ft_strdup(src);
	ASSERT_STREQ(src, dst);
	free(dst);
}

UTEST(ft_strdup, special_chars)
{
	const char	*src;
	char		*dst;

	src = "\n\r\t\v\f!@#$%¨&*()`{}^~´[].,<>;:\\|\"'?+_-=";
	dst = ft_strdup(src);
	ASSERT_STREQ(src, dst);
	free(dst);
}
