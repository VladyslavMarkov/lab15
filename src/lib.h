/*!
\file lib.h
\brief Бібіиотечный файл

Це файл, який містить декларацію функції CreateConst.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct group
{
	char name_faculti[200];
	int group_n;
};

struct student
{
	bool budget_edu;
	char name_student[55];
	char name_kurator[55];
	int enroll_year;
	struct group name_faculti;
	struct group group_n;
	char name_cafedra;
};

/**
Функція mul_matrix
 \param a[] - масив у якому зберігається строка яку ввів користувач.
 \return Повертає сформоване число або нуль.
*/

int check_path_to_files(int number_arguments, char *arr_arguments[]);

int* check_input_data(int *error_data, char path_input_file[]);

int write_out_file();















