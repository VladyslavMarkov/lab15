/**
\file lib.c
\brief Файл з реалізацією функцій

Цей файл, містить реалізацію функцій 'check_path_to_files', 'check_input_data', 'read_from_file', 'student_sort', 'write_out_file', 'write_on_screen'.
*/

#include "lib.h"

/**
 Функція check_path_to_files
 \param number_arguments - кількість аргументів.
 \param *arr_arguments[] - масив аргусентів.
 \return Повертає номер перевірки як що та не була пройдена або нуль як що все гаразд.
 
 
 Послідовність дій
 
- Створення змінних
	FILE *output_file - вказівник на файл для вихідних даних.
	FILE *input_file - вказівник на файл з вхідними даних.

- Перевіряємо чи були введені якісь значення, як що ні то повертаємо 1, як що було щось введено ідемо далі.

- Перевіряємо чи дійснану кількість значень ввів користувач, як що ні то повертаємо 2, як що кількість значень задовільна ідемо далі.

- Присвоємо вказівнику на наші файл та відкриваємо їх.

- Перевіряємо чи були присвоєні файли їх вказівникам, як що так тоді закриваємо їх і повертаємо 0, як що ні  повертаємо 3.

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

/**
 Функція check_input_data
 \param *res_check - масив у якому зберігаються дані про помилку.
 \param path_input_file[] - шлях до файлу у якому превіряється правильність внесення даних.
 \return Повертає масив у якому номер перевірки як що та не була пройдена та строка де помилка або нуль і кількість строк.
 
 
 Послідовність дій
 
- Створення змінних
	FILE *input_file - вказівник на файл з вхідними даних.
	unsigned int n_str - номер строки у файлі.
	char true_false[8] - масив у якому зберігається відповідь на питання чи набжеті студент або ні.
	char name_student[55] -  масив у якому зберігається ім'я студента.
	char name_kurator[55] -  масив у якому зберігається ім'я куратора.
	char name_faculti[15] - масив у якому зберігається назва факультету.
	char group_code[21] -  масив у якому зберігається номер групи.
	char name_cafedra[200] - масив у якому зберігається ім'я куратора назва кафедри.

- Перевіряємо чи була введена кількість студентів, як що ні то записуємо у `*(res_check)` 1 ,закриваємо файл та повертаємо 1, як що було введено ідемо далі.

- Перевіряємо чи дорвнює кількість студентів 0, як що так то записуємо у `*(res_check)` 2 ,закриваємо файл та повертаємо 1, як що було введено ідемо далі.

- Створюємо цикл який буде перебирати вказану кількість строки у файллі.

- Записуємо у масив `true_false` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не пробіл і записана у масив строка це не 'так' і 'ні' то записуємо у `*(res_check)` 3 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Записуємо у масив `name_student` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не пробіл  то записуємо у `*(res_check)` 4 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Записуємо у масив `name_kurator` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не пробіл  то записуємо у `*(res_check)` 5 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Записуємо у масив `name_faculti` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не пробіл  то записуємо у `*(res_check)` 6 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Записуємо у масив `group_code` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не пробіл  то записуємо у `*(res_check)` 7 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Записуємо у масив `name_cafedra` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не перехід на іншу строку і записана у масив строка це не 'ВК','ГАК','У1' і 'У2' то записуємо у `*(res_check)` 8 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Як що цикл було завершено то закриваємо файл, записуємо *(res_check + 1) кількість строк і завершуємо функцію.
*/

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

/**
 Функція read_from_file
 \param *res_check - масив у якому зберігаються шлях до файлу із данми.
 \param *student -динамічний масив куди їх треба записати.
 
 Послідовність дій
 
- Створення змінних
	FILE *input_file - вказівник на файл з вхідними даних.
	int n_str - кількість строк.
	

- Записуємо кількість строк у `n_str`.

- Створюємо цикл який буде перебирати вказану кількість строки у файллі та елементи у масиві `*student`.

- Присвоюємо власитивості `enroll_year` об'єкту `*(student + i)` і записуємо у кожну властивість значення із файлу.

- Викликаємо функцію `srand` для того щоб зажди генерувалося різне число.

- Створюємо цикл який буде перебирати вказану кількість елементі у масиві `*student`.

- Перевіряємо як що властивість `enroll_year` об'єкту `*(student + i)` дорівнює 0 то генеруємо рандомне значення у диапазоні від 2017 до 2022 та присвоюємо їй.

- Створюємо цикл який буде перебирати вказану кількість елементі у масиві `*student`.

- Перевяряємо як що валистивість `group_n` об'єкту `*(student + j)` такаж сама яка і `*(student + i)` то присвоюємо `enroll_year` об'єкту `*(student + j)` теж саме значення що і `*(student + i)`.

- закриваємо файл.
*/
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

/**
 Функція student_sort
 \param *student -динамічний масив який треба відсортувати.
 \param *student_sort - динамічний масив у який треба записати відсортовані елементи.
 \param *n_students - вказівник на масив де зберіється кількість студентів.
 \return Повертає кількість відсортованих елементів.
 
 Послідовність дій
 
- Створення змінних
	int n_sort_students - кількість відсортованих студентів;
	

- Записуємо кількість строк у `n_str`.

- Створюємо цикл який буде перебирати вказану кількість елементів у масиві `*student` та `*student_sort`.

- Перевіряємо як що властивість `enroll_year` об'єкту `*(student + i)` дорівнює 2018 то записуємо цей об'єкт у `*(student_sort + n_sort_students)` та додаємо до кількості відсортованих студентів 1.

- Повертаємо кількість відсортованих студентів.
*/
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

/**
 Функція write_out_file
 \param path_input_file[] - шлях до файлу у який потрібно записати дані.
 \param *student_sort -динамічний масив де зберігаються дані для запису.
 \param n_sort_students - кількість елементів у масиві вище.
 
 Послідовність дій
 
- Створення змінних
	FILE *output_file - вказівник на файл куди треба записати вміст масиву `*student_sort`.
	

- Перевіряємо як що кількість відсортованих студентв дорівнє 0 то записуємо у файл "Кількість студентів дорівнює 0".

- Як що кількість студентів не дорівнює 0 то записуємо у файл поточну кількість студентів.

- Створюємо цикл який буде перебирати вказану кількість елементів у масиві `*student_sort`.

- Записуємо у файл кожний елемент у масиві `*student_sort`.
*/
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

/**
 Функція write_out_file
 \param *student_sort -динамічний масив де зберігаються дані для запису.
 \param n_sort_students - кількість елементів у масиві вище.
 
 Послідовність дій
	

- Перевіряємо як що кількість відсортованих студентв дорівнє 0 то виводимо на екран "Кількість студентів дорівнює 0".

- Як що кількість студентів не дорівнює 0 то виводимо на екран поточну кількість студентів.

- Створюємо цикл який буде перебирати вказану кількість елементів у масиві `*student_sort`.

- Виводимо на екран кожний елемент у масиві `*student_sort`.
*/
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









