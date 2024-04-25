// Repository=> We store data in it
// #include <bits/stdc++.h>
#include "../Model/Models.cpp"

using namespace std;

// * Static Data *
class Data
{
public:
  static Student students[25];
  static int indexStudent;
  static int idStudent;

  static Teacher teachers[25];
  ;
  static int indexTeacher;
  static int idTeacher;

  static Course courses[25];
  ;
  static int indexCourse;
  static int idCourse;
};
// * Init Static Data *
Student Data::students[25];
int Data::indexStudent = 0;
int Data::idStudent = 1;

Teacher Data::teachers[25];
int Data::indexTeacher = 0;
int Data::idTeacher = 1;

Course Data::courses[25];
int Data::indexCourse = 0;
int Data::idCourse = 1;

// *********** Student ***************
//* Interface for StudentRepository *
class StudentRepository
{
public:
  virtual int addStudent(Student student) = 0; // Pure virtual function
  virtual Student getStudentById(int id) = 0;  // Pure virtual function
  virtual Student getStudentByName(string name) = 0; // Pure virtual function
  virtual int showAll () = 0; // Pure virtual function
  virtual int editStudent(Student student) = 0; 
};
// class for StudentRepositoryImp
class StudentRepositoryImp : public StudentRepository
{
private:
  Data data;
  Student invalidStudent;
  int indexx = -1;
public:
  // Add Student To the System
  int addStudent(Student student)
  {
    
    if (data.indexStudent == 25)
    {
      cout << "Full Student ";
      return -1;
    }
    else
    {
      student.setId(data.idStudent++);
      data.students[data.indexStudent] = student;
      data.indexStudent++;
    }
    return student.getId();
  }
  // Show Student By Id 
  Student getStudentById(int id)
  {
    for (int i = 0; i < data.indexStudent; i++)
    {
      if(data.students[i].getId() == id){
        return data.students[i];
      }
    }
    invalidStudent.setId(-1);
    return invalidStudent;
  }
  // Show Student By Name
  Student getStudentByName(string name) {
    for (int i = 0; i < data.indexStudent; i++)
    {
      if(data.students[i].getName() == name){
        return data.students[i];
      }
    }
    invalidStudent.setName("");
    return invalidStudent;
  }
  // Show All Students
  int showAll () {
    if (data.students[0].getName() == "") {
      return -1;
    }
    else {
    Student arrayStudents[25];
    for (int i = 0; i < data.indexStudent; i++) {
      arrayStudents[i] = data.students[i];
      cout << "Student " << i +1 << " Data :"<< endl;
      cout << "Student Name         : " << arrayStudents[i].getName() << endl;
      cout << "Student Id           : " << arrayStudents[i].getId() << endl;
      cout << "Student Age          : " << arrayStudents[i].getAge() << endl;
      cout << "Student Gpa          : " << arrayStudents[i].getGpa() << endl;
      cout << "Student Phone Number : " << arrayStudents[i].getphoneNumber() << endl;
      cout << "************************************\n";
  }
    }
    return 0;
  } 
  // Edit Students 
  int editStudent(Student student) {
    for (int i = 0; i < data.indexStudent; i++) {
      if(data.students[i].getId() == student.getId()) {
        indexx = i;
        break;
      }
    }
    if(indexx == -1) {
      return -1;
    } else {
      data.students[indexx] = student;
      return indexx;
    }
  }
};

// *********** Course ***************
// Interface for courseRepository
class CourseRepository
{
public:
  virtual int addCourse(Course course) = 0;
  virtual Course getCourseById(int id) = 0;
  virtual int editCourse(Course course) = 0;
};
// class for CourseRepositoryImp
class CourseRepositoryImp : public CourseRepository
{
private:
    Data data;
    Course invalidCourse;
    int indexx = -1;
public:
  // Add Course
  int addCourse(Course course)
  {
    if (data.indexCourse == 25)
    {
      cout << "Full Course";
      return -1;
    }
    else
    {
      course.setId(data.idCourse++);
      data.courses[data.indexCourse++] = course;
    }
    return course.getId();
  }
  // Get Course By Id
  Course getCourseById(int id){
    for(int i = 0; i < data.indexCourse ; i++){
      if(data.courses[i].getId() == id){
      return data.courses[i];
    }
    }
    invalidCourse.setId(-1);
    return invalidCourse;
  }
  // Edit Course
  int editCourse(Course course) {
    for (int i = 0; i < data.indexCourse; i++) {
      if(data.courses[i].getId() == course.getId()) {
        indexx = i;
        break;
      }
    }
    if(indexx == -1) {
      return -1;
    } else {
      data.courses[indexx] = course;
      return indexx;
    }
  }
};

// *********** Teacher ***************
// Interface for TeacherRepository
class TeacherRepository
{
public:
  virtual int addTeacher(Teacher teacher) = 0;
  virtual Teacher getTeacherById(int id) = 0;
  virtual Teacher getTeacherByName(string name) = 0;
  virtual int showAll () = 0;
  virtual int editTeacher(Teacher teacher) = 0;
};
// class for TeacherRepositoryImp
class TeacherRepositoryImp : public TeacherRepository
{
private:
    Data data;
    Teacher invalidTeacher;
    int indexx = -1;
public:
  // Add A Teacher
  int addTeacher(Teacher teacher)
  {
    if (data.indexTeacher == 25)
    {
      cout << "Full Teacher";
      return -1;
    }
    else
    {
      teacher.setId(data.idTeacher++);
      data.teachers[data.indexTeacher++] = teacher;
    }
    return teacher.getId();
  }
  
  // Show Teachers By Id
  Teacher getTeacherById(int id){
    for(int i = 0 ; i<data.indexTeacher ;i++) {
      if(data.teachers[i].getId() == id){
        return data.teachers[i];
      }
    }
    invalidTeacher.setId(-1);
    return invalidTeacher;
  }

  // Show Teachers By Name
  Teacher getTeacherByName(string name) {
    for (int i = 0; i < data.indexTeacher; i++)
    {
      if(data.teachers[i].getName() == name){
        return data.teachers[i];
      }
    }
    invalidTeacher.setName("");
    return invalidTeacher;
  }
  // Show Teachers All
  int showAll () {
    if (data.teachers[0].getName() == "") {
      return -1;
    }
    else {
    Teacher arrayTeachers[25];
    for (int i = 0; i < data.indexTeacher; i++) {
      arrayTeachers[i] = data.teachers[i];
      cout << "Teacher " << i +1 << " Data :"<< endl;
      cout << "Teacher Name         : " << arrayTeachers[i].getName() << endl;
      cout << "Teacher Id           : " << arrayTeachers[i].getId() << endl;
      cout << "Teacher Age          : " << arrayTeachers[i].getAge() << endl;
      cout << "Teacher Salary       : " << arrayTeachers[i].getSalary() << endl;
      cout << "Teacher Phone Number : " << arrayTeachers[i].getphoneNumber() << endl;
      cout << "************************************\n";
  }
    }
    return 0;
  } 
  // Edit A Teacher
  int editTeacher(Teacher teacher) {
    for (int i = 0; i < data.indexTeacher; i++) {
      if(data.teachers[i].getId() == teacher.getId()) {
        indexx = i;
        break;
      }
    }
    if(indexx == -1) {
      return -1;
    } else {
      data.teachers[indexx] = teacher;
      return indexx;
    }
  }
};