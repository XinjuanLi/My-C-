#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

class Student;
class Teacher;
class Homework;
class Course;
class Note;
class Teaching;


class Homework
{
private:
	char *homework;
public:
	Homework(const char *homework);
	Homework();
	char* correctHomework();
    char* getHomework();
	void setHomework(Teacher &t1,Student &s1);
	~Homework();
	friend char *content();
};

class Student
{
private:
	char *studentName;
	int age;
	double score;
public:
	Student(const char*n1, int age, double score);
	void setname(const char *p1);
	char *getName();
	~Student();
	friend class Teaching;
	friend class Homework;
	static int studentNum;
	Homework home1;
};

class Teacher
{
private:
	char *teacherName;
public:
	Teacher(const char*n2);
	Teacher(Teacher &t);
	void setname(const char *x1);
	char *getName();
	~Teacher();
	friend class Teaching;
	friend class Homework;
};

class Course
{
private:
	char *courseName;
public:
	Course(const char *n3);
	~Course();
	friend class Teaching;
};


class Note
{
private:
    char *noteContent;
    friend char *content();
};


class Teaching
{
public:
	static void show(Teacher &t1, Student &s1);
	static void show(Teacher &t1, Student &s1,Student &s2);
	static void show(Teacher &t1, Student &s1,Student &s2,Student &s3);
	Teaching(Teacher &t1, Course &c1);
};


Student::Student(const char *n1, int age, double score):home1("C plus plus")
{
	this->age = age;
	this->score = score;
	if (n1)
	{
		studentName = new char[strlen(n1) + 1];
		strcpy(studentName, n1);
	}
	else
	{
		studentName = new char[11];
		strcpy(studentName, "Wu Mingshi");
	}
	studentNum++;
}

char* Student::getName()
{
    return studentName;
}

Student::~Student()
{
	delete[]studentName;
}

void Student::setname(const char *p1)
{
	studentName = new char[strlen(p1) + 1];
	strcpy(studentName,p1);
}

int Student::studentNum = 0;

Teacher::Teacher(const char *n2)
{
	if (n2)
	{
		teacherName = new char[strlen(n2) + 1];
		strcpy(teacherName, n2);
	}
	else
	{
		teacherName = new char[8];
		strcpy(teacherName, "Teacher");
	}
}

Teacher::Teacher(Teacher &t)
{
	if (t.teacherName)
	{
		teacherName = new char[strlen(t.teacherName) + 1];
		strcpy(teacherName, t.teacherName);
	}
	else
	{
		teacherName = new char[8];
		strcpy(teacherName, "Jiang");
	}
}

char* Teacher::getName()
{
    return teacherName;
}

void Teacher::setname(const char *x1)
{
	teacherName = new char[strlen(x1) + 1];
	strcpy(teacherName,x1);
}

Teacher::~Teacher()
{
	delete[]teacherName;
}

Course::Course(const char *n3)
{
	if (n3)
	{
		courseName = new char[strlen(n3) + 1];
		strcpy(courseName, n3);
	}
	else
	{
		courseName = new char[4];
		strcpy(courseName, "C++");
	}
}

Course::~Course()
{
	delete[]courseName;
}

Homework::Homework(const char *homework)
{
	if (homework)
	{
		this->homework = new char[strlen(homework) + 1];
		strcpy(this->homework,  homework);
	}
	else
	{
		this->homework = new char[12];
		strcpy(this->homework,  "no homework");
	}
}

Homework::Homework()
{
	homework = new char[12];
	strcpy(homework, "no homework");
}

char* Homework::getHomework()
{
    return homework;
}

void Homework::setHomework(Teacher &t1,Student &s1)
{
    cout<<"Teacher "<<t1.getName()<<" sets "<<getHomework()<<" to student "<<s1.getName()<<endl;
}

Homework::~Homework()
{
	delete[]homework;
}

void Teaching::show(Teacher &t1, Student &s1)
{
	cout << s1.studentName << "'s teacher is Teacher " << t1.teacherName << endl;
}

void Teaching::show(Teacher &t1, Student &s1, Student &s2)
{
	cout << s1.studentName << "'s teacher is Teacher " << t1.teacherName << endl;
	cout << s2.studentName << "'s teacher is Teacher " << t1.teacherName << endl;
}

void Teaching::show(Teacher &t1, Student &s1,Student &s2,Student &s3)
{
	cout << s1.studentName << "'s teacher is Teacher " << t1.teacherName << endl;
	cout << s2.studentName << "'s teacher is Teacher " << t1.teacherName << endl;
	cout << s3.studentName << "'s teacher is Teacher " << t1.teacherName << endl;
}

Teaching::Teaching(Teacher &t1, Course &c1)
{
	cout << "Teacher " << t1.teacherName << " teaches " << c1.courseName << endl;
}

//char *content(char *c)
//{
//    char *content;
//    content=new char[strlen(c)+1];
//    strcpy(content,c);
//    return content;
//}

int main(void)
{
	Student stud[2] = { Student("Zhang san",20,60),Student("Wang wu",19,70) };
	Student stud2 = stud[1];
	Teacher teac0("Jiang");
	Teacher teac1=teac0;
	Course cour0("C++");
	const char *px="Wang mazi";
	stud2.setname(px);
	Teaching::show(teac0,stud[0],stud[1],stud2);
	Teaching(teac0, cour0);
	Homework h1("teaching process");
	h1.setHomework(teac0,stud[1]);
	return 0;
}
