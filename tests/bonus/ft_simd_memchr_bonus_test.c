/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simd_memchr_bonus_test.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:30:31 by rde-mour          #+#    #+#             */
/*   Updated: 2026/10/17 17:56:49 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include "utest.h"
#include <string.h>
#include <stdint.h>

UTEST(ft_simd_memchr, null_length)
{
	const char	*str = "hello";

	ASSERT_EQ(ft_simd_memchr(str, 'h', 0), NULL);
}

UTEST(ft_simd_memchr, first_character)
{
	const char	*str = "hello";

	ASSERT_EQ(ft_simd_memchr(str, 'h', 5), str);
}

UTEST(ft_simd_memchr, middle_character)
{
	const char	 *str = "hello";

	ASSERT_EQ(ft_simd_memchr(str, 'l', 5), str + 2);
}

UTEST(ft_simd_memchr, last_character)
{
	const char	 *str = "hello";
	ASSERT_EQ(ft_simd_memchr(str, 'o', 5), str + 4);
}

UTEST(ft_simd_memchr, character_not_found)
{
	const char	 *str = "hello";
	ASSERT_EQ(ft_simd_memchr(str, 'z', 5), NULL);
}

UTEST(ft_simd_memchr, empty_search)
{
	const char	 *str = "";
	ASSERT_EQ(ft_simd_memchr(str, 'a', 0), NULL);
}

UTEST(ft_simd_memchr, single_byte_found)
{
	const char	 str[] = {'a'};

	ASSERT_EQ(ft_simd_memchr(str, 'a', 1), str);
}

UTEST(ft_simd_memchr, single_byte_not_found)
{
	const char	 str[] = {'a'};

	ASSERT_EQ(ft_simd_memchr(str, 'b', 1), NULL);
}

UTEST(ft_simd_memchr, embedded_null_byte)
{
	const char	 str[] = {'a', 'b', '\0', 'c', 'd'};

	ASSERT_EQ(ft_simd_memchr(str, '\0', 5), str + 2);
}

UTEST(ft_simd_memchr, search_after_null_byte)
{
	const char	 str[] = {'a', '\0', 'b', 'c'};

	ASSERT_EQ(ft_simd_memchr(str, 'c', 4), str + 3);
}

UTEST(ft_simd_memchr, null_byte_not_found)
{
	const char	 str[] = {'a', 'b', 'c'};

	ASSERT_EQ(ft_simd_memchr(str, '\0', 3), NULL);
}

UTEST(ft_simd_memchr, unsigned_byte_255)
{
	unsigned const char	 str[] = { 0x10, 0x80, 0xFF, 0x20 };

	ASSERT_EQ(ft_simd_memchr(str, 255, 4), str + 2);
}

UTEST(ft_simd_memchr, negative_c)
{
	unsigned const char	 str[] = { 0x10, 0xFF, 0x20 };

	ASSERT_EQ(ft_simd_memchr(str, -1, 3), str + 1);
}

UTEST(ft_simd_memchr, c_greater_than_255)
{
	unsigned const char	 str[] = { 0x2C, 0xFF, 0x10 };

	ASSERT_EQ(ft_simd_memchr(str, 511, 3), str + 1);
}

UTEST(ft_simd_memchr, duplicate_character)
{
	const char	 str[] = "abacada";

	ASSERT_EQ(ft_simd_memchr(str, 'a', 7), str);
}

UTEST(ft_simd_memchr, first_occurrence_in_middle)
{
	const char	 str[] = "xyzabcabc";

	ASSERT_EQ(ft_simd_memchr(str, 'a', 9), str + 3);
}

UTEST(ft_simd_memchr, occurrence_outside_n)
{
	const char	 str[] = "abcdef";

	ASSERT_EQ(ft_simd_memchr(str, 'f', 5), NULL);
}

UTEST(ft_simd_memchr, occurrence_at_n_boundary)
{
	const char	 str[] = "abcdef";

	ASSERT_EQ(ft_simd_memchr(str, 'e', 5), str + 4);
}

UTEST(ft_simd_memchr, exactly_16_bytes_found)
{
	const char	 str[] = "abcdefghijklmnoX";

	ASSERT_EQ(ft_simd_memchr(str, 'X', 16), str + 15);
}

UTEST(ft_simd_memchr, exactly_16_bytes_not_found)
{
	const char	 str[] = "abcdefghijklmnop";

	ASSERT_EQ(ft_simd_memchr(str, 'z', 16), NULL);
}

UTEST(ft_simd_memchr, first_byte_of_vector)
{
	const char	 str[] = "Xbcdefghijklmnop";

	ASSERT_EQ(ft_simd_memchr(str, 'X', 16), str);
}

UTEST(ft_simd_memchr, multiple_matches_in_vector)
{
	const char	 str[] = "abcXefghXjklmnoX";

	ASSERT_EQ(ft_simd_memchr(str, 'X', 16), str + 3);
}

UTEST(ft_simd_memchr, second_vector)
{
	const char	 str[] = "abcdefghijklmnopX";

	ASSERT_EQ(ft_simd_memchr(str, 'X', 17), str + 16);
}

UTEST(ft_simd_memchr, second_vector_first_character)
{
	const char	 str[] = "abcdefghijklmnopXbcdefghijklmnop";

	ASSERT_EQ(ft_simd_memchr(str, 'X', 32), str + 16);
}

UTEST(ft_simd_memchr, vector_and_tail)
{
	const char	 str[] = "abcdefghijklmnopqrsX";

	ASSERT_EQ(ft_simd_memchr(str, 'X', 20), str + 19);
}

UTEST(ft_simd_memchr, tail_first_character)
{
	const char	 str[] = "abcdefghijklmnopX";

	ASSERT_EQ(ft_simd_memchr(str, 'X', 17), str + 16);
}

UTEST(ft_simd_memchr, tail_last_character)
{
	const char	 str[] = "abcdefghijklmnopqrsX";

	ASSERT_EQ(ft_simd_memchr(str, 'X', 20), str + 19);
}

UTEST(ft_simd_memchr, tail_not_found)
{
	const char	 str[] = "abcdefghijklmnopqrs";

	ASSERT_EQ(ft_simd_memchr(str, 'z', 19), NULL);
}

UTEST(ft_simd_memchr, n_smaller_than_vector)
{
	const char	 str[] = "abcdefgh";

	ASSERT_EQ(ft_simd_memchr(str, 'h', 8), str + 7);
}

UTEST(ft_simd_memchr, unaligned_address)
{
	const char	 str[] = "_abcdefghijklmnopX";

	ASSERT_EQ(ft_simd_memchr(str + 1, 'X', 17), str + 17);
}

UTEST(ft_simd_memchr, binary_data)
{
	unsigned const char	 str[] = { 0x01, 0x02, 0x03, 0xFE, 0x05 };

	ASSERT_EQ(ft_simd_memchr(str, 0xFE, 5), str + 3);
}

UTEST(ft_simd_memchr, byte_zero)
{
	unsigned const char	 str[] = { 0x01, 0x02, 0x00, 0x04 };

	ASSERT_EQ(ft_simd_memchr(str, 0, 4), str + 2);
}

UTEST(ft_simd_memchr, compare_with_libc)
{
	const unsigned char	 str[] = { 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,
		0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0, 0xFF, 0x10, 0x20, 0x30,
		0x40, 0x50 };
	size_t i;
	int c;

	i = 0;
	while (i <= sizeof(str))
	{
		c = 0;
		while (c <= 255)
		{
			ASSERT_EQ(ft_simd_memchr(str, c, i), memchr(str, c, i));
			c++;
		}
		i++;
	}
}
