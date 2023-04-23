/**
\file lib.c
\brief Файл з реалізацією функцій

Цей файл, містить реалізацію функцій 'check_path_to_files', 'check_input_data', 'read_from_file', 'student_sort', 'write_out_file', 'write_on_screen'.
*/

#include "lib.h"

/**
 Функція check_arguments
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
unsigned int check_arguments(int number_arguments, char *arr_arguments[])
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
	unsigned int n_str - кількість студентів яку треба перевірити
	struct student_data test_stedent - структура куди будуть записуватися дані з файлу

- Перевіряємо чи була введена кількість студентів, як що ні то записуємо у `*(res_check)` 4 ,закриваємо файл та повертаємо 1, як що було введено ідемо далі.

- Перевіряємо чи дорвнює кількість студентів 0, як що так то записуємо у `*(res_check)` 5, закриваємо файл та повертаємо 1, як що було введено ідемо далі.

- Створюємо цикл який буде перебирати вказану кількість строки у файллі.

- Записуємо у масив `true_false` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не пробіл і записана у масив строка це не 'так' і 'ні' то записуємо у `*(res_check)` 6 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Записуємо у масив `name_student` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не пробіл  то записуємо у `*(res_check)` 7 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Записуємо у масив `name_kurator` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не пробіл  то записуємо у `*(res_check)` 8 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Записуємо у масив `name_faculti` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не пробіл  то записуємо у `*(res_check)` 9 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Записуємо у масив `group_code` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не пробіл  то записуємо у `*(res_check)` 10 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Записуємо у масив `name_cafedra` строку із файлу, після чого перевіряємо як що наступний знак у файлі це не перехід на іншу строку і записана у масив строка це не 'ВК','ГАК','У1' і 'У2' то записуємо у `*(res_check)` 11 і у *(res_check + 1) номер строки, закриваємо файл, завершкємо роботу функції.

- Як що цикл було завершено то закриваємо файл, записуємо *(res_check + 1) кількість строк і завершуємо функцію.
*/
void check_input_data(unsigned int *res_check, char *path_input_file)
{	
	FILE *input_file = fopen(path_input_file, "r");
	unsigned int n_str;
	struct student_data test_stedent;

	if (fscanf(input_file, "Кількість студентів:%d", &n_str) != 1) {
		*(res_check) = 4;
		fclose(input_file);
		return;
	} else if (n_str == 0) {
		*(res_check) = 5;
		fclose(input_file);
		return;
	}

	for (unsigned int i = 1; i <= n_str; i++) {
		fscanf(input_file, "\n%7[^;\n];", test_stedent.budget_edu);
		if (fgetc(input_file) != ' ' && strcmp(test_stedent.budget_edu, "так") != 0 && strcmp(test_stedent.budget_edu, "ні") != 0) {
			*(res_check) = 6;
			*(res_check + 1) = i;
			fclose(input_file);
			return;
		}

		fscanf(input_file, "%54[^;\n];", test_stedent.name_student);
		if (fgetc(input_file) != ' ') {
			*(res_check) = 7;
			*(res_check + 1) = i;
			fclose(input_file);
			return;
		}

		fscanf(input_file, "%54[^;\n];", test_stedent.name_kurator);
		if (fgetc(input_file) != ' ') {
			*(res_check) = 8;
			*(res_check + 1) = i;
			fclose(input_file);
			return;
		}

		fscanf(input_file, "%199[^;\n];", test_stedent.faculti.name_faculti);
		if (fgetc(input_file) != ' ') {
			*(res_check) = 9;
			*(res_check + 1) = i;
			fclose(input_file);
			return;
		}

		fscanf(input_file, "%20[^;\n];", test_stedent.group.group_n);
		if (fgetc(input_file) != ' ') {
			*(res_check) = 10;
			*(res_check + 1) = i;
			fclose(input_file);
			return;
		}

		fscanf(input_file, "%199[^;\n];", test_stedent.name_cafedra);
		if (fgetc(input_file) != '\n' || (strcmp(test_stedent.name_cafedra, "ВК") != 0 && strcmp(test_stedent.name_cafedra, "ГАК") != 0 &&
						  strcmp(test_stedent.name_cafedra, "У1") != 0 && strcmp(test_stedent.name_cafedra, "У2") != 0)) {
			*(res_check) = 11;
			*(res_check + 1) = i;
			fclose(input_file);
			return;
		}
	}
	fclose(input_file);

	*(res_check + 1) = n_str;
	return;
}




/**
Функція write_info_error
 \param *res_check - масив у якому зберігаються дані про помилку.
 
 
 Послідовність дій
 
- Перевіряємо перший елемент у масиві res_check
	1 - вивидимо повідомлення `Ви не ввели ніякі дані`  та заврешуємо програму.
	2 - вивидимо повідомлення `Ви ввели некоректну кількість даних`  та заврешуємо програму.
	3 - вивидимо повідомлення `Не можливо отримати доступ до файлу або дерикторії`  та заврешуємо програму.
	4 - вивидимо повідомлення `Ви не ввели кількість студентів`  та заврешуємо програму.
	5 - вивидимо повідомлення `Кількість студентів для сортування дорівню 0`  та заврешуємо програму.
	6 - вивидимо повідомлення `У вас помилка на строці:(№ строки), у полі форма навчання`  та заврешуємо програму.
	7 - вивидимо повідомлення `У вас помилка на строці:(№ строки), у полі ім'я студента`  та заврешуємо програму.
	8 - вивидимо повідомлення `У вас помилка на строці:(№ строки), у полі ім'я куратора`  та заврешуємо програму.
	9 - вивидимо повідомлення `У вас помилка на строці:(№ строки), у полі назва факультету`  та заврешуємо програму.
	10 - вивидимо повідомлення `У вас помилка на строці:(№ строки), у полі код групи`  та заврешуємо програму.
	11 - вивидимо повідомлення `У вас помилка на строці:(№ строки), у полі назва кафедри`  та заврешуємо програму.
	12 - вивидимо повідомлення `Для роботи програми не вистачає ресурсів комп'ютера`  та заврешуємо програму.
*/
void write_info_error(unsigned int *res_check)
{
	switch (*res_check){
	
	case 1:
		printf("Ви не ввели ніякі дані\n");
		break;

	case 2:
		printf("Ви ввели некоректну кількість даних\n");
		break;

	case 3:
		printf("Не можливо отримати доступ до файлу або дерикторії\n");
		break;
		
	case 4:
		printf("Ви не ввели кількість студентів\n\n");
		break;

	case 5:
		printf("Кількість студентів для сортування дорівню 0\n\n");
		break;

	case 6:
		printf("У вас помилка на строці:%d, у полі форма навчання\n\n", *(res_check + 1));
		break;
	
	case 7:
		printf("У вас помилка на строці:%d, у полі ім'я студента\n\n", *(res_check + 1));
		break;
	
	case 8:
		printf("У вас помилка на строці:%d, у полі ім'я куратора\n\n", *(res_check + 1));
		break;
		
	case  9:
		printf("У вас помилка на строці:%d, у полі назва факультету\n\n", *(res_check + 1));
		break;
	
	case  10:
		printf("У вас помилка на строці:%d, у полі код групи\n\n", *(res_check + 1));
		break;
		
	case  11:
		printf("У вас помилка на строці:%d, у полі назва кафедри\n\n", *(res_check + 1));
		break;
	
	case  12:
		printf("Для роботи програми не вистачає ресурсів комп'ютера\n\n");
		break;
	}
}




/**
Функція create_arr_students
 \param num_students - кількість студентів у масиві
 \return Повертає адресу на блоки пам'яті.
 
 
 Послідовність дій
 
- Виділяємо пам'ять для вказівника array стільки скільки потребуя структура student_arr.
- Перевіряємо чи була виділена пам'ять, як що ні то повертаємо значення NULL.
- Як що перевірка була пройдена то виділяємо пам'ть для поля структури students стільки скільки потребує вказівник на структуру 'student_data * num_students'.
- Перевіряємо чи була виділена пам'ять, як що ні то звільняємо пам'ять для array та повертаємо значення NULL.
- Як що перевірка була пройдена то записуємо поле array->n_students кількість студентів.
- Повертаємо адресу виділеної пам'яті.
*/
struct student_arr* create_arr_students(unsigned int num_students)
{
	struct student_arr *array = malloc(sizeof(struct student_arr));
	if(array == NULL)
		return NULL;
		
	array->students = malloc(num_students * sizeof(struct student_data*));
	if(array->students == NULL)
	{	
		free(array);
		return NULL;
	}
	array->n_students = num_students;
	
	return array;
}




/**
 Функція read_from_file
 \param *path_input_file - строка із шляхом до файлу де зберігається.
 \return Повертає адресу на блоки пам'яті.
 
 Послідовність дій
 
- Створення змінних
	FILE *input_file - вказівник на файл з вхідними даних.
	int n_str - кількість строк.
	

- Записуємо кількість строк у `n_str`.

- Викликаємо функцію `create_arr_students(n_str)`, та присвоюємо значення що вона повернула вказивнику arr_students.

- Перевіряємо те що вказівник зберігяє адресу на блоки пам'яті, як що ні то повертаємо NULL.

- Як що перевірка була пройдена створюємо цикл який буде перебирати вказану кількість строк у файллі та елементи у масиві arr_students.

- Виділяємо пам'ять для *(arr_students->students + i) стільки скільки потрібно для об'єкта структури student_data.

- Перевіряємо те що вказівник зберігяє адресу на блоки пам'яті, як що ні то звільнямо пам'ять яку виділили до цього та повертаємо NULL.

- Як що перевірка була пройдена присвоюємо полю `enroll_year` об'єкту `(*(arr_students->students + i))` 0 і записуємо у кожне поле значення із файлу.

- Викликаємо функцію `srand` для того щоб зажди генерувалося різне число.

- Створюємо цикл який буде перебирати вказану кількість елементі у масиві `*(arr_students->students)`.

- Перевіряємо як що поле `enroll_year` об'єкту `(*(arr_students->students + i))` дорівнює 0 то генеруємо рандомне значення у диапазоні від 2017 до 2022 та присвоюємо їй.

- Створюємо цикл який буде перебирати вказану кількість елементі у масиві `*(arr_students->students)`.

- Перевяряємо як що поле `group_n` об'єкту `(*(arr_students->students + j))` такаж сама яка і `(*(arr_students->students + i))` то присвоюємо `enroll_year` об'єкту `(*(arr_students->students + j))` теж саме значення що і `(*(arr_students->students + i))`.

- Закриваємо файл та повертаємо адресу на виділену пам'ять.
*/
struct student_arr* read_from_file(char *path_input_file)
{
	FILE *input_file = fopen(path_input_file, "r");
	unsigned int n_str;
	
	fscanf(input_file,"Кількість студентів:%d", &n_str);
	
	struct student_arr *arr_students = create_arr_students(n_str);
	if(arr_students == NULL)
		return NULL;
		
	
	for(unsigned int i = 0; i < n_str; i++)
	{
		*(arr_students->students + i) = malloc(sizeof(struct student_data));
		if(*(arr_students->students + i) == NULL)
		{	
			for(unsigned int j = 0; j < i; j++)
				free(*(arr_students->students + j));
			free(arr_students->students);
			free(arr_students);
			return NULL;
		}
			
		(*(arr_students->students + i))->enroll_year = 0;
		fscanf(input_file,"\n%7[^;]; %54[^;]; %54[^;]; %14[^;]; %20[^;]; %10[^;];\n",   (*(arr_students->students + i))->budget_edu, 
	 								     	 	    	(*(arr_students->students + i))->name_student,  
	 								     	 	    	(*(arr_students->students + i))->name_kurator, 
	 								     	 	    	(*(arr_students->students + i))->faculti.name_faculti, 
	 								     	 	    	(*(arr_students->students + i))->group.group_n, 
	 								     	 	    	(*(arr_students->students + i))->name_cafedra);
						  
	}
	
	srand((unsigned int)time(NULL));
	for(unsigned int i = 0; i < n_str ;i++)
	{
		if((*(arr_students->students + i))->enroll_year == 0)
		{
    			(*(arr_students->students + i))->enroll_year = rand() % 5 + 2017;
    			
    			for(unsigned int j = i ;j < n_str; j++)
    				if(strcmp((*(arr_students->students + j))->group.group_n, (*(arr_students->students + i))->group.group_n) == 0)
    					(*(arr_students->students + j))->enroll_year = (*(arr_students->students + i))->enroll_year;
    		}
		
	}
	
	fclose(input_file);
	return arr_students;
}

/**
 Функція student_sort
 \param *student -динамічний масив який треба відсортувати.
 \return Повертає адресу на блоки пам'яті.
 
 Послідовність дій
 
- Створення змінних
	int n_sort_students - кількість відсортованих студентів;
	struct student_arr *arr_sort_students - вказіник на відсортовані об'єкти

- Запускаємо цикл який знайде всі об'єкти які підходять за задиним критерієм тоб то їх поле `enroll_year` дорівню 2018.

- Викликаємо функцію `create_arr_students(n_str)`, та присвоюємо значення що вона повернула вказивнику arr_students.

- Перевіряємо те що вказівник зберігяє адресу на блоки пам'яті, як що ні то повертаємо NULL.

- Створюємо цикл який буде перебирати вказану кількість елементів у масиві `arr_students` та `*arr_sort_students`.

- Перевіряємо як що поле `enroll_year` об'єкту `(*(arr_students->students + i))` дорівнює 2018 то виділяємо пам'ять для *(arr_sort_students->students + j) стільки скільки потрібно для об'єкта структури student_data.

- Перевіряємо те що вказівник зберігяє адресу на блоки пам'яті, як що ні то звільнямо пам'ять яку виділили до цього та повертаємо NULL. 

- як що перевірка буда пройдена записуємо цей об'єкт у `*(arr_sort_students->students + j)` та додаємо до кількості відсортованих студентів 1.

- Повертаємо адресу на виділену пам'ять.
*/
struct student_arr* student_sort(struct student_arr *arr_students)
{
	unsigned int n_sort_students = 0;
	struct student_arr *arr_sort_students;
	
	for(unsigned int i = 0; i < (arr_students->n_students);i++)
	{
		if((*(arr_students->students + i))->enroll_year == 2018)
		{
			n_sort_students++;
		}
	}
	
	arr_sort_students = create_arr_students(n_sort_students);
	if(arr_sort_students == NULL)
		return NULL;
	
	for(unsigned int i = 0, j = 0; i < (arr_students->n_students); i++)
	{
		if((*(arr_students->students + i))->enroll_year == 2018)
		{	
			
			*(arr_sort_students->students + j) = malloc(sizeof(struct student_data));
			if(*(arr_sort_students->students + j) == NULL)
			{
				for(unsigned int t = 0; t < j; t++)
					free(*(arr_students->students + j));
				free(arr_sort_students->students);
				free(arr_sort_students);
				return NULL;
			}
				
			memcpy(*(arr_sort_students->students + j), *(arr_students->students + i),sizeof(struct student_data));
			j++;
		}
	}
	
	return arr_sort_students;
}

/**
 Функція write_out_file
 \param *path_output_file - шлях до файлу у який потрібно записати дані.
 \param *student -динамічний масив де зберігаються дані для виводу.
 
 Послідовність дій
 
- Створення змінних
	FILE *output_file - вказівник на файл куди треба записати вміст масиву `*student_sort`.
	

- Перевіряємо як що кількість відсортованих студентв дорівнє 0 то записуємо у файл "Кількість студентів дорівнює 0".

- Як що кількість студентів не дорівнює 0 то записуємо у файл поточну кількість студентів.

- Створюємо цикл який буде перебирати вказану кількість елементів у масиві `*(arr_sort_students->students)`.

- Записуємо у файл кожний елемент у масиві `(*(arr_sort_students->students + i))`.

- Закриваємо файл.
*/
void write_out_file(char *path_output_file,struct student_arr *arr_sort_students)
{	
	FILE *output_file = fopen(path_output_file, "w");
	
	if(arr_sort_students->n_students == 0)
		fprintf(output_file,"Кількість студентів дорівнює 0");
	else
	{	
		fprintf(output_file,"Кількість студентів дорівнює %d\n", arr_sort_students->n_students);
		
		for(unsigned int i = 0; i < (arr_sort_students->n_students); i++)
			fprintf(output_file,"\n%s; %s; %s; %s; %s; %s; %d;\n", (*(arr_sort_students->students + i))->budget_edu, 
	 								       (*(arr_sort_students->students + i))->name_student,  
	 								       (*(arr_sort_students->students + i))->name_kurator, 
	 								       (*(arr_sort_students->students + i))->faculti.name_faculti, 
	 								       (*(arr_sort_students->students + i))->group.group_n, 
	 								       (*(arr_sort_students->students + i))->name_cafedra,
	 				          		  	       (*(arr_sort_students->students + i))->enroll_year);
	}
	
	fclose(output_file);
}

/**
 Функція write_on_screen
 \param *student_sort -динамічний масив де зберігаються дані для виводу на екран.
 
 Послідовність дій
	

- Перевіряємо як що кількість відсортованих студентв дорівнє 0 то виводимо на екран "Кількість студентів дорівнює 0".

- Як що кількість студентів не дорівнює 0 то виводимо на екран поточну кількість студентів.

- Створюємо цикл який буде перебирати вказану кількість елементів у масиві `*(arr_sort_students->students)`.

- Виводимо на екран кожний елемент у масиві `(*(arr_sort_students->students + i))`.
*/
void write_on_screen(struct student_arr *arr_sort_students)
{
	
	if(arr_sort_students->n_students == 0)
		printf("Кількість студентів дорівнює 0");
	else
	{	
		printf("Кількість студентів дорівнює %d\n", arr_sort_students->n_students);
		
		for(unsigned int i = 0; i < (arr_sort_students->n_students); i++)
			printf("\n%s; %s; %s; %s; %s; %s; %d;\n", (*(arr_sort_students->students + i))->budget_edu, 
	 							  (*(arr_sort_students->students + i))->name_student,  
	 							  (*(arr_sort_students->students + i))->name_kurator, 
	 						          (*(arr_sort_students->students + i))->faculti.name_faculti, 
	 						          (*(arr_sort_students->students + i))->group.group_n, 
	 							  (*(arr_sort_students->students + i))->name_cafedra,
	 				          		  (*(arr_sort_students->students + i))->enroll_year);
	}
}









