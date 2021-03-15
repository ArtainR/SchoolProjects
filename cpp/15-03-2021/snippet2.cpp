#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct student
{
	string name, surname, classroom;
	vector<int> grades;
};

struct classroom
{
	vector<student> students;
};

int main()
{
	string imie, nazwisko, klasa;

	classroom myClassroom;
	while(true)
	{
		student myStudent;
		cout << "Input name: ";
		cin >> myStudent.name;
		cout << "Input surname: ";
		cin >> myStudent.surname;
		cout << "Input class: ";
		cin >> myStudent.classroom;
		int grade = -1;
		while(grade != 0)
		{
			cout << "Input grade: (0 to exit): ";
			cin >> grade;
			if(grade > 0 && grade <= 6)
			{
				myStudent.grades.push_back(grade);
			}
		}
		myClassroom.students.push_back(myStudent);
		string cont = "y";
		cout << "Do you want to continue? (y/n)" << endl;
		cin >> cont;
		system("clear");
		if(cont == "n")
		{
			break;
		}
	}
	fstream file;
	file.open("journal.txt", ios::out | ios::app);
	int loopFor = myClassroom.students.size();
	float totalGrades;
	float totalGradeCount;
	for(int i = 0; i < loopFor; i++)
	{
		file << myClassroom.students[i].name << endl;
		file << myClassroom.students[i].surname << endl;
		file << myClassroom.students[i].classroom << endl;
		int gradeCount = myClassroom.students[i].grades.size();
		totalGradeCount += gradeCount;
		if(gradeCount != 0)
		{
			cout << "Grades of student " + myClassroom.students[i].name + " " + myClassroom.students[i].surname + ", from class " + myClassroom.students[i].classroom + ": " << endl;
			for(int o = 0; o < gradeCount; o++)
			{
				cout << to_string(myClassroom.students[i].grades[o]);
				file << to_string(myClassroom.students[i].grades[o]);
				totalGrades += myClassroom.students[i].grades[o];
				if(o != gradeCount - 1)
				{
					cout << ", ";
					file << ", ";
				}
			}
			cout << endl;
			file << endl;
		}
	}
	cout << "Class average: " << totalGrades / totalGradeCount << endl;
	file.close();

	return 0;
}
