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
			else{
				fclose(input_file);
				fclose(output_file);
				return 0;
			}
				
		}
	}

	return 1;
}

unsigned int* check_input_data(unsigned int *res_check, char path_input_file[])
{	
	FILE *input_file = fopen(path_input_file, "r");
	unsigned int n_str;
	char true_false[8];
	char name_student[55];
	char name_kurator[55];
	char name_faculti[200];
	char group_code[21];
	char name_cafedra[200];
	
	if(fscanf(input_file,"Кількість студентів:%d", &n_str) != 1)
	{	
		*(res_check) = 1;
		fclose(input_file);
		return res_check;
	}
	else if(n_str == 0)
	{	
		*(res_check) = 2;
		fclose(input_file);
		return res_check;
	}
	
	for(unsigned int i = 1; i <= n_str; i++)
	{	
		
		fscanf(input_file,"\n%7[^;\n];", true_false);
		if(fgetc(input_file) != ' ' && strcmp(true_false, "так") != 0 && strcmp(true_false, "ні") != 0){
			*(res_check) = 3;
			*(res_check + 1) = i;
			fclose(input_file);
			return res_check;
		}	
		
			
		fscanf(input_file,"%54[^;\n];", name_student);
		if(fgetc(input_file) != ' '){
			*(res_check) = 4;
			*(res_check + 1) = i;
			fclose(input_file);
			return res_check;
		}
			
		fscanf(input_file,"%54[^;\n];", name_kurator);
		if(fgetc(input_file) != ' '){
			*(res_check) = 5;
			*(res_check + 1) = i;
			fclose(input_file);
			return res_check;
		}
		
		fscanf(input_file,"%199[^;\n];", name_faculti);
		if(fgetc(input_file) != ' '){
			*(res_check) = 6;
			*(res_check + 1) = i;
			fclose(input_file);
			return res_check;
		}
		
		fscanf(input_file,"%20[^;\n];", group_code);
		if(fgetc(input_file) != ' '){
			*(res_check) = 7;
			*(res_check + 1) = i;
			fclose(input_file);
			return res_check;
		}
		
		fscanf(input_file,"%199[^;\n];", name_cafedra);
		if(fgetc(input_file) != '\n' || (strcmp(name_cafedra, "ВК") != 0 && strcmp(name_cafedra, "ГАК") != 0 && strcmp(name_cafedra, "У1") != 0 && strcmp(name_cafedra, "У2") != 0)){
			*(res_check) = 8;
			*(res_check + 1) = i;
			fclose(input_file);
			return res_check;
		}
	}
	fclose(input_file);
	
	*(res_check + 1) = n_str;			
	return 0;
}

void read_from_file(char path_input_file[], struct student *student)
{
	FILE *input_file = fopen(path_input_file, "r");
	int n_str;
	
	fscanf(input_file,"Кількість студентів:%d", &n_str);
	
	for(int i = 0; i < n_str; i++)
	{	
		(*(student + i)).enroll_year = 0;
		fscanf(input_file,"\n%7[^;]; %54[^;]; %54[^;]; %199[^;]; %20[^;]; %199[^;];\n", (*(student + i)).budget_edu, 
	 								     	 	    	(*(student + i)).name_student,  
	 								     	 	    	(*(student + i)).name_kurator, 
	 								     	 	    	(*(student + i)).faculti.name_faculti, 
	 								     	 	    	(*(student + i)).group.group_n, 
	 								     	 	    	(*(student + i)).name_cafedra);
													  
	}
	
	srand((unsigned int)time(NULL));
	for(int i = 0; i < n_str ;i++)
	{
		if((*(student + i)).enroll_year == 0)
		{
    			(*(student + i)).enroll_year = rand() % 5 + 2017;
    			
    			for(int j = i ;j < n_str; j++)
    				if(strcmp((*(student + j)).group.group_n, (*(student + i)).group.group_n) == 0)
    					(*(student + j)).enroll_year = (*(student + i)).enroll_year;
    		}
		
	}
	
	fclose(input_file);
}

int student_sort(struct student *student, struct student *student_sort, unsigned int *n_students)
{
	int n_sort_students = 0;
	
	for(unsigned int i = 0;i < *(n_students + 1);i++)
	{
		if((*(student + i)).enroll_year == 2018)
		{
			(*(student_sort + n_sort_students)) = (*(student + i));
			n_sort_students++;
		}
	}
	
	return n_sort_students;
}

void write_out_file(char path_output_file[], struct student *student_sort, int n_sort_students)
{	
	FILE *output_file = fopen(path_output_file, "w");
	
	if(n_sort_students == 0)
		fprintf(output_file,"Кількість студентів дорівнює 0");
	else
	{	
		fprintf(output_file,"Кількість студентів дорівнює %d\n", n_sort_students);
		for(int i = 0; i < n_sort_students; i++)
			fprintf(output_file,"\n%s; %s; %s; %s; %s; %s; %d;\n", (*(student_sort + i)).budget_edu, 
	 				      	  		  	       (*(student_sort + i)).name_student,  
	 				          		  	       (*(student_sort + i)).name_kurator, 
	 				          		  	       (*(student_sort + i)).faculti.name_faculti, 
	 				          		  	       (*(student_sort + i)).group.group_n, 
	 				          		  	       (*(student_sort + i)).name_cafedra,
	 				          		  	       (*(student_sort + i)).enroll_year);
	}
	
	fclose(output_file);
}

void write_on_screen(struct student *student_sort, int n_sort_students)
{
	if(n_sort_students == 0)
		printf("Кількість студентів дорівнює 0");
	else
	{	
		printf("Кількість студентів дорівнює %d\n", n_sort_students);
		for(int i = 0; i < n_sort_students; i++)
			printf("\n%s; %s; %s; %s; %s; %s; %d;\n", (*(student_sort + i)).budget_edu, 
	 				      	  		  (*(student_sort + i)).name_student,  
	 				          		  (*(student_sort + i)).name_kurator, 
	 				          		  (*(student_sort + i)).faculti.name_faculti, 
	 				          		  (*(student_sort + i)).group.group_n, 
	 				          		  (*(student_sort + i)).name_cafedra,
	 				          		  (*(student_sort + i)).enroll_year);
	}
}









