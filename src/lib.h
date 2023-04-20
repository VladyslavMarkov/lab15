/*!
\file lib.h
\brief Бібіиотечный файл

Це файл, який містить декларацію функцій 'check_path_to_files', 'check_input_data', 'read_from_file', 'student_sort', 'write_out_file', 'write_on_screen' та ініціалізацію структур 'group', 'student.
*/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>




/**
Структура group
 	char name_faculti[15] - масив у якому зберігається назва факультету.
	char group_n[21] -  масив у якому зберігається номер групи.
*/
struct group
{
	char name_faculti[15];
	char group_n[21];
};




/**
Структура student
 	char budget_edu[8] - масив у якому зберігається відповідь на питання чи набжеті студент або ні.
	name_student[55] -  масив у якому зберігається ім'я студента.
	name_kurator[55] -  масив у якому зберігається ім'я куратора.
	int enroll_year - рік у якому поступив студент.
	struct group faculti - об'єкт типу структури group.
	struct group group - об'єкт типу структури group.
	char name_cafedra[200] - масив у якому зберігається ім'я куратора назва кафедри.
*/
struct student_data
{
	char budget_edu[8];
	char name_student[55];
	char name_kurator[55];
	int enroll_year;
	struct group faculti;
	struct group group;
	char name_cafedra[200];
};

struct student_arr
{
	unsigned int n_students;
	unsigned int n_sort_students;
	struct student_data **students;
};




/**
Функція check_path_to_files
 \param number_arguments - кількість аргументів.
 \param *arr_arguments[] - масив аргусентів.
 \return Повертає номер перевірки як що та не була пройдена або нуль як що все гаразд.
*/
unsigned int check_arguments(int number_arguments, char *arr_arguments[]);




/**
Функція check_input_data
 \param *res_check - масив у якому зберігаються дані про помилку.
 \param path_input_file[] - шлях до файлу у якому превіряється правильність внесення даних.
 \return Повертає масив у якому номер перевірки як що та не була пройдена та строка де помилка або нуль і кількість строк.
*/
void check_input_data(unsigned int *res_check, char *path_input_file);



void write_info_error(unsigned int *res_check);



struct student_arr* create_arr_students(unsigned int num_students);




/**
Функція read_from_file
 \param *res_check - масив у якому зберігаються шлях до файлу із данми.
 \param *student -динамічний масив куди їх треба записати.
*/
//void read_from_file(char path_input_file[], struct student *student);




/**
Функція student_sort
 \param *student -динамічний масив який треба відсортувати.
 \param *student_sort - динамічний масив у який треба записати відсортовані елементи.
 \param *n_students - вказівник на масив де зберіється кількість студентів.
 \return Повертає кількість відсортованих елементів.
*/
//int student_sort(struct student *student, struct student *student_sort, unsigned int *n_students);




/**
Функція write_out_file
 \param path_input_file[] - шлях до файлу у який потрібно записати дані.
 \param *student_sort -динамічний масив де зберігаються дані для запису.
 \param n_sort_students - кількість елементів у масиві вище.
*/
//void write_out_file(char path_output_file[], struct student *student_sort, int n_sort_students);




/**
Функція write_out_file
 \param *student_sort -динамічний масив де зберігаються дані для виводу на екран.
 \param n_sort_students - кількість елементів у масиві вище.
*/
//void write_on_screen(struct student *student_sort, int n_sort_students);















