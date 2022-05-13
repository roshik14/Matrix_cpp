.PHONY: all test gcov_report clean
SRCS=s21_matrix_oop.cpp
OBJS=${SRCS:.cpp=.o}
CC = g++ -std=c++17
CFLAGS = -Wall -Werror -Wextra
LINUX_FLAGS= -lm -lsubunit -lpthread -lrt 
OS:=$(shell uname -s)

all: clean s21_matrix_oop.a test

s21_matrix_oop.a: $(SRCS)
	${CC} ${CFLAGS} -c $(SRCS) -lm 
	@ar rcs s21_matrix_oop.a $(OBJS)
	@ranlib s21_matrix_oop.a

test: s21_matrix_oop.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) s21_matrix_test.cpp s21_matrix_oop.a -o test -lgtest -lm
else
	$(CC) $(CFLAGS) s21_matrix_test.cpp s21_matrix_oop.a -o test -lgtest $(LINUX_FLAGS)
endif
	./test

gcov_report:
ifeq ($(OS), Darwin)
	@g++ --coverage s21_matrix_test.cpp s21_matrix_oop.cpp -o test -lgtest -lm
else
	@g++ --coverage s21_matrix_test.cpp s21_matrix_oop.cpp -o test -lgtest $(LINUX_FLAGS) 
endif
	@./test
	@lcov -t "test" -o test.info -c -d .
	@genhtml -o report test.info
	
clean:
	@/bin/rm -rf *.o *.a test *.gcno *gcda report *.info 

checks: cppcheck leaks style

style:
	@python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.h

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem . *.cpp

leaks: test 
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test
else
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test $(LINUX_FLAGS) 
endif
