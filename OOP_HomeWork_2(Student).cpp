#include "Student.h"
#include "Group.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));
	

	Group A(5);
	A.Show_Group();
	A.Add_Student();
	A.Show_Group();
	
	
	

	return 0;
}