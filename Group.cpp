#include "Group.h"
#include "Student.h"

Group::Group()
{
	count_of_student = 0;
	student = new Student[count_of_student];
	name_of_group = new char[100];
	strcpy_s(name_of_group, 99, "Избранные");
	specialization = new char[100];
	strcpy_s(specialization, 99, "Маркетинг и мененджмент");
	course = 3;
}

Group::Group(int count_of_student)
{

	if (count_of_student < 0)
	{
		throw "OPPS!";
	}
	else
	{
		this->count_of_student = count_of_student;
	}
	student = new Student[this->count_of_student];
	name_of_group = new char[100];
	strcpy_s(name_of_group, 99, "Избранные");
	specialization = new char[100];
	strcpy_s(specialization, 99, "Маркетинг и мененджмент");
	course = 3;
}

Group::Group(const char* name_of_group, const char* specialization)
{
	count_of_student = 0;
	student = new Student[this->count_of_student];
	this->name_of_group = new char[100];
	strcpy_s(this->name_of_group, 99, name_of_group);
	this->specialization = new char[100];
	strcpy_s(this->specialization, 99, specialization);
	course = 3;
}

Group::Group(int count_of_student, const char* name_of_group, const char* specialization)
{
	if (count_of_student < 0)
	{
		throw "OPPS!";
	}
	else
	{
		this->count_of_student = count_of_student;
	}
	student = new Student[this->count_of_student];
	this->name_of_group = new char[100];
	strcpy_s(this->name_of_group, 99, name_of_group);
	this->specialization = new char[100];
	strcpy_s(this->specialization, 99, specialization);
	course = 3;
}

Group::Group(const Group& original)
{
	count_of_student = original.count_of_student;
	student = new Student[count_of_student];
	for (int i = 0; i < count_of_student; i++)
	{
		student[i] = original.student[i];
	}
	name_of_group = new char[100];
	strcpy_s(name_of_group, 99, original.name_of_group);
	specialization = new char[100];
	strcpy_s(specialization, 99, original.specialization);
	course = original.course;
}

Group::~Group()
{
	if (student != nullptr) delete[] student;
	if (name_of_group != nullptr) delete[] name_of_group;
	if (specialization != nullptr) delete[] specialization;
}


void Group::Set_course(int course)
{
	this->course = course;
}

int Group::Get_course() const
{
	return course;
}

void Group::Set_name_of_group(const char* name_of_group)
{
	delete[] this->name_of_group;
	this->name_of_group = new char[100];
	strcpy_s(this->name_of_group, 99, name_of_group);
	
}

void Group::Set_specialization(const char* specialization)
{
	delete[] this->specialization;
	this->specialization = new char[100];
	strcpy_s(this->specialization, 99, specialization);
}

void Group::Show_Group()  // показ всех студентов группы
{
	cout << "----------------------------------" << endl;
	cout << "----------------------------------" << endl;
	cout << "Информация о группе: " << endl;
	cout << "Название группы: " << name_of_group << endl;
	cout << "Специализация группы: " << specialization << endl;
	cout << "Номер курса: " << Get_course() << endl;
	if (count_of_student > 0)
	{
		cout << "Студенты: " << endl;
		for (int i = 0; i < count_of_student; i++)
		{
			student[i].Show_Student();
			cout << endl;
		}
	}
	else
	{
		cout << "Группа пустая" << endl;
	}

}

void Group::Add_Student()
{
	Student *new_student = new Student[count_of_student+1];
	for (int i = 0; i < count_of_student; i++)
	{
		new_student[i] = student[i];
	}
	count_of_student++;
	student = new Student[count_of_student];
	for (int i = 0; i < count_of_student-1; i++)
	{
		student[i] = new_student[i];
	}
}

void Group::Dismiss_for_exam()  // отчисление студента за несдавший экз
{
	Student* new_student = new Student[count_of_student];
	for (int i = 0; i < count_of_student; i++)
	{
		new_student[i] = student[i];
	}
	int count_of_exam = 0;
	for (int i = 0; i < count_of_student; i++)
	{
		if (new_student[i].Get_exam() == 1)
		{
			count_of_exam++;
		}
	}
	student = new Student[count_of_exam];
	int j = 0;
	for (int i = 0; i < count_of_student; i++)
	{
		if (new_student[i].Get_exam() == 1)
		{
			student[j] = new_student[i];
			j++;
		}
	}
	count_of_student = count_of_exam;
}

void Group::Dismiss_for_credits() // метод отчисления неуспевающего студента
{
	float MIN;
	MIN = student[0].Get_avegare_rating();
	for (int i = 1; i < count_of_student; i++)
	{
		if (student[i].Get_avegare_rating() < MIN)
		{
			MIN = student[i].Get_avegare_rating();
		}
		else
		{
			continue;
		}
	}
	count_of_student--;
	Student* new_student = new Student[count_of_student];
	for (int i = 0; i < count_of_student; i++)
	{
		if (student[i].Get_avegare_rating() == MIN)
		{
			for (int j = i; j < count_of_student; j++)
			{
				new_student[j] = student[j + 1];
			}
			break;
		}
		new_student[i] = student[i];
	}
	student = new Student[count_of_student];
	for (int i = 0; i < count_of_student; i++)
	{
		student[i] = new_student[i];
	}
}


void Group::Merge_groups(const Group& first, const Group& second)
{
	
	this->count_of_student = first.count_of_student + second.count_of_student;
	this->student = new Student[this->count_of_student];
	for (int i = 0; i < first.count_of_student; i++)
	{
		this->student[i] = first.student[i];
	}
	for (int i = first.count_of_student; i < count_of_student; i++)
	{
		this->student[i] = second.student[i - first.count_of_student];
	}
	
}

// первоначальный вариант слияния двух груп

//void Group::Sum_group(const Group& original)// метод слияния двух групп
//{
//	
//	Student* new_student = new Student[count_of_student+original.count_of_student];
//	for (int i = 0; i <count_of_student ; i++)
//	{
//		new_student[i] = student[i];
//	}
//	for (int i = count_of_student; i < count_of_student+original.count_of_student; i++)
//	{
//		new_student[i] = original.student[i-count_of_student];
//	}
//	count_of_student += original.count_of_student;
//	for (int i = 0; i < count_of_student; i++)
//	{
//		student[i] = new_student[i];
//	}
//}


// прошлые варианты модов отчисления

//void Group::Add_Student()
//{
//
//	Student* new_student = new Student[count_of_student + 1];
//	for (int i = 0; i < count_of_student; i++)
//	{
//		new_student[i] = student[i];
//	}
//	//new_student[count_of_student] = Student();
//	count_of_student++;
//	//delete[] student;
//
//	student = new Student[count_of_student];
//	for (int i = 0; i < count_of_student - 1; i++)
//	{
//		student[i] = new_student[i];
//	}
//
//	//delete[] new_student;
//
//}

//void Group::Dismiss_for_exam()  // отчисление студента за несдавший экз
//{
//	int count_of_student_2 = 0;
//	Student* new_student = new Student[count_of_student];
//	for (int i = 0; i < count_of_student; i++)
//	{
//		new_student[i] = student[i];
//	}
//
//	int j = 0;
//	student = new Student[count_of_student_2];
//	for (int i = 0; i < count_of_student; i++)
//	{
//		if (new_student[i].Get_exam() == 0)
//		{
//			continue;
//		}
//		else
//		{
//			count_of_student_2++;
//			student[j] = new_student[i];
//			//count_of_student_2++;
//			j++;
//		}
//	}
//	count_of_student = count_of_student_2 + 1;  //?
//}


//Student* new_student_1 = new Student[first.count_of_student];
//for (int i = 0; i < first.count_of_student; i++)
//{
//	new_student_1[i] = first.student[i];
//}
//Student* new_student_2 = new Student[second.count_of_student];
//for (int i = 0; i < second.count_of_student; i++)
//{
//	new_student_2[i] = second.student[i];
//}
//
//count_of_student = first.count_of_student + second.count_of_student;
//student = new Student[count_of_student];
//for (int i = 0; i < first.count_of_student; i++)
//{
//	student[i] = new_student_1[i];
//}
//for (int i = first.count_of_student; i < count_of_student; i++)
//{
//	student[i] = new_student_2[i - first.count_of_student];
//}