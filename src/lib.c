/**
\file lib.c
\brief Файл з реалізацією функцій

Цей файл, містить реалізацію функції CreateConst.
*/

#include "lib.h"

/**
 
 Функція mul_matrix
 \param a[] - масив у якому зберігається строка яку ввів користувач.
 \return Повертає сформоване число або нуль.
 
 
 Послідовність дій
 
- Створення змінних
	number_letter - кількість букв у слові
	res - число яке сформувала функція.

- Перевіряємо порожня наша строка чи ні, як що так то повертємо 0.

- Як що строка не порожня то рахуємо скільки в ній літер та цифр.

- Запускаємо цил який буде пребирати слова у нашому речені.

- Запускаємо другий цикл який буде преебирати літери у нашому слові.

- Первіряємо як що це латиниця або число то додаємо до j + 1. Як що не те не інше перевіряємо на те чи це кирилиця, як що так то додаємо до кількості літер +1 і до j та i +1 так як кирилиця займає два байти. Як що це щось інше завершуємо цикл та переходимо до наступного слова.

- Потім присвоюємо різницю між j та кількітю літер змінній number_letter, таким чином слова у яких є кирилиця дорівнюють кількості символлів а не кількості занятих байт.

- Перевіряємо як що у слові кількість літер більша ніж 10 то множимо змінну res на 100 та додаємо кількість літер, як що менше десяти то множимо змінну res на 10 та додаємо кількість літер.

- Повертаємо res. 

*/

int check_path_to_files(int number_arguments, char *arr_arguments[])
{
	FILE *output_file;
	FILE *input_file;

	if (number_arguments > 1) {
		if (number_arguments != 3)
			return 2;
		else {
			output_file = fopen(*(arr_arguments + 2), "w");
			input_file = fopen(*(arr_arguments + 1), "r");

			if (output_file == NULL || input_file == NULL)
				return 3;
			else
				return 0;
		}
	}

	return 1;
}

int* check_input_data(int *error_data, char path_input_file[])
{	
	FILE *input_file = fopen(path_input_file, "r");
	int n_str;
	bool budget_edu = false;
	char name_student[55];
	char name_kurator[55];
	char name_faculti[200];
	char group_code[21];
	char name_cafedra[200];
	
	if(fscanf(input_file,"Кількість студентів:%d", &n_str) != 1)
	{	
		*(error_data) = 1;
		return error_data;
	}
	else if(n_str == 0)
	{	
		*(error_data) = 2;
		return error_data;
	}
	
	for(int i = 1; i <= n_str; i++)
	{	
		char true_false[8];
		fscanf(input_file,"\n%7[^;\n];", true_false);
		if(fgetc(input_file) != ' ' && strcmp(true_false, "так") != 0 && strcmp(true_false, "ні") != 0){
			*(error_data) = 3;
			*(error_data + 1) = i;
			return error_data;
		}	
		memset(true_false,0,8);
			
		fscanf(input_file,"%54[^;\n];", name_student);
		if(fgetc(input_file) != ' '){
			*(error_data) = 4;
			*(error_data + 1) = i;
			return error_data;
		}
			
		fscanf(input_file,"%54[^;\n];", name_kurator);
		if(fgetc(input_file) != ' '){
			*(error_data) = 5;
			*(error_data + 1) = i;
			return error_data;
		}
		
		fscanf(input_file,"%199[^;\n];", name_faculti);
		if(fgetc(input_file) != ' '){
			*(error_data) = 6;
			*(error_data + 1) = i;
			return error_data;
		}
		
		fscanf(input_file,"%20[^;\n];", group_code);
		if(fgetc(input_file) != ' '){
			*(error_data) = 7;
			*(error_data + 1) = i;
			return error_data;
		}
		
		fscanf(input_file,"%199[^;\n];", name_cafedra);
		if(fgetc(input_file) != '\n' || (strcmp(name_cafedra, "ВК") != 0 && strcmp(name_cafedra, "ГАК") != 0 && strcmp(name_cafedra, "У1") != 0 && strcmp(name_cafedra, "У2") != 0)){
			*(error_data) = 8;
			*(error_data + 1) = i;
			return error_data;
		}
	}
							
	return error_data;
}

int write_out_file()
{
	return 0;
}
