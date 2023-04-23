/**
 * \mainpage
 * # Лабораторна робота №15
 *
 * \author Марков Владислав, КН-922б
 * \date 24-04-2023
 */

/*!
\file main.c
\brief Головний файл

Це файл, який містить точку входу і виклики функцій 'check_arguments', 'check_input_data', 'read_from_file', 'student_sort', 'write_out_file', 'write_on_screen'.
*/

#include "lib.h"

/**
 Головна функція.

 Послідовність дій

- Створення змінних
	unsigned int result_check[2] - маисв для запису результату преевірки, перше значення номер перевірки, строка у якій помилка.
	unsigned int *res_check - вказівник на масив вище.
	struct student_arr *arr_sort_students - вакзівник типу структуру у якому потім будемо зберігати відсортовані вказівники на об'єкти структиру student_data.
	struct student_arr *arr_students - вакзівник типу структури у якому потім будемо зберігати вказівники на об'єкти структиру student_data.
	
- Виводимо на екран інформацію про автора, номер, тему лабараторної роботи , і що виконує програма
- Викликаємо функцію `check_arguments(argc, argv)`, як що вона повернула номер перевірки який не дорівнє 0 то викликаємо функцію `write_info_error(res_check)` повертаємо 1.
- Як що перевірка була пройдена викликаємо функцію `check_input_data(res_check, *(argv + 1))`, як що вона повернула номер перевірки який не дорівнє 0 то викликаємо функцію `write_info_error(res_check)` повертаємо 1.
- Як що перевірка була пройдена викликаємо функцію `read_from_file(*(argv + 1))`, присвоюємо значення що вона повернула вказівнику arr_students.
- Перевіряємо те що вказівник зберігяє адресу на блоки пам'яті, як що ні то записуємо у масив result_check[0] значення 12 та викликаємо функцію `write_info_error(res_check)`, і повертаємо 1.
- Як що перевірка була пройдена викликаємо функцію `student_sort(arr_students)`, присвоюємо значення що вона повернула вказівнику arr_sort_students.
- Перевіряємо те що вказівник зберігяє адресу на блоки пам'яті, як що ні то записуємо у масив result_check[0] значення 12 та викликаємо функцію `write_info_error(res_check)`, і повертаємо 1.
- Як що перевірка була пройдена викликаємо функцію `write_out_file` та `write_on_screen`.
- Звільняємо пам'ять яку ми виділяли для наших вказівників та завершуємо роботу програми.
*/
int main(int argc, char* argv[])
{
	unsigned int result_check[2] = {0,0};
	unsigned int *res_check = result_check;
	struct student_arr *arr_sort_students;
	struct student_arr *arr_students;
	
	printf("\nАвтор:Марков Владислав\nГрупа:КН-922Б\nНомер лабараторної роботи:15\nТема:Структуровані типи даних\n\n");
	printf("Вивести список усіх студентів які поступили у 2018р.\n\n");
		
		
		
		
	if((*res_check = check_arguments(argc, argv)) != 0){
	
		write_info_error(res_check);
		return 1;
	
	}
	
	check_input_data(res_check, *(argv + 1));
	if(*res_check != 0){
	
		write_info_error(res_check);
		return 1;
	
	}
	
	
	
	
	arr_students = read_from_file(*(argv + 1));
	if(arr_students == NULL)
	{	
		*res_check = 12;
		write_info_error(res_check);
		return 1;
	}
	
	arr_sort_students = student_sort(arr_students);
	if(arr_sort_students == NULL)
	{	
		*res_check = 12;
		write_info_error(res_check);
		return 1;
	}
	
	write_out_file(*(argv + 2), arr_sort_students);
	write_on_screen(arr_sort_students);
	
	for(unsigned int i = 0; i < arr_students->n_students; i++)
		free(*(arr_students->students + i));
	free(arr_students->students);
	free(arr_students);
	
	for(unsigned int i = 0; i < arr_sort_students->n_students; i++)
		free(*(arr_sort_students->students + i));
	free(arr_sort_students->students);
	free(arr_sort_students);
	
	return 0;
}

















