#include "Student.h"

Student::Student()
{
	const char* Surname[10] = { "������", "�������" , "���������" , "�������" , "�������" , "��������"
				, "���������" , "�������" , "���������" , "���������" };
	surname = new char[100];
	strcpy_s(surname, 99, Surname[rand() % 10]);
	const char* Name[10] = { "�����" , "�������","������","����","�������","����������", "���������",
		"�������","����","������" };
	name = new char[100];
	strcpy_s(name, 99, Name[rand() % 10]);
	const char* Patronomic[10] = { "����������", "����������","��������","����������",
		"����������","�������","���������","���������","��������","���������" };
	patronymic = new char[100];
	strcpy_s(patronymic, 99, Patronomic[rand() % 10]);
	age = rand() % 4 + 17;
	credits = new int[10];
	for (int i = 0; i < 10; i++)
	{
		credits[i] = rand() % 11 + 1;
	}
	float sum = 0 ;
	for (int i = 0; i < 10; i++)
	{
		sum += credits[i];
	}
	average_rating = sum / 10;
	exam = rand() % 2;
	
}

Student::Student(const char* surname, const char* name, const char* patronymic)
{
	this->surname = new char[100];
	strcpy_s(this->surname, 99, surname);
	this->name = new char[100];
	strcpy_s(this->name, 99, name);
	this->patronymic = new char[100];
	strcpy_s(this->patronymic, 99, patronymic);
	age = rand() % 4 + 17;
	credits = new int[10];
	for (int i = 0; i < 10; i++)
	{
		credits[i] = rand() % 11 + 1;
	}
	float sum=0;
	for (int i = 0; i < 10; i++)
	{
		sum += credits[i];
	}
	average_rating = sum / 10;
	exam = rand() % 2;
}

Student::~Student()
{
	if (surname != nullptr)
	{
		delete[] surname;
	}
	if (name != nullptr)
	{
		delete[] name;
	}
	if (patronymic != nullptr)
	{
		delete[] patronymic;
	}
	if (credits != nullptr)
	{
		delete[] credits;
	}
}

const char* Student::Get_name() 
{
	return name;
}

const char* Student::Get_surname() 
{
	return surname;
}

const char* Student::Get_patronymic() 
{
	return patronymic;
}

float Student::Get_avegare_rating() const
{
	return average_rating;
}

int Student::Get_age()const
{
	return age;
}

void Student::Show_credits() const
{
	for (int i = 0; i < 10; i++)
	{
		cout << credits[i] << "  ";
	}
}

bool Student::Get_exam() const
{
	return exam;
}

void Student::Show_Student()
{
	cout << "-----------------" << endl;
	cout << "���������� � ��������: " << endl;
	cout << "�������: " << Get_surname() << endl;
	cout << "���: " << Get_name() << endl;
	cout << "��������: " << Get_patronymic() << endl;
	cout << "�������: " << Get_age() << endl;
	cout << "������: ";
	Show_credits();
	cout << "\n����� ��������: " << boolalpha << Get_exam() << endl;
	cout << "������� ������ ��������: " << average_rating << endl;
}


