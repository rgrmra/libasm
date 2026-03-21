#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

////int	main(void)
////{
////	char	*str = "hello, world!\n";
////	void	*dst;
////
////	dst = (void *) calloc(sizeof(char), 20);
////	if (!dst)
////		return (EXIT_FAILURE);
////
////	ft_memset(dst, 'c', 20);
////	printf("%s\n", str);
////	printf("%s\n", (char *) dst);
////
////
////	return (EXIT_SUCCESS);
////}
//
int	main(void)
{
	char	*str = "hello, world";
	
	ft_putendl_fd(str, 1);
	printf("%d\n", errno);

	return (EXIT_SUCCESS);
}
