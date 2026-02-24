#include "../includes/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	print_result(char *name, int ok)
{
	if (ok)
		printf("%s OK\n", name);
	else
		printf("%s FAIL\n", name);
}

/* ---------- strlen ---------- */
static void	test_strlen(void)
{
	print_result("ft_strlen", ft_strlen("hello") == strlen("hello"));
}

/* ---------- strchr ---------- */
static void	test_strchr(void)
{
	char	s = "hello";

	print_result("ft_strchr", ft_strchr(s, 'e') == strchr(s, 'e'));
}

/* ---------- strcmp ---------- */
static void	test_strncmp(void)
{
	print_result("ft_strncmp", ft_strncmp("abc", "abd", 3) == strncmp("abc", "abd", 3));
}

/* ---------- strdup ---------- */
static void	test_strdup(void)
{
	char	dup;

	dup = ft_strdup("libft");
	print_result("ft_strdup", strcmp(dup, "libft") == 0);
	free(dup);
}

/* ---------- substr ---------- */
static void	test_substr(void)
{
	char	sub;

	sub = ft_substr("hello", 1, 3);

	print_result("ft_substr", strcmp(sub, "ell") == 0);

	free(sub);
}

/* ---------- split ---------- */
static void	test_split(void)
{
	char	*arr;

	arr = ft_split("a,b,c", ',');

	print_result("ft_split", strcmp(arr[0], "a") == 0 && strcmp(arr[1], "b") == 0 && strcmp(arr[2], "c") == 0);

	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr);
}

/* ---------- atoi ---------- */
static void	test_atoi(void)
{
	print_result("ft_atoi",
	ft_atoi("  -42") == -42);
}

/* ---------- main ---------- */
int	main(void)
{
	printf("\n===== LIBFT TEST =====\n\n");

	test_strlen();
	test_strchr();
	test_strncmp();
	test_strdup();
	test_substr();
	test_split();
	test_atoi();

	printf("\n======================\n");

	return (0);
}
