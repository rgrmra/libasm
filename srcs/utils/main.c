#include <stdlib.h>
#include <stdio.h>

extern char *ft_strdup(const char *s);

int main(void) {
    char *s = "";
    char *d = ft_strdup(s);
    if (!d) return 1;
    printf("'%s'\n", d);
    free(d);
    return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#include "libft.h"
//
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
//int	main(void)
//{
//	char	*str = "hello, world!";
//	char	*dst = ft_strdup(str);
//
//	printf("%s\n", str);
//	if (!dst)
//		return (EXIT_FAILURE);
//	printf("%s\n", str);
//	printf("%s\n", dst);
//	free(dst);
//	return (EXIT_SUCCESS);
//}
