/**
 * @brief It tests space module
 *
 * @file space_test.c
 * @author Profesores Pprog
 * @version 0.0
 * @date 17-02-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"
#include "space_test.h"
#include "test.h"

/**
 * @brief Defines maximum number of test per execution
 */
#define MAX_TESTS 30

/**
 * @brief Main function for SPACE unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char **argv)
{

	int test = 0;
	int all = 1;

	if (argc < 2)
	{
		printf("Running all test for module Space:\n");
	}
	else
	{
		test = atoi(argv[1]);
		all = 0;
		printf("Running test %d:\t", test);
		if (test < 1 && test > MAX_TESTS)
		{
			printf("Error: unknown test %d\t", test);
			exit(EXIT_SUCCESS);
		}
	}

	if (all || test == 1)
		test1_space_create();
	if (all || test == 2)
		test2_space_create();
	if (all || test == 3)
		test1_space_set_name();
	if (all || test == 4)
		test2_space_set_name();
	if (all || test == 5)
		test3_space_set_name();
	if (all || test == 14)
		test1_space_set_object();
	if (all || test == 15)
		test2_space_set_object();
	if (all || test == 16)
		test1_space_get_id();
	if (all || test == 17)
		test2_space_get_id();
	if (all || test == 18)
		test1_space_get_name();
	if (all || test == 19)
		test2_space_get_name();
	if (all || test == 28)
		test1_space_get_object();
	if (all || test == 29)
		test2_space_get_object();
	if (all || test == 30)
		test3_space_get_object();

	PRINT_PASSED_PERCENTAGE;

	return 1;
}

/**
 * @brief Tests space_create function
 */
void test1_space_create()
{
	int result;
	Space *s;
	s = space_create(5);
	result = s != NULL;
	PRINT_TEST_RESULT(result);
	space_destroy(s);
}

/**
 * @brief Tests space_create function
 */
void test2_space_create()
{
	Space *s;
	s = space_create(4);
	PRINT_TEST_RESULT(space_get_id(s) == 4);
	space_destroy(s);
}

/**
 * @brief Tests space_set_name function
 */
void test1_space_set_name()
{
	Space *s;
	s = space_create(5);
	PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
	space_destroy(s);
}

/**
 * @brief Tests space_set_name function
 */
void test2_space_set_name()
{
	Space *s = NULL;
	PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

/**
 * @brief Tests space_set_name function
 */
void test3_space_set_name()
{
	Space *s;
	s = space_create(5);
	PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
	space_destroy(s);
}

/**
 * @brief Tests space_set_object function
 */
void test1_space_set_object()
{
	Space *s;
	s = space_create(1);
	PRINT_TEST_RESULT(space_set_object(s, TRUE) == OK);
	space_destroy(s);
}

/**
 * @brief Tests space_set_object function
 */
void test2_space_set_object()
{
	Space *s = NULL;
	PRINT_TEST_RESULT(space_set_object(s, TRUE) == ERROR);
}

/**
 * @brief Tests space_get_name function
 */
void test1_space_get_name()
{
	Space *s;
	s = space_create(1);
	space_set_name(s, "adios");
	PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
	space_destroy(s);
}

/**
 * @brief Tests space_get_name function
 */
void test2_space_get_name()
{
	Space *s = NULL;
	PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

/**
 * @brief Tests space_get_object function
 */
void test1_space_get_object()
{
	Space *s;
	s = space_create(1);
	PRINT_TEST_RESULT(space_get_object(s, 1) == FALSE);
	space_destroy(s);
}

/**
 * @brief Tests space_get_object function
 */
void test2_space_get_object()
{
	Space *s;
	s = space_create(1);
	set_add(space_get_object_locations(s), 1);
	PRINT_TEST_RESULT(space_get_object(s, 1) == TRUE);
	space_destroy(s);
}

/**
 * @brief Tests space_get_object function
 */
void test3_space_get_object()
{
	Space *s = NULL;
	PRINT_TEST_RESULT(space_get_object(s, 1) == FALSE);
}

/**
 * @brief Tests space_get_id function
 */
void test1_space_get_id()
{
	Space *s;
	s = space_create(25);
	PRINT_TEST_RESULT(space_get_id(s) == 25);
	space_destroy(s);
}

/**
 * @brief Tests space_get_id function
 */
void test2_space_get_id()
{
	Space *s = NULL;
	PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}
