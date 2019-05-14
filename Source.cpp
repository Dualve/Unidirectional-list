#include <iostream>
#include <conio.h>
#include <string>
//������� c����

using namespace std;


///////////////////////// - ����
struct steck

{

	string word;

	steck* next;

};

///////////////////////// - ��������� �������
void push(steck*& next, string word);
string pop(steck*& next);
string rev_word(string word);
void print_menu();
int input_number();

//////////////////////// - ���������� ����
int main()
{
	setlocale(LC_ALL, "Rus");
	steck* p = 0; // ������������� �����
	int n;
	int check = 0;
	string word;

	while (check != 48)
	{
		print_menu();
		check = _getch(); // ��������� ������� ������� � ��������� �� ���
		switch (check)
		{

		case 49:
		{
			// ���� ��������� � ����
			cout << "Enter count of words for stack -> ";
			n = input_number();
			cout << "Enter " << n << " str words:\n";
			for (int i = 0; i < n; i++)
			{
				cout << "Enter " << i + 1 << " word -> ";
				cin >> word;
				push(p, word);
			}
			cout << endl;
			// ����� ��������� �� �����
			for (int i = 0; i < n; i++)
			{
				word = rev_word(pop(p));
				cout << "Word " << i + 1 << " " << word << endl;
			}
			cout << endl;

		}break;

		case 48:
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

////////////////////////// - �������� �������
//������� ���������� �������� � ����
void push(steck*& next, string word)
{
	steck* Stack = new steck;
	Stack->word = word;
	Stack->next = next;//� ���� ������ �������� ��������� �� ���������� �������
	next = Stack;// ��������� ��������� ���� ������ �� Stack
}

//������� ������� �������� �� �����
string pop(steck*& next)
{
	string temp = next->word;
	
	steck* MyStack = next;
	next = next->next;
	delete MyStack;

	return temp;

}

//������� ������ ����
void print_menu() {

	cout << "*****************************************************************\n";

	cout << "\t\t\t     |Steck|\n" << endl;

	cout << "\t\tPress any key to make operation:\n" << endl

		<< "\t\tPress '1' to create new steck\n"

		<< "\t\tPress '0' to exit from program.\n";

	cout << "\n*****************************************************************\n";

}

//������� �������� ����� �����
int input_number()
{
	int number;

	while (!(cin >> number) || number < 0 || number != int(number))//�������� ������������ �����
	{
		cin.clear();//����� ������
		while (cin.get() != '\n');
		cout << "Wrong input. Input integer number.\n" << endl;
		cout << "Enter integer element -> ";
	}

	cout << "Successfully!\n\n" << endl;
	return number;
}

//������� ������� ����������� ������ ������
// begin - ���������� �������� � ������ ���������
// end - ���������� �������� � ��������� ���������
// lenght - ���������� ���������� �������� � ������
// reverse - ������ ������� ��������� ���������� � ���������
// ������ - ����� �� ���������������
string rev_word(string word)
{
	if (word.length()) 
	{
		reverse(word.begin(), word.end());
	}
	return word;
}
