#!/bin/sh

echo "🛠  Compiling libft..."
make re >/dev/null

echo "📦 Compiling tester..."
if ! cc -Wall -Wextra -Werror -I. tests/libft_tester.c libft.a -o run_tests; then
	echo "❌ Compilation failed!"
	exit 1
fi

echo "🚀 Running tests..."
if ./run_tests > /dev/null; then
	echo "✅ All tests passed successfully!"
	make fclean >/dev/null
	rm -f run_tests
	echo "🗑  Cleaning up..."
else
	echo "❌ Some tests failed!"
	exit 1
fi
