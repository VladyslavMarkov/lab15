#include "../src/lib.h"
#include <check.h>




//Тести для функції "check_arguments"

START_TEST(test_no_write_arguments)
{	
	int number_arguments = 0;
	char* arr_arguments[1];
	unsigned int expected_code_error = 1;
	unsigned int actual_code_error;
	
	actual_code_error = check_arguments(number_arguments,arr_arguments);
	
	ck_assert_int_eq(expected_code_error,actual_code_error);
}
END_TEST

START_TEST(test_wrong_qu_arguments)
{	
	int number_arguments = 2;
	char *arr_arguments[1];
	unsigned int expected_code_error = 2;
	unsigned int actual_code_error;
	
	actual_code_error = check_arguments(number_arguments,arr_arguments);
	
	ck_assert_int_eq(expected_code_error,actual_code_error);
	
	number_arguments = 4;
	
	actual_code_error = check_arguments(number_arguments,arr_arguments);
	
	ck_assert_int_eq(expected_code_error,actual_code_error);
}
END_TEST

START_TEST(test_not_correct_path)
{	
	int number_arguments = 3;
	char *arr_arguments[3];
	
	*(arr_arguments) = "0";
	*(arr_arguments + 1) = "homi////";
	*(arr_arguments + 2) = "dist/text.txt";
	
	unsigned int expected_code_error = 3;
	unsigned int actual_code_error;
	
	actual_code_error = check_arguments(number_arguments,arr_arguments);
	
	ck_assert_int_eq(expected_code_error,actual_code_error);
	
	*(arr_arguments + 1) = "/home/vlad/Documents/1cours";
	*(arr_arguments + 2) = "////text.txt";
	
	actual_code_error = check_arguments(number_arguments,arr_arguments);
	
	ck_assert_int_eq(expected_code_error,actual_code_error);
}
END_TEST

START_TEST(test_true_arguments)
{	
	int number_arguments = 3;
	char *arr_arguments[3];
	
	*(arr_arguments) = "0";
	*(arr_arguments + 1) = "test/test_input.txt";
	*(arr_arguments + 2) = "dist/true_arguments.txt";
	
	unsigned int expected_code_error = 0;
	unsigned int actual_code_error;
	
	actual_code_error = check_arguments(number_arguments,arr_arguments);
	
	ck_assert_int_eq(expected_code_error,actual_code_error);
}
END_TEST




//Тести для функції "check_input_data"

START_TEST(test_check_n_students)
{	
	char input_file[] = "test/check_n_students/check_n_students";//не введено кільеість студентів
	char input_file2[] = "test/check_n_students/check_n_students2";// кількість студенів 0
	unsigned int result_function[2] = {0,0};
	unsigned int *res_func = result_function;
	int expected_code_error[2] = {4,0};
	
	check_input_data(res_func,input_file);
	
	ck_assert_int_eq(*(expected_code_error),*(res_func));
	
	*(expected_code_error) = 5;
	
	check_input_data(res_func,input_file2);
	
	ck_assert_int_eq(*(expected_code_error),*res_func);	
}
END_TEST

START_TEST(test_check_form_education)
{	
	char input_file[] = "test/check_form_education/check_form_education";
	unsigned int result_function[2] = {0};
	unsigned int *res_func = result_function;
	int expected_code_error[2] = {6,1};
	
	check_input_data(res_func,input_file);
	
	for(int i = 0; i < 2; i++)
	ck_assert_int_eq(*(expected_code_error + i),*(res_func + i));
}
END_TEST

START_TEST(test_check_name_students)
{	
	char input_file[] = "test/check_name_students/check_name_students";
	unsigned int result_function[2] = {0,0};
	unsigned int *res_func = result_function;
	int expected_code_error[2] = {7,1};
	
	check_input_data(res_func,input_file);
	
	for(int i = 0; i < 2; i++)
	ck_assert_int_eq(*(expected_code_error + i),*(res_func + i));
}
END_TEST

START_TEST(test_check_name_curator)
{	
	char input_file[] = "test/check_name_curator/check_name_curator";
	unsigned int result_function[2] = {0};
	unsigned int *res_func = result_function;
	int expected_code_error[2] = {8,1};
	
	check_input_data(res_func,input_file);
	
	for(int i = 0; i < 2; i++)
	ck_assert_int_eq(*(expected_code_error + i),*(res_func + i));
}
END_TEST

START_TEST(test_check_name_faculti)
{	
	char input_file[] = "test/test_check_name_faculti/test_check_name_faculti";
	unsigned int result_function[2] = {0};
	unsigned int *res_func = result_function;
	int expected_code_error[2] = {9,1};
	
	check_input_data(res_func,input_file);
	
	for(int i = 0; i < 2; i++)
	ck_assert_int_eq(*(expected_code_error + i),*(res_func + i));
}
END_TEST

START_TEST(test_check_group_number)
{	
	char input_file[] = "test/check_group_number/check_group_number";
	unsigned int result_function[2] = {0};
	unsigned int *res_func = result_function;
	int expected_code_error[2] = {10,1};
	
	check_input_data(res_func,input_file);
	
	for(int i = 0; i < 2; i++)
	ck_assert_int_eq(*(expected_code_error + i),*(res_func + i));
}
END_TEST

START_TEST(test_check_name_cafedra)
{	
	char input_file[] = "test/check_name_cafedra/check_name_cafedra";
	unsigned int result_function[2] = {0};
	unsigned int *res_func = result_function;
	int expected_code_error[2] = {11,1};
	
	check_input_data(res_func,input_file);
	
	for(int i = 0; i < 2; i++)
	ck_assert_int_eq(*(expected_code_error + i),*(res_func + i));
}
END_TEST

START_TEST(test_true_write_data)
{	
	char file[] = "test/test_input.txt";
	unsigned int actual_result_function[2] = {0};
	unsigned int *actual_res_func = actual_result_function;
	int expected_result_function[2] = {0,4};
	
	check_input_data(actual_res_func,file);
	
	for(int i = 0; i < 2; i++)
	ck_assert_int_eq(*(expected_result_function + i),*(actual_res_func + i));
}
END_TEST




//Тести для функції "read_from_file"

START_TEST(test_geration_enroll_year)
{	
	char file[] = "test/test_input.txt";
	struct student_arr *actual_arr_students;
	struct student_arr *expected_arr_sort_students = create_arr_students(0);
	
	actual_arr_students = read_from_file(file);
	
	for(int i = 0; i < 4; i++){
		ck_assert_int_le((*(actual_arr_students->students + i))->enroll_year, 2022);
		ck_assert_int_ge((*(actual_arr_students->students + i))->enroll_year, 2017);
	}
	
	for(unsigned int i = 0; i < actual_arr_students->n_students; i++)
		free(*(actual_arr_students->students + i));
	free(actual_arr_students->students);
	free(actual_arr_students);
	free(expected_arr_sort_students->students);
	free(expected_arr_sort_students);
}
END_TEST




//Тести для функції "student_sort"

START_TEST(test_expected_2_students)
{	
	
	struct student_arr *arr_students = create_arr_students(2);
	for(int i = 0; i < 2; i++)
		*(arr_students->students + i) = malloc(sizeof(struct student_data));
	
	(*(arr_students->students))->enroll_year = 2018;
	(*(arr_students->students + 1))->enroll_year = 2018;
	
	struct student_arr *expected_arr_sort_students = create_arr_students(2);
	struct student_arr *actual_arr_sort_students;
	
	actual_arr_sort_students = student_sort(arr_students);
	
	ck_assert_int_eq(expected_arr_sort_students->n_students, actual_arr_sort_students->n_students);
	
	for(unsigned int i = 0; i < arr_students->n_students; i++)
		free(*(arr_students->students + i));
	free(arr_students->students);
	free(arr_students);
	
	free(expected_arr_sort_students->students);
	free(expected_arr_sort_students);
	
	for(unsigned int i = 0; i < actual_arr_sort_students->n_students; i++)
		free(*(actual_arr_sort_students->students + i));
	free(actual_arr_sort_students->students);
	free(actual_arr_sort_students);
	
	
}
END_TEST

START_TEST(test_expected_0_students)
{	
	struct student_arr *arr_students = create_arr_students(2);
	for(int i = 0; i < 2; i++)
		*(arr_students->students + i) = malloc(sizeof(struct student_data));
		
	(*(arr_students->students))->enroll_year = 2017;
	(*(arr_students->students + 1))->enroll_year = 2017;
	
	struct student_arr *expected_arr_sort_students = create_arr_students(0);
	struct student_arr *actual_arr_sort_students;
	
	actual_arr_sort_students = student_sort(arr_students);
	
	ck_assert_int_eq(expected_arr_sort_students->n_students, actual_arr_sort_students->n_students);
	
	for(unsigned int i = 0; i < arr_students->n_students; i++)
		free(*(arr_students->students + i));
	free(arr_students->students);
	free(arr_students);
	
	free(expected_arr_sort_students->students);
	free(expected_arr_sort_students);
	
	free(actual_arr_sort_students->students);
	free(actual_arr_sort_students);
}
END_TEST




Suite *lab_test_suite(void)
{
	Suite *s;
	TCase *check_path_to_files;
	TCase *check_input_data;
	TCase *read_from_file;
	TCase *student_sort;

	s = suite_create("lab15");

	check_path_to_files = tcase_create("check_path_to_files");
	check_input_data = tcase_create("check_input_data");
	read_from_file = tcase_create("read_from_file");
	student_sort = tcase_create("student_sort");
	
	tcase_add_test(check_path_to_files, test_no_write_arguments);
	tcase_add_test(check_path_to_files, test_wrong_qu_arguments);
	tcase_add_test(check_path_to_files, test_not_correct_path);
	tcase_add_test(check_path_to_files, test_true_arguments);
	
	suite_add_tcase(s, check_path_to_files);
	
	tcase_add_test(check_input_data, test_check_n_students);
	tcase_add_test(check_input_data, test_check_form_education);
	tcase_add_test(check_input_data, test_check_name_students);
	tcase_add_test(check_input_data, test_check_name_curator);
	tcase_add_test(check_input_data, test_check_name_faculti);
	tcase_add_test(check_input_data, test_check_group_number);
	tcase_add_test(check_input_data, test_check_name_cafedra);
	tcase_add_test(check_input_data, test_true_write_data);
	
	suite_add_tcase(s, check_input_data);
	
	tcase_add_test(read_from_file, test_geration_enroll_year);
	
	suite_add_tcase(s, read_from_file);
	
	tcase_add_test(student_sort, test_expected_2_students);
	tcase_add_test(student_sort, test_expected_0_students);
	
	suite_add_tcase(s, student_sort);
	
	return s;
}

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = lab_test_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
