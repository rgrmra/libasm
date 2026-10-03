/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:49:35 by rde-mour          #+#    #+#             */
/*   Updated: 2026/10/02 10:16:34 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include "utest.h"

UTEST(ft_atoi_base, empty_string)
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
