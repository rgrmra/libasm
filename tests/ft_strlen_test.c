/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:49:35 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/18 09:23:30 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "utest.h"
#include <string.h>

UTEST(ft_strlen, empty_string)
{
	const char	*str;

	str = "";
	ASSERT_EQ(ft_strlen(str), strlen(str));
}

UTEST(ft_strlen, odd_string)
{
	const char	*str;

	str = "hello, world!";
	ASSERT_EQ(ft_strlen(str), strlen(str));
}

UTEST(ft_strlen, even_string)
{
	const char	*str;

	str = "hello, world";
	ASSERT_EQ(ft_strlen(str), strlen(str));
}

UTEST(ft_strlen, simple_string)
{
	const char	*str;

	str = "a";
	ASSERT_EQ(ft_strlen(str), strlen(str));
}

UTEST(ft_strlen, long_string)
{
	const char	*str;

	str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n";
	ASSERT_EQ(ft_strlen(str), strlen(str));
}

UTEST(ft_strlen, especial_chars)
{
	const char	*str;

	str = "\n\r\t\v\f!@#$%¨&*()`{}^~´[].,<>;:\\|\"'?+_-=";
	ASSERT_EQ(ft_strlen(str), strlen(str));
}
