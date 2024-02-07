source_files = *.c States/*.c
header_files = *.h States/*.h
files = $(source_files) $(header_files)

all: 
	gcc -o main -Wall -Wextra -Wconversion -Wpedantic $(source_files)

cppcheck:
	cppcheck --enable=all --inline-suppr --suppress=missingIncludeSystem  $(files)

clang-format:
	clang-format -i $(files)