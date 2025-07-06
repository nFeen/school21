CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
V_COMMAND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt
L_COMMAND = leaks -atExit --

PATH_TO_TESTS = test/
PATH_TO_FUNCTIONS = ./
PATH_TO_ROOT = ./
COV_REPORT = report/
EXEC = s21_decimal.a
EXEC_T = unit_tests

SRC = $(wildcard $(PATH_TO_FUNCTIONS)*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
SRC_T = $(wildcard $(PATH_TO_TESTS)*.c)
OBJ_T = $(patsubst %.c, %.o, $(SRC_T))

OS := $(shell uname -s)

all: s21_decimal.a

s21_decimal.a: $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

test: $(OBJ_T) s21_decimal.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(OBJ_T) $(EXEC) -o $(PATH_TO_TESTS)$(EXEC_T) -lcheck
	$(PATH_TO_TESTS)$(EXEC_T)
else
	$(CC) $(CFLAGS) $(OBJ_T) $(EXEC) -o $(PATH_TO_TESTS)$(EXEC_T) -lcheck -lsubunit -lrt -lpthread -lm
	$(PATH_TO_TESTS)$(EXEC_T)
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

format-check:
	@cp ../materials/linters/.clang-format ./
	@clang-format -n $(PATH_TO_FUNCTIONS)*.h $(PATH_TO_FUNCTIONS)*.c $(PATH_TO_TESTS)*.c $(PATH_TO_TESTS)*.h
	@rm .clang-format

format:
	@cp ../materials/linters/.clang-format ./
	@clang-format -i $(PATH_TO_FUNCTIONS)*.h $(PATH_TO_FUNCTIONS)*.c $(PATH_TO_TESTS)*.c $(PATH_TO_TESTS)*.h
	@rm .clang-format

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem $(PATH_TO_FUNCTIONS)*.c $(PATH_TO_FUNCTIONS)*.h $(PATH_TO_TESTS)*.c $(PATH_TO_TESTS)*.h

valgrind: test
	$(V_COMMAND) ./$(PATH_TO_TESTS)$(EXEC_T)

leaks: test
	$(L_COMMAND) ./$(PATH_TO_TESTS)$(EXEC_T)

coverage_flag:
	$(eval CFLAGS += --coverage)

sanitize: sanitize_flag test
	./$(PATH_TO_TESTS)$(EXEC_T)

sanitize_flag:
	$(eval CFLAGS += -fsanitize=address -fsanitize=leak)

gcov_report: coverage_flag test
	@#./$(PATH_TO_TESTS)$(EXEC_T)
	@rm -rf $(PATH_TO_TESTS)*.gcda $(PATH_TO_TESTS)*.gcno
	@rm -rf $(PATH_TO_TESTS)*.gcda $(PATH_TO_TESTS)*.gcno
	@rm -rf $(COV_REPORT)
	@mkdir $(COV_REPORT)
	@gcov -b -l -p -c $(PATH_TO_FUNCTIONS)*.gcno
	@gcovr -o $(COV_REPORT)gcov_report.html --html --html-details
	@rm -rf *.gcno && rm -rf *.gcda
	@rm -rf *.info && rm -rf *.gcov

clean:
	@rm -rf $(PATH_TO_FUNCTIONS)*.o $(EXEC) $(PATH_TO_TESTS)*.o $(PATH_TO_TESTS)./$(EXEC_T) $(PATH_TO_FUNCTIONS)a.out
	@rm -rf $(PATH_TO_FUNCTIONS)*.gcno && rm -rf $(PATH_TO_FUNCTIONS)*.gcda
	@rm -rf $(PATH_TO_FUNCTIONS)*.info && rm -rf $(PATH_TO_FUNCTIONS)*.gcov
	@rm -rf $(PATH_TO_TESTS)*.gcda $(PATH_TO_TESTS)*.gcno
	@rm -rf $(PATH_TO_TESTS)*.gcda $(PATH_TO_TESTS)*.gcno
	@rm -rf RESULT_VALGRIND.txt gcov_*
	@rm -rf $(COV_REPORT)