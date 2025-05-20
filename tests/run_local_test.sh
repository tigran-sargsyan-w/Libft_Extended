#!/bin/sh

echo "🛠  Compiling libft..."
make >/dev/null

echo "📦 Compiling tester..."
if ! cc -Wall -Wextra -Werror -I. tests/libft_tester.c libft.a -o run_tests; then
	echo "❌ Compilation failed!"
	exit 1
fi

echo "🚀 Running tests..."
if ./run_tests > /dev/null; then
	echo "✅ All tests passed successfully!"
else
	echo "❌ Some tests failed!"
	exit 1
fi
