#include <iostream>
#include <conio.h>

//задание линейного списка
using namespace std;

const int DATE = 3;

struct File
{
	string name;
	int date[DATE];//день/мес€ц/год;
	int counter;

	File* next;
};

//прототипы функций
int input_number();
int input_day();
int input_month();
int input_year();
string input_name();
void print_menu();
void add_file(File** begin);
void print_catalog(File** begin);
void delete_files(File** begin);
void find_file(File** begin);

//логика программы
int main() 
{
	setlocale(LC_ALL, "Rus");
	
	File* begin = NULL;//инициализаци€ списка
	int key = 0, amount, choice;
	while (key != 48)
	{
		print_menu();
		key = _getch();
		switch(key)
		{

		case 49://добавление элементов в каталог
		{
			system("cls");
			cout << "How many files do you want to add?\n->";
			cin >> amount;
			for (int i = 0; i < amount; i++)
			{
				add_file(&begin);
			}
		}break;

		case 50://вывод всех элементов каталога
		{
			system("cls");
			print_catalog(&begin);
		}break;

		case 51://удаление элемента из каталога
		{
			system("cls");
			delete_files(&begin);
		}break;

		case 52://вывод самого попул€рного файла
		{
			system("cls");
			find_file(&begin);
		}break;

		case 48://выход из программы
		{
			system("cls");
			cout << "Goodbuy" << endl;
			cout << endl;
		}break;

		default:
		{
			cout << "Wrong input! Press key 0 or 1..." << endl;
		}

		}
	}
	system("Pause");
	return 0;
}

//блок функций

//функци€ проверки дн€
int input_day()
{
	int day;
	while (true)
	{
		day = input_number();
		if (day >= 1 && day <= 31)
		{
			break;
		}
		else 
		{
			cout << "Wrong day!\n";
			cout << "->";
		}
	}
	return day;
}

//функции проверки мес€ца
int input_month()
{
	int month;
	while (true) 
	{
		month = input_number();
		if (month >= 1 && month <= 12)
		{
			break;
		}
		else
		{
			cout << "Wrong month!\n";
			cout << "->";
		}
	}
	return month;
}

//функции проверка года
int input_year()
{
	int year;
	while (true)
	{
		year = input_number();
		if (year >= 0 && year <= 2019)
		{
			break;
		}
		else 
		{
			cout << "Wrong year!\n";
			cout << "->";
		}
	}
	return year;
}
//¬вод натуральных чисел
int input_number()
{
	int number;

	while (!(cin >> number) || number < 0 || number != int(number))//ѕроверка правильности ввода
	{
		cin.clear();//—брос ошибки
		while (cin.get() != '\n');
		cout << "Wrong input. Input integer number.\n" << endl;
		cout << "Enter integer element -> ";
	}

	return number;
}

//¬вод имени файла
string input_name()
{
	string name;
	cin >> name;
	return name;
}

//функци€ добавлени€ файла в список
void add_file(File** begin)
{
	File* add = new File; //выделение пам€ти под новый файл
	cout << "******************************************************************\n";

	cout << "\t\t\t    |Add new file|\n" << endl;
	cout << "\t\t\tEnter the name of file\n\t\t\t-> ";
	add->name = input_name();

	cout << "\t\t\tEnter amount of views \n\t\t\t-> ";
	add->counter = input_number();

	cout << "\t\t\t\Enter the date of the release\n";
	cout << "\t\t\t    Day | Month | Year" << endl;
	for (int i = 0; i < DATE; i++)
	{
		cout << "\t\t\t->";
		if (i == 0)
		{
			add->date[i] = input_day();
		}
		else if (i == 1)
		{
			add->date[i] = input_month();
		}
		else
		{
			add->date[i] = input_year();
		}
	}
	add->next = NULL;//указатель на следующий элемент на NULL
	cout << "\n\t\t\t    |File was added!|\n";

	cout << "******************************************************************\n";
	if (*begin)//если есть 1ый элемент
	{
		File* addd = *begin; // передаем указателю add самый первый элемент
		while (true)// работает до добавлени€ элемента в список
		{
			if (!addd->next)//  если не существует указател€ на следующий
			{
				addd->next = add;// передаем элементу адрес следующего сегмента
				break;
			}
			addd = addd->next;// если же существует указатель на следующий элемент, то указателю addd передаетс€ этот элемент
		}
	}
	else//если нет 1ого элемента
	{
		*begin = add;//присваеваем в виде 1ого элемента введеный
	}
}


//вывод каталога с файлами на экран
void print_catalog(File **begin)
{
	cout << "******************************************************************\n";
	cout << "\t\t|Information about The Catalog|\n";
	if (*begin) 
	{
		File* print = *begin;
		while (true) 
		{
			cout << "------------------------------------------------------------------\n";
			cout << "Name: " << print->name << endl;
			cout << "Amount of views: " << print->counter<< endl;
			cout << "Date of creation: ";
			for(int i = 0; i < DATE; i++)
			{
				cout << print->date[i] << "/";
			}
			cout << endl;
			cout << "------------------------------------------------------------------\n";

			if (!print->next)
			{
				break;
			}

			print = print->next;
		}
	}
	else
	{
		cout << "\t\t     |The Catalog is empty|\n";
	}
	cout << "******************************************************************\n";
}

//функци€ вывода меню
void print_menu() {

	cout << "*****************************************************************\n";

	cout << "\t\t\t     |Catalog|\n" << endl;

	cout << "\t\tPress any key to make operation:\n" << endl

		<< "\t\tPress '1' to add new file.\n"

		<< "\t\tPress '2' to print the catalog.\n"

		<< "\t\tPress '3' to delete files, which were\n" 
		<< "\t\t\t  created after certain date.\n"

		<< "\t\tPress '4' to get the most popular file.\n"

		<< "\t\tPress '0' to exit from program.\n";

	cout << "\n*****************************************************************\n";
}

//функци€ удалени€ элементов с датой меньше заданной
void delete_files(File** begin)
{
	int day_c;
	int month_c;
	int year_c;
	int counter = 0;
	cout << "*****************************************************************\n";

	cout << "\t\t     |Delete files from Catalog|\n" << endl;
	cout << "\t\tEnter a verifying day   -> ";
	day_c = input_day();
	cout << "\t\tEnter a verifying month -> ";
	month_c = input_month();
	cout << "\t\tEnter a verifying year  -> ";
	year_c = input_year();

	File* prev_p = NULL, * del_p, *p = *begin;

	if (!(*begin))
	{
		cout << "\n\t\t\t |Catalog is empty.|" << endl;
		cout << "*****************************************************************\n";
		return;
	}
	while (true)
	{
		counter += 1;
		if (year_c > p->date[2] || (year_c == p->date[2] && month_c > p->date[1]) || 
			(year_c == p->date[2] && month_c == p->date[1] && day_c > p->date[0]))//первый элемент
		{
			if (counter == 1)//если элемент 1ый или элемент единственный 
			{
				if(!p->next)
				{
					*begin = NULL;
					delete p;
					break;
				}
				else
				{
					del_p = p;
					p = p->next;
					*begin = p; //изменение первого элемента исходного списка
					delete del_p;
					counter = 0;
				}
			}
			else if (!p->next)//последний элемент
			{
				del_p = p;
				prev_p->next = NULL;//предыдущий указатель указывает на нулл
				delete del_p;
				break;
			}
			else//остальные элементы
			{
				prev_p->next = p->next;//измен€ем указатель предыдущего через объект
				del_p = p;
				p = p->next;
				delete del_p;
			}
		}
		else//если элемент подходит
		{
			if (!p->next)
			{
				break;
			}
			prev_p = p;
			p = p->next;
		}
	}
	cout << "\t\t\t |Files were deleted|\n" << endl;
	cout << "*****************************************************************\n";
}
//функци€ вывода файла с наибольшим количеством просмотров
void find_file(File** begin)
{
	File *certain_file = NULL, *p = *begin;
	int max = 0;
	while (true)
	{
		if(p->counter > max)
		{
			certain_file = p;
			max = certain_file->counter;
		}
		if (!p->next)
		{
			break;
		}

		p = p->next;
	}
	cout << "*****************************************************************\n";
	cout << "\n\tThe largest part of views has file with name ' " << certain_file->name << " '.";
	cout << "\n\t\t  This file has - " << certain_file->counter << " views.";
	cout << "\n\t\tThe date of creation: " << certain_file->date[0] << "/" << certain_file->date[1] << "/" << certain_file->date[2] << endl;
	cout << "\n*****************************************************************\n";

}