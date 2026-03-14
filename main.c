#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

//size_t	ft_strlen(const char *str);
//
//int	main(void)
//{
//	printf("%lu\n", ft_strlen(NULL));
//	return (EXIT_SUCCESS);
//}

//char	*ft_strcpy(char *dst, const char *src);
//
//int	main(void)
//{
//	const char	*src;
//	char 		dst[14];
//
//	src = "Hello, World!";
//	ft_strcpy(dst, src);
//	printf("src: %s\n", src);
//	printf("dst: %s\n", dst);
//	return (EXIT_SUCCESS);
//}

//int	ft_strcmp(const char *dst, const char *src);
//
//int	main(void)
//{
//	const char	*s1;
//	const char	*s2;
//
//	s1 = "Helo, World!";
//	s2 = "Hello, World!";
//	printf("%d\n", ft_strcmp(s1, s2));
//	printf("%d\n", strcmp(s1, s2));
//	return (EXIT_SUCCESS);
//}

//ssize_t	ft_write(int fd, const char *buf, size_t count);
//
//int	main(void)
//{
//	const char	*str;
//	int			size;
//	int			ret;
//
//	str = "Hello, World!\n";
//	size = strlen(str);
//	ret = ft_write(STDIN_FILENO, str, size);
//	if (ret == -1)
//		printf("errno: %d\n", errno);
//	printf("size: %d, ret: %d\n", size, ret);
//	return (EXIT_SUCCESS);
//}

//char *ft_strdup(const char *s);
//
//int	main(void)
//{
//	const char	*str;
//	char		*cpy;
//
//	str = "Hello, World!";
//	cpy = ft_strdup(str);
//	printf("str: %s\n", str);
//	printf("cpy: %s\n", cpy);
//	free(cpy);
//	return (EXIT_SUCCESS);
//}

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char	str[20];
	char	base[20];
	int		value;

	strcpy(str, "42");
	strcpy(base, "0123456789");
	value = ft_atoi_base(str, base);
	printf("value: %d\n", value);
	printf("str: %s\n", str);
	printf("base: %s\n", base);
	return (EXIT_SUCCESS);
}
