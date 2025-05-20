#include "libft.h"
#include "ft_printf.h"
#include "ft_dprintf.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>

#define ASSERT(msg, cond) \
	do { \
		if (!(cond)) { \
			printf("❌ %s\n", msg); \
			exit(1); \
		} else { \
			printf("✅ %s\n", msg); \
		} \
	} while (0)

// ───────────── CHAR & INT CHECKS ─────────────
void test_char_checks(void)
{
	ASSERT("ft_isalpha('a')", ft_isalpha('a') != 0);
	ASSERT("ft_isdigit('3')", ft_isdigit('3') != 0);
	ASSERT("ft_isalnum('Z')", ft_isalnum('Z') != 0);
	ASSERT("ft_isascii(127)", ft_isascii(127) != 0);
	ASSERT("ft_isprint(' ')", ft_isprint(' ') != 0);
	ASSERT("ft_isspace('\\n')", ft_isspace('\n') != 0);
	ASSERT("ft_isxdigit('A')", ft_isxdigit('A') != 0);
	ASSERT("ft_isvalid_int(\"42\")", ft_isvalid_int("42") == 1);
	ASSERT("ft_isvalid_int(\"2147483647\")", ft_isvalid_int("2147483647") == 1);
	ASSERT("ft_isvalid_int(\"2147483648\")", ft_isvalid_int("2147483648") == 0);
	ASSERT("ft_isvalid_int(\"-2147483648\")", ft_isvalid_int("-2147483648") == 1);
	ASSERT("ft_isvalid_int(\"-2147483649\")", ft_isvalid_int("-2147483649") == 0);
	ASSERT("ft_isvalid_int(\"999999999999999\")", ft_isvalid_int("999999999999999") == 0);
	ASSERT("ft_isvalid_hex(\"1A3F\")", ft_isvalid_hex("1A3F") == 1);
	ASSERT("ft_isvalid_hex(\"Z23\")", ft_isvalid_hex("Z23") == 0);
}

// ───────────── STRING & MEMORY ─────────────
void test_string_memory(void)
{
	char buf[20];
	char *tmp;

	ASSERT("ft_strlen(\"hello\")", ft_strlen("hello") == 5);
	ASSERT("ft_strlcpy(buf, \"abc\", 5)", ft_strlcpy(buf, "abc", 5) == 3);
	ASSERT("ft_strlcat(buf, \"de\", 20)", ft_strlcat(buf, "de", 20) >= 3);
	ASSERT("ft_strcmp(\"a\", \"a\") == 0", ft_strcmp("a", "a") == 0);
	ASSERT("ft_strncmp(\"abc\", \"abd\", 2) == 0", ft_strncmp("abc", "abd", 2) == 0);
	ASSERT("ft_strchr(\"abc\", 'b')", ft_strchr("abc", 'b') != NULL);
	ASSERT("ft_strrchr(\"abcabc\", 'a')", ft_strrchr("abcabc", 'a') != NULL);
	ASSERT("ft_strnstr(\"hello world\", \"world\", 11)", ft_strnstr("hello world", "world", 11) != NULL);
	ASSERT("ft_strdup(\"hi\")", (tmp = ft_strdup("hi")) && strcmp(tmp, "hi") == 0); free(tmp);
	ASSERT("ft_strjoin(\"ab\", \"cd\")", (tmp = ft_strjoin("ab", "cd")) && strcmp(tmp, "abcd") == 0); free(tmp);
	ASSERT("ft_substr(\"abcdef\", 2, 3)", (tmp = ft_substr("abcdef", 2, 3)) && strcmp(tmp, "cde") == 0); free(tmp);
	ASSERT("ft_strtrim(\"--42--\", \"-\")", (tmp = ft_strtrim("--42--", "-")) && strcmp(tmp, "42") == 0); free(tmp);
	char **split = ft_split("a,b,c", ',');
	ASSERT("ft_split(\"a,b,c\", ',')", split && split[1] && !strcmp(split[1], "b")); free(split[0]); free(split[1]); free(split[2]); free(split);

	char mem[10]; ft_bzero(mem, 10);
	ASSERT("ft_bzero()", mem[0] == 0 && mem[9] == 0);

	ft_memset(mem, 'A', 10);
	ASSERT("ft_memset()", mem[0] == 'A' && mem[9] == 'A');

	char copy[10];
	ft_memcpy(copy, mem, 10);
	ASSERT("ft_memcpy()", copy[0] == 'A' && copy[9] == 'A');

	ft_memmove(copy + 1, copy, 5);
	ASSERT("ft_memmove()", copy[1] == 'A');

	ASSERT("ft_memchr(\"abc\", 'b', 3)", ft_memchr("abc", 'b', 3) != NULL);
	ASSERT("ft_memcmp(\"abc\", \"abc\", 3) == 0", ft_memcmp("abc", "abc", 3) == 0);

	void *p = ft_calloc(4, sizeof(int));
	ASSERT("ft_calloc()", p && ((int *)p)[0] == 0); free(p);
}

// ───────────── CONVERSIONS ─────────────
void test_conversions(void)
{
	ASSERT("ft_atoi(\"42\") == 42", ft_atoi("42") == 42);
	ASSERT("ft_atol(\"2147483647\")", ft_atol("2147483647") == 2147483647L);
	ASSERT("ft_atoi_hex(\"1A\") == 26", ft_atoi_hex("1A") == 26);
	char *tmp = ft_itoa(-42);
	ASSERT("ft_itoa(-42)", tmp && strcmp(tmp, "-42") == 0); free(tmp);
	ASSERT("ft_toupper('a')", ft_toupper('a') == 'A');
	ASSERT("ft_tolower('Z')", ft_tolower('Z') == 'z');
}

// ───────────── OUTPUT ─────────────
void test_output(void)
{
	ft_putchar_fd(1, 'A');
	ft_putstr_fd("BC", 1);
	ft_putendl_fd("DE", 1);
	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);
}

// ───────────── STRMAPI / STRITERI ─────────────
char mapfunc(unsigned int i, char c) { return c + i; }
void iterfunc(unsigned int i, char *c) { *c = *c + i; }

void test_strmapi_iteri(void)
{
	char *s = ft_strmapi("abc", mapfunc);
	ASSERT("ft_strmapi(\"abc\")", s && strcmp(s, "ace") == 0); free(s);

	char str[] = "abc";
	ft_striteri(str, iterfunc);
	ASSERT("ft_striteri(\"abc\")", strcmp(str, "ace") == 0);
}

// ───────────── LISTS ─────────────
void del_func(void *content) { free(content); }
void iter_func(void *c) { ((char *)c)[0] += 1; }
void *dup_wrapper(void *content) { return strdup((char *)content); }

void test_lists(void)
{
	t_list	*head = NULL;
	t_list	*node1 = ft_lstnew(strdup("one"));
	t_list	*node2 = ft_lstnew(strdup("two"));
	t_list	*node3 = ft_lstnew(strdup("three"));

	ft_lstadd_front(&head, node2); // head -> node2
	ft_lstadd_front(&head, node1); // head -> node1 -> node2
	ASSERT("ft_lstadd_front() maintains order", head == node1 && node1->next == node2);
	ft_lstadd_back(&head, node3); // head -> node1 -> node2 -> node3
	ASSERT("ft_lstadd_back() adds to end", ft_lstlast(head) == node3);
	ASSERT("ft_lstsize() == 3", ft_lstsize(head) == 3);
	ft_lstiter(head, iter_func);
	ASSERT("ft_lstiter() changed content", ((char *)head->content)[0] != 'o');
	t_list *copy = ft_lstmap(head, dup_wrapper, del_func);
	ASSERT("ft_lstmap() duplicated list", copy && strcmp(copy->content, head->content) == 0);
	ft_lstclear(&copy, del_func);
	t_list *tmp = node1->next; // node2
	node1->next = node2->next; // skip node2
	ft_lstdelone(tmp, del_func);

	ASSERT("ft_lstdelone() deleted node2", ft_lstsize(head) == 2);
	ft_lstclear(&head, del_func);
	ASSERT("ft_lstclear() sets head to NULL", head == NULL);
}

// ───────────── MISC ─────────────
void test_misc(void)
{
	char *tokens[] = { "a", "b", "c", NULL };
	ASSERT("ft_count_tokens()", ft_count_tokens(tokens) == 3);
}

// ───────────── PRINTF ─────────────
void test_printf(void)
{
	int ret;

	ret = ft_printf("ft_printf test: %s %d\n", "hello", 42);
	ASSERT("ft_printf returns correct char count", ret == (int)strlen("ft_printf test: hello 42\n"));

	ret = ft_dprintf(1, "ft_dprintf test: %s %d\n", "world", 21);
	ASSERT("ft_dprintf returns correct char count", ret == (int)strlen("ft_dprintf test: world 21\n"));
}

// ───────────── GNL ─────────────
void test_get_next_line(void)
{
	int fd;
	char *line;

	fd = open("tests/libft_tester.c", O_RDONLY);
	ASSERT("open(\"tests/libft_tester.c\") != -1", fd != -1);

	line = get_next_line(fd);
	ASSERT("get_next_line returns non-NULL", line != NULL);
	ASSERT("line is not empty", ft_strlen(line) > 0);

	ft_printf("get_next_line output: %s", line);
	free(line);
	close(fd);
}

int main(void)
{
	printf("🔍 Running full libft test suite:\n\n");

	test_char_checks();
	test_string_memory();
	test_conversions();
	test_output();
	test_strmapi_iteri();
	test_lists();
	test_misc();
    test_printf();
    test_get_next_line();

	printf("\n🎉 All tests passed successfully!\n");
	return 0;
}
