#include "../src/lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include <math.h>


//Тести для функції "check_path_to_files"

START_TEST(test_no_write_arguments)
{	
	int number_arguments = 0;
	char* arr_arguments[1];
	int expected_code_error = 1;
	int actual_code_error;
	
	actual_code_error = check_path_to_files(number_arguments,arr_arguments);
	
	ck_assert_int_eq(expected_code_error,actual_code_error);
}
END_TEST

START_TEST(test_wrong_qu_arguments)
{	
	int number_arguments = 2;
	char *arr_arguments[1];
	int expected_code_error = 2;
	int actual_code_error;
	
	actual_code_error = check_path_to_files(number_arguments,arr_arguments);
	
	ck_assert_int_eq(expected_code_error,actual_code_error);
	
	number_arguments = 4;
	
	actual_code_error = check_path_to_files(number_arguments,arr_arguments);
	
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
	
	int expected_code_error = 3;
	int actual_code_error;
	
	actual_code_error = check_path_to_files(number_arguments,arr_arguments);
	
	ck_assert_int_eq(expected_code_error,actual_code_error);
	
	*(arr_arguments + 1) = "/home/vlad/Documents/1cours";
	*(arr_arguments + 2) = "////text.txt";
	
	actual_code_error = check_path_to_files(number_arguments,arr_arguments);
	
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
	
	int expected_code_error = 0;
	int actual_code_error;
	
	actual_code_error = check_path_to_files(number_arguments,arr_arguments);
	
	ck_assert_int_eq(expected_code_error,actual_code_error);
}
END_TEST



//Тести для функції "check_input_data"

START_TEST(test_check_n_students)
{	
	char input_file[] = "test/check_n_students/check_n_students";
	char input_file2[] = "test/check_n_students/check_n_students2";
	unsigned int result_function[2] = {0,0};
	unsigned int *res_func = result_function;
	int expected_code_error[2] = {1,0};
	
	check_input_data(res_func,input_file);
	
	ck_assert_int_eq(*(expected_code_error),*(res_func));
	
	*(expected_code_error) = 2;
	
	check_input_data(res_func,input_file2);
	
	ck_assert_int_eq(*(expected_code_error),*res_func);	
}
END_TEST

START_TEST(test_check_form_education)
{	
	char input_file[] = "test/check_form_education/check_form_education";
	unsigned int result_function[2] = {0};
	unsigned int *res_func = result_function;
	int expected_code_error[2] = {3,1};
	
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
	int expected_code_error[2] = {4,1};
	
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
	int expected_code_error[2] = {5,1};
	
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
	int expected_code_error[2] = {6,1};
	
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
	int expected_code_error[2] = {7,1};
	
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
	int expected_code_error[2] = {8,1};
	
	check_input_data(res_func,input_file);
	
	for(int i = 0; i < 2; i++)
	ck_assert_int_eq(*(expected_code_error + i),*(res_func + i));
}
END_TEST

START_TEST(test_right_write_data)
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

START_TEST(test_read_from_file)
{	
	char file[] = "test/test_input.txt";
	FILE *input_file = fopen(file,"r");
	struct student expected_student[4];
	int n_str;
	
	fscanf(input_file,"Кількість студентів:%d", &n_str);
	
	struct student actual_student[4];
	struct student *p_actual_student = actual_student;
	
	read_from_file(file, p_actual_student);
	
	for(int i = 0; i < 4; i++){
		ck_assert_int_le((*(p_actual_student + i)).enroll_year, 2022);
		ck_assert_int_ge((*(p_actual_student + i)).enroll_year, 2017);
	}
}
END_TEST


//Тести для функції "student_sort"

START_TEST(test_expected_2_students)
{	
	
	struct student student[4];
	struct student *p_student = student;
	
	(*p_student).enroll_year = 2018;
	(*(p_student + 1)).enroll_year = 2018;
	
	struct student sort_student[4];
	struct student *p_sort_student = sort_student;
	unsigned int number_students[2] = {0,4};
	unsigned int *n_students = number_students;
	int expected_n_students = 2;
	int actual_n_students;
	
	actual_n_students = student_sort(p_student, p_sort_student, n_students);
	
	ck_assert_int_eq(expected_n_students, actual_n_students);
	
}
END_TEST

START_TEST(test_expected_0_students)
{	
	
	struct student student[4];
	struct student *p_student = student;
	struct student sort_student[4];
	struct student *p_sort_student = sort_student;
	unsigned int number_students[2] = {0,4};
	unsigned int *n_students = number_students;
	int expected_n_students = 0;
	int actual_n_students;
	
	actual_n_students = student_sort(p_student, p_sort_student, n_students);
	
	ck_assert_int_eq(expected_n_students, actual_n_students);
	
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
	tcase_add_test(check_input_data, test_right_write_data);
	
	suite_add_tcase(s, check_input_data);
	
	tcase_add_test(read_from_file, test_read_from_file);
	
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
