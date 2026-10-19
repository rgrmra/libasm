/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:49:35 by rde-mour          #+#    #+#             */
/*   Updated: 2026/10/19 18:21:50 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include "utest.h"

UTEST(ft_atoi_base, null_string_and_base)
{
	ASSERT_EQ(ft_atoi_base(NULL, NULL), 0);
}

UTEST(ft_atoi_base, null_string)
{
	char	*str;
	char	*base;

	str = NULL;
	base = "0123456789ABCDEF";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, null_base)
{
	char	*str;
	char	*base;

	str = "10";
	base = NULL;
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, empty_base)
{
	char	*str;
	char	*base;

	str = "10";
	base = "";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, one_char_base)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, two_char_base)
{
	char	*str;
	char	*base;

	str = "10";
	base = "01";
	ASSERT_EQ(ft_atoi_base(str, base), 2);
}

UTEST(ft_atoi_base, duplicated_base)
{
	char	*str;
	char	*base;

	str = "10";
	base = "01223456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_space)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789 ";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_plus_sign)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789+";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_minus_sign)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789-";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_tab)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789\t";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_vertical_tab)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789\v";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_carriage_return)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789\r";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_new_line)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789\n";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_form_feed)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789\f";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, number_skip_space)
{
	char	*str;
	char	*base;

	str = "    11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 11);
}

UTEST(ft_atoi_base, number_skip_tab)
{
	char	*str;
	char	*base;

	str = "\t\t\t\t11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 11);
}

UTEST(ft_atoi_base, number_skip_vertical_tab)
{
	char	*str;
	char	*base;

	str = "\v\v\v\v11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 11);
}

UTEST(ft_atoi_base, number_skip_carriage_return)
{
	char	*str;
	char	*base;

	str = "\r\r\r\r11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 11);
}

UTEST(ft_atoi_base, number_skip_form_feed)
{
	char	*str;
	char	*base;

	str = "\f\f\f\f11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 11);
}

UTEST(ft_atoi_base, number_skip_new_line)
{
	char	*str;
	char	*base;

	str = "\n\n\n\n11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 11);
}

UTEST(ft_atoi_base, number_skip_all_spaces)
{
	char	*str;
	char	*base;

	str = "\t\v\r\f\n 11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 11);
}

UTEST(ft_atoi_base, number_skip_space_minus_sign)
{
	char	*str;
	char	*base;

	str = "    -11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -11);
}

UTEST(ft_atoi_base, number_skip_tab_minus_sign)
{
	char	*str;
	char	*base;

	str = "\t\t\t\t-11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -11);
}

UTEST(ft_atoi_base, number_skip_vertical_tab_minus_sign)
{
	char	*str;
	char	*base;

	str = "\v\v\v\v-11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -11);
}

UTEST(ft_atoi_base, number_skip_carriage_return_minus_sign)
{
	char	*str;
	char	*base;

	str = "\r\r\r\r-11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -11);
}

UTEST(ft_atoi_base, number_skip_form_feed_minus_sign)
{
	char	*str;
	char	*base;

	str = "\f\f\f\f-11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -11);
}

UTEST(ft_atoi_base, number_skip_new_line_minus_sign)
{
	char	*str;
	char	*base;

	str = "\n\n\n\n-11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -11);
}

UTEST(ft_atoi_base, number_skip_all_spaces_minus_sign)
{
	char	*str;
	char	*base;

	str = "\t\v\r\f\n -11";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -11);
}

UTEST(ft_atoi_base, number_max_int)
{
	char	*str;
	char	*base;

	str = "2147483647";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 2147483647);
}

UTEST(ft_atoi_base, number_min_int)
{
	char	*str;
	char	*base;

	str = "-2147483648";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -2147483648);
}

UTEST(ft_atoi_base, number_overflow)
{
	char	*str;
	char	*base;

	str = "2147483648";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -2147483648);
}

UTEST(ft_atoi_base, number)
{
	char	*str;
	char	*base;

	str = "42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 42);
}

UTEST(ft_atoi_base, octal)
{
	char	*str;
	char	*base;

	str = "10";
	base = "01234567";
	ASSERT_EQ(ft_atoi_base(str, base), 8);
}

UTEST(ft_atoi_base, double_octal)
{
	char	*str;
	char	*base;

	str = "20";
	base = "01234567";
	ASSERT_EQ(ft_atoi_base(str, base), 16);
}

UTEST(ft_atoi_base, binary)
{
	char	*str;
	char	*base;

	str = "100";
	base = "01";
	ASSERT_EQ(ft_atoi_base(str, base), 4);
}

UTEST(ft_atoi_base, double_binary)
{
	char	*str;
	char	*base;

	str = "1000";
	base = "01";
	ASSERT_EQ(ft_atoi_base(str, base), 8);
}

UTEST(ft_atoi_base, empty_string)
{
	char	*str;
	char	*base;

	str = "";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, only_spaces)
{
	char	*str;
	char	*base;

	str = "   \t\n\v\r\f";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, only_plus_sign)
{
	char	*str;
	char	*base;

	str = "+";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, only_minus_sign)
{
	char	*str;
	char	*base;

	str = "-";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, positive_sign)
{
	char	*str;
	char	*base;

	str = "+42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 42);
}

UTEST(ft_atoi_base, multiple_plus_signs)
{
	char	*str;
	char	*base;

	str = "++42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, multiple_minus_signs)
{
	char	*str;
	char	*base;

	str = "--42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, mixed_signs)
{
	char	*str;
	char	*base;

	str = "+-42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, minus_plus_signs)
{
	char	*str;
	char	*base;

	str = "-+42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, zero)
{
	char	*str;
	char	*base;

	str = "0";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, multiple_zeros)
{
	char	*str;
	char	*base;

	str = "000000";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, negative_zero)
{
	char	*str;
	char	*base;

	str = "-0";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, positive_zero)
{
	char	*str;
	char	*base;

	str = "+0";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, leading_zeros)
{
	char	*str;
	char	*base;

	str = "00042";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 42);
}

UTEST(ft_atoi_base, negative_leading_zeros)
{
	char	*str;
	char	*base;

	str = "-00042";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -42);
}

UTEST(ft_atoi_base, invalid_first_character)
{
	char	*str;
	char	*base;

	str = "a42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, invalid_character_after_number)
{
	char	*str;
	char	*base;

	str = "42abc";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 42);
}

UTEST(ft_atoi_base, invalid_character_in_number)
{
	char	*str;
	char	*base;

	str = "12a34";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 12);
}

UTEST(ft_atoi_base, spaces_after_number)
{
	char	*str;
	char	*base;

	str = "42   ";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 42);
}

UTEST(ft_atoi_base, spaces_before_sign)
{
	char	*str;
	char	*base;

	str = "   -42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -42);
}

UTEST(ft_atoi_base, spaces_between_sign_and_number)
{
	char	*str;
	char	*base;

	str = "- 42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, sign_after_spaces_and_tabs)
{
	char	*str;
	char	*base;

	str = "\t \n\v -123";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -123);
}

UTEST(ft_atoi_base, binary_zero)
{
	char	*str;
	char	*base;

	str = "0";
	base = "01";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, binary_one)
{
	char	*str;
	char	*base;

	str = "1";
	base = "01";
	ASSERT_EQ(ft_atoi_base(str, base), 1);
}

UTEST(ft_atoi_base, binary_negative)
{
	char	*str;
	char	*base;

	str = "-101";
	base = "01";
	ASSERT_EQ(ft_atoi_base(str, base), -5);
}

UTEST(ft_atoi_base, binary_invalid_character)
{
	char	*str;
	char	*base;

	str = "102";
	base = "01";
	ASSERT_EQ(ft_atoi_base(str, base), 2);
}

UTEST(ft_atoi_base, octal_negative)
{
	char	*str;
	char	*base;

	str = "-10";
	base = "01234567";
	ASSERT_EQ(ft_atoi_base(str, base), -8);
}

UTEST(ft_atoi_base, hexadecimal_lowercase)
{
	char	*str;
	char	*base;

	str = "ff";
	base = "0123456789abcdef";
	ASSERT_EQ(ft_atoi_base(str, base), 255);
}

UTEST(ft_atoi_base, hexadecimal_uppercase)
{
	char	*str;
	char	*base;

	str = "FF";
	base = "0123456789ABCDEF";
	ASSERT_EQ(ft_atoi_base(str, base), 255);
}

UTEST(ft_atoi_base, hexadecimal_mixed_case_base)
{
	char	*str;
	char	*base;

	str = "aF";
	base = "0123456789aBcDeF";
	ASSERT_EQ(ft_atoi_base(str, base), 175);
}

UTEST(ft_atoi_base, hexadecimal_negative)
{
	char	*str;
	char	*base;

	str = "-FF";
	base = "0123456789ABCDEF";
	ASSERT_EQ(ft_atoi_base(str, base), -255);
}

UTEST(ft_atoi_base, hexadecimal_zero)
{
	char	*str;
	char	*base;

	str = "0";
	base = "0123456789ABCDEF";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, hexadecimal_invalid_character)
{
	char	*str;
	char	*base;

	str = "1G";
	base = "0123456789ABCDEF";
	ASSERT_EQ(ft_atoi_base(str, base), 1);
}

UTEST(ft_atoi_base, base_with_duplicate_first_character)
{
	char	*str;
	char	*base;

	str = "10";
	base = "00123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_duplicate_last_character)
{
	char	*str;
	char	*base;

	str = "10";
	base = "01234567890";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_duplicate_letters)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789aabc";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_carriage_return_and_newline)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789\r\n";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_duplicate_sign)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789++";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_duplicate_space)
{
	char	*str;
	char	*base;

	str = "10";
	base = "0123456789  ";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_three_characters)
{
	char	*str;
	char	*base;

	str = "210";
	base = "012";
	ASSERT_EQ(ft_atoi_base(str, base), 21);
}

UTEST(ft_atoi_base, base_with_special_characters)
{
	char	*str;
	char	*base;

	str = "#@!";
	base = "!@#";
	ASSERT_EQ(ft_atoi_base(str, base), 21);
}

UTEST(ft_atoi_base, base_with_letters)
{
	char	*str;
	char	*base;

	str = "cab";
	base = "abc";
	ASSERT_EQ(ft_atoi_base(str, base), 19);
}

UTEST(ft_atoi_base, negative_base_with_letters)
{
	char	*str;
	char	*base;

	str = "-cab";
	base = "abc";
	ASSERT_EQ(ft_atoi_base(str, base), -19);
}

UTEST(ft_atoi_base, large_number)
{
	char	*str;
	char	*base;

	str = "123456789";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 123456789);
}

UTEST(ft_atoi_base, negative_large_number)
{
	char	*str;
	char	*base;

	str = "-123456789";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -123456789);
}

UTEST(ft_atoi_base, max_int_with_positive_sign)
{
	char	*str;
	char	*base;

	str = "+2147483647";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 2147483647);
}

UTEST(ft_atoi_base, min_int_with_leading_zeros)
{
	char	*str;
	char	*base;

	str = "-0002147483648";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), -2147483648);
}

UTEST(ft_atoi_base, negative_overflow)
{
	char	*str;
	char	*base;

	str = "-2147483649";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 2147483647);
}

UTEST(ft_atoi_base, number_with_leading_whitespace_and_plus)
{
	char	*str;
	char	*base;

	str = " \t\n+42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 42);
}

UTEST(ft_atoi_base, whitespace_after_sign)
{
	char	*str;
	char	*base;

	str = "+\t42";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, number_with_trailing_letters)
{
	char	*str;
	char	*base;

	str = "123abc";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 123);
}

UTEST(ft_atoi_base, number_with_prefix_invalid)
{
	char	*str;
	char	*base;

	str = "0xFF";
	base = "0123456789ABCDEF";
	ASSERT_EQ(ft_atoi_base(str, base), 0);
}

UTEST(ft_atoi_base, base_with_only_letters)
{
	char	*str;
	char	*base;

	str = "bca";
	base = "abc";
	ASSERT_EQ(ft_atoi_base(str, base), 15);
}

UTEST(ft_atoi_base, base_with_punctuation)
{
	char	*str;
	char	*base;

	str = "!?";
	base = "?!";
	ASSERT_EQ(ft_atoi_base(str, base), 2);
}

UTEST(ft_atoi_base, base_with_all_valid_digits)
{
	char	*str;
	char	*base;

	str = "9876543210";
	base = "0123456789";
	ASSERT_EQ(ft_atoi_base(str, base), 1286608618);
}
