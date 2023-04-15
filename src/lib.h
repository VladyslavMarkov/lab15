/*!
\file lib.h
\brief Бібіиотечный файл

Це файл, який містить декларацію функції CreateConst.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct group
{
	char name_faculti[15];
	char group_n[21];
};

struct student
{
	char budget_edu[8];
	char name_student[55];
	char name_kurator[55];
	int enroll_year;
	struct group faculti;
	struct group group;
	char name_cafedra[200];
};

/**
Функція mul_matrix
 \param a[] - масив у якому зберігається строка яку ввів користувач.
 \return Повертає сформоване число або нуль.
*/

int check_path_to_files(int number_arguments, char *arr_arguments[]);

unsigned int* check_input_data(unsigned int *res_check, char path_input_file[]);

void read_from_file(char path_input_file[], struct student *student);

int student_sort(struct student *student, struct student *student_sort, unsigned int *n_students);

void write_out_file(char path_output_file[], struct student *student_sort, int n_sort_students);

void write_on_screen(struct student *student_sort, int n_sort_students);















