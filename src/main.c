/**
 * \mainpage
 * # Лабораторна робота №13
 *
 * \author Марков Владислав, КН-922б
 * \date 03-04-2023
 */

/*!
\file main.c
\brief Головний файл

Це файл, який містить точку входу, код для запису строки,
виклики функцій CreateConst та код виводу результату її роботи .
*/

#include "lib.h"

/**
 Головна функція.

 Послідовність дій

- Створення змінних
	str - маисв куди записуємо строку
	res - число яке сформувала функція.
	
	
- Виводимо на екран інформацію про автора, номер, тему лабараторної роботи , і що виконує програма
- Записуємо строку яку ввів користувач
- Викликаємо функцію CreateConst та записуємо результат який вона повернула у змінну res
- Виводимо результат на екран
*/

int main(int argc, char* argv[])
{
	char path_input_file[4096] = {0};
	char path_output_file[4096] = {0};
	unsigned int result_check[2] = {0,0};
	unsigned int *res_check = result_check;
	int n_sort_students;
	struct student *sort_student;
	struct student *student;
	
	printf("\nАвтор:Марков Владислав\nГрупа:КН-922Б\nНомер лабараторної роботи:15\nТема:Структуровані типи даних\n\n");
	printf("Вивести список усіх студентів які поступили у 2018р.\n\n");
		
	switch (check_path_to_files(argc, argv)){
	case 01:
		printf("Ви не ввели ніякі дані\n");
		return 1;
		break;

	case 02:
		printf("Ви ввели некоректну кількість даних\n");
		return 1;
		break;

	case 03:
		printf("Не можливо отримати доступ до файлу або дерикторії\n");
		return 1;
		break;
	}
	
	strcat(path_output_file,*(argv + 2));
	strcat(path_input_file,*(argv + 1));
	
	
	check_input_data(res_check, path_input_file);

	switch (*res_check){
	case 1:
		printf("Ви не ввели кількість студентів\n\n");
		return 1;
		break;

	case 2:
		printf("Кількість студентів для сортування дорівню 0\n\n");
		return 1;
		break;

	case 3:
		printf("У вас помилка на строці:%d, у полі форма навчання\n\n", *(res_check + 1));
		return 1;
		break;
	
	case 4:
		printf("У вас помилка на строці:%d, у полі ім'я студента\n\n", *(res_check + 1));
		return 1;
		break;
	
	case 5:
		printf("У вас помилка на строці:%d, у полі ім'я куратора\n\n", *(res_check + 1));
		return 1;
		break;
		
	case  6:
		printf("У вас помилка на строці:%d, у полі назва факультету\n\n", *(res_check + 1));
		return 1;
		break;
	
	case  7:
		printf("У вас помилка на строці:%d, у полі код групи\n\n", *(res_check + 1));
		return 1;
		break;
		
	case  8:
		printf("У вас помилка на строці:%d, у полі назва кафедри\n\n", *(res_check + 1));
		return 1;
		break;
	}
	
	student = malloc(sizeof(struct student) * *(res_check + 1));
	sort_student = malloc(sizeof(struct student) * *(res_check + 1));
	
	read_from_file(path_input_file, student);
	
	n_sort_students = student_sort(student, sort_student, res_check);
	
	write_out_file(path_output_file, sort_student, n_sort_students);
	
	write_on_screen(sort_student, n_sort_students);
	
	free(student);
	free(sort_student);
	
	return 0;
}

















