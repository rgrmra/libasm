#include "libasm.h"
#include "utest.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

UTEST(ft_calloc, basic_allocation)
{
	int		*ptr;
	size_t	i;

	ptr = ft_calloc(5, sizeof(int));
	ASSERT_NE(ptr, NULL);
	i = 0;
	while (i < 5)
	{
		ASSERT_EQ(ptr[i], 0);
		i++;
	}
	free(ptr);
}

UTEST(ft_calloc, single_element)
{
	int	*ptr;

	ptr = ft_calloc(1, sizeof(int));
	ASSERT_NE(ptr, NULL);
	ASSERT_EQ(ptr[0], 0);
	free(ptr);
}

UTEST(ft_calloc, multiple_elements)
{
	char	*ptr;
	size_t	i;

	ptr = ft_calloc(10, sizeof(char));
	ASSERT_NE(ptr, NULL);
	i = 0;
	while (i < 10)
	{
		ASSERT_EQ(ptr[i], 0);
		i++;
	}
	free(ptr);
}

UTEST(ft_calloc, allocation_bytes)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = ft_calloc(16, 1);
	ASSERT_NE(ptr, NULL);
	i = 0;
	while (i < 16)
	{
		ASSERT_EQ(ptr[i], 0);
		i++;
	}
	free(ptr);
}

UTEST(ft_calloc, zero_nmemb)
{
	void	*ptr;

	ptr = ft_calloc(0, sizeof(int));
	free(ptr);
	ASSERT_TRUE(1);
}

UTEST(ft_calloc, zero_size)
{
	void	*ptr;

	ptr = ft_calloc(10, 0);
	free(ptr);
	ASSERT_TRUE(1);
}

UTEST(ft_calloc, zero_nmemb_and_size)
{
	void	*ptr;

	ptr = ft_calloc(0, 0);
	free(ptr);
	ASSERT_TRUE(1);
}

UTEST(ft_calloc, large_allocation)
{
	int		*ptr;
	size_t	i;
	size_t	count;

	count = 10000;
	ptr = ft_calloc(count, sizeof(int));
	ASSERT_NE(ptr, NULL);
	i = 0;
	while (i < count)
	{
		ASSERT_EQ(ptr[i], 0);
		i++;
	}
	free(ptr);
}

UTEST(ft_calloc, different_element_sizes)
{
	short			*a;
	int				*b;
	long long		*c;

	a = ft_calloc(4, sizeof(short));
	b = ft_calloc(4, sizeof(int));
	c = ft_calloc(4, sizeof(long long));
	ASSERT_NE(a, NULL);
	ASSERT_NE(b, NULL);
	ASSERT_NE(c, NULL);
	ASSERT_EQ(a[0], 0);
	ASSERT_EQ(b[0], 0);
	ASSERT_EQ(c[0], 0);
	free(a);
	free(b);
	free(c);
}

UTEST(ft_calloc, overflow_nmemb)
{
	void	*ptr;

	errno = 0;
	ptr = ft_calloc(SIZE_MAX, 2);
	ASSERT_EQ(ptr, NULL);
	free(ptr);
}

UTEST(ft_calloc, overflow_size)
{
	void	*ptr;

	errno = 0;
	ptr = ft_calloc(2, SIZE_MAX);
	ASSERT_EQ(ptr, NULL);
	free(ptr);
}

UTEST(ft_calloc, overflow_both_arguments)
{
	void	*ptr;

	errno = 0;
	ptr = ft_calloc(SIZE_MAX, SIZE_MAX);
	ASSERT_EQ(ptr, NULL);
	free(ptr);
}
