#include <iostream>
#include "Controller/Controller.cpp"
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

short Process = 0;
bool choice = 1;

bool anotherProcess()
{
  system("pause");
  cout << "\nDo You Want To Do Another Processing? y or n" << endl;
  char ch;
  cin >> ch;
  ch = toupper(ch);
  if (ch == 'Y')
  {
    return 1;
  }
  else if (ch == 'N')
  {
    cout << "\nThank You!\n"
         << endl;
    return 0;
  }
  else
  {
    cout << "Default Choice!\n";
    return 0;
  }
}

short displaySystem()
{
  system("cls");
  cout << "\t\t ********** Management System **********\n"
       << endl;
  cout << setw(60) << "Please Enter your Procces You Need To Do ! \n";
  cout << setw(30) << "1 - About Students"
       << "\t\t"
       << "2 - About Courses" << endl;
  cout << setw(30) << "3 - About Teachers"
       << "\t\t"
       << "4 - Exit" << endl;
  short Process;
  cin >> Process;
  return Process;
}
void showList(string value)
{
  system("cls");
  cout << "\t\t ********** " << value << " Management System **********\n"
       << endl;
  cout << setw(30) << "1 - Add " << value << "           "
       << "2 - Remove " << value << endl;
  cout << setw(31) << "3 - Edit " << value << "          "
       << "4 - Show " << value << " By Id"<< endl
       << setw(31) << "5 - Show " << value << " By Name";
       cout << "  6- Show All " << value << endl;
  cout << setw(30) << "7 - Exit" << endl;
}

/*
 *Student*
 */
void addStudent()
{
  system("cls");
  Student student;
  string name;
  int age;
  string phone;
  double gpa;
  cout << "Please Enter The Student Data : " << endl;
  cout << "Please Enter The Student Name Not Contains A Spaces: ";
  cin >> name;
  student.setName(name);
  cout << "Please Enter The Student Age : ";
  cin >> age;
  student.setAge(age);
  cout << "Please Enter The Student gpa : ";
  cin >> gpa;
  student.setGpa(gpa);
  cout << "Please Enter The Student phone : ";
  cin >> phone;
  student.setphoneNumber(phone);
  StudentController studentController;
  int id = studentController.addStudent(student);
  if(id != -1){
    cout << "Succes Added Student With Id [ " << id << " ]" << endl;
  }else{
    cout << "Failed To Add Student, Try Again" << endl;
  }
}

void removeStudent()
{
}

void editStudent()
{
  system("cls");
  Student student;
  string name;
  int age;
  string phone;
  double gpa;
  int id;
  cout << "Please Enter The Student Data : " << endl;
  cout << "Please Enter The Student Name Not Contains A Spaces: ";
  cin >> name;
  student.setName(name);
  cout << "Please Enter The Student Id: ";
  cin >> id;
  student.setId(id);
  cout << "Please Enter The Student Age : ";
  cin >> age;
  student.setAge(age);
  cout << "Please Enter The Student gpa : ";
  cin >> gpa;
  student.setGpa(gpa);
  cout << "Please Enter The Student phone : ";
  cin >> phone;
  student.setphoneNumber(phone);
  StudentServiceImp studentServiceImp;
  int ID = studentServiceImp.addStudent(student);
  if (ID == -1) {
    cout << "Please Enter A Valid Student Data" << endl;
  } else {
  StudentController studentController;
  studentController.editStudent(student);
  }
}

void showStudentById()
{
  system("cls");
  Student student ;
  int id;
  cout << "Please Enter The Student Id \n";
  cin >> id;
  StudentController studentController;
  student = studentController.getStudentById(id);
  if(student.getId() != -1){
  cout << "Student Name         : " << student.getName() << endl;
  cout << "Student Id           : " << student.getId() << endl;
  cout << "Student Age          : " << student.getAge() << endl;
  cout << "Student Gpa          : " << student.getGpa() << endl;
  cout << "Student Phone Number : " << student.getphoneNumber() << endl;
  }
  else {
    cout << "Invalid Student! \n";
  }
}

void showStudentByName() {
  system("cls");
  Student student ;
  string name;
  cout << "Please Enter The Student Name \n";
  cin >> name;
  StudentController studentController;
  student = studentController.getStudentByName(name);
  if(student.getName() != ""){
  cout << "Student Name         : " << student.getName() << endl;
  cout << "Student Id           : " << student.getId() << endl;
  cout << "Student Age          : " << student.getAge() << endl;
  cout << "Student Gpa          : " << student.getGpa() << endl;
  cout << "Student Phone Number : " << student.getphoneNumber() << endl;
  }
  else {
    cout << "Invalid Student! \n";
  }
}

void showAllStudents () {
  system("cls");
  StudentRepositoryImp studnetRepo;
  int result = studnetRepo.showAll();
  if(result == -1){
    cout << "No Students Found\n";
  }
}

void switchStudent()
{
  switch (Process)
  {
  case 1:
    cout << "Add Student" << endl;
    addStudent();
    break;
  case 2:
    cout << "Remove Student" << endl;
    removeStudent();
    break;
  case 3:
    cout << "Edit Student" << endl;
    editStudent();
    break;
  case 4:
    cout << "Show Student By Id" << endl;
    showStudentById();
    break;
  case 5:
    cout << "Show Student By Name" << endl;
    showStudentByName();
    break;
  case 6:
    cout << "Show Studenta All" << endl;
    showAllStudents();
    break;
  case 7:
    break;
  default:
    cout << "Invalid Choice\n";
  }
}


/*
 * Course *
 */

void addCourse()
{
  system("cls");
  Course course;

  string name;
  double hour;
  cout << "Please Enter The Course Data : " << endl;
  cout << "Please Enter The Course Name : ";
  cin >> name;
  course.setName(name);

  cout << "Please Enter The Course Hour : ";
  cin >> hour;
  course.setHour(hour);

  CourseController courseController;
  int id = courseController.addCourse(course);
  if(id != -1){
    cout << "Succes Added Course With Id [ " << id << " ]" << endl;
  }else {
    cout << "Failed To Add Course, Try Again" << endl;
  }
}

void removeCourse()
{
}

void editCourse()
{
  system("cls");
  Course course;

  string name;
  double hour;
  int id ;
  cout << "Please Enter The Course Data : " << endl;
  cout << "Please Enter The Course Name : ";
  cin >> name;
  course.setName(name);

  cout << "Please Enter The Course Id : ";
  cin >> id;
  course.setId(id);

  cout << "Please Enter The Course Hour : ";
  cin >> hour;
  course.setHour(hour);

  CourseServiceImp courseServiceImp;
  int ID = courseServiceImp.addCourse(course);
  if (ID == -1) {
    cout << "Please Enter A Valid Course Data" << endl;
  } else {
  CourseController courseController;
  courseController.editCourse(course);
  }
}

void showCourseById()
{
  system("cls");
  Course course;
  int id;
  cout << "Please Enter The Course Id \n";
  cin >> id;
  CourseController courseController;
  course = courseController.getCourseById(id);
  if(course.getId() != -1){
  cout << "Course Data With Id [ " << id << " ] Is : " << endl;
  cout << "Course Name         : " << course.getName() << endl;
  cout << "Course Id           : " << course.getId() << endl;
  cout << "Course Hour         : " << course.getHour() << endl;
  }
  else {
    cout << "Invalid Course! \n";
  }
}

void switchCourse()
{
  switch (Process)
  {
  case 1:
    cout << "Add Course" << endl;
    addCourse();
    break;
  case 2:
    cout << "Remove Course" << endl;
    removeCourse();
    break;
  case 3:
    cout << "Edit Course" << endl;
    editCourse();
    break;
  case 4:
    cout << "Show Course" << endl;
    showCourseById();
    break;
  case 5:
    break;
  default:
    cout << "Invalid Choice\n";
  }
}

/*
 * Teacher *
 */
void addTeacher()
{
  system("cls");
  Teacher teacher;
  string name;
  int age;
  string phoneNumber;
  double salary;
  cout << "Please Enter The Teacher Data : " << endl;
  cout << "Please Enter The Teacher Name : ";
  cin >> name;
  teacher.setName(name);

  cout << "Please Enter The Teacher Age : ";
  cin >> age;
  teacher.setAge(age);

  cout << "Please Enter The Teacher phoneNumber : ";
  cin >> phoneNumber;
  teacher.setphoneNumber(phoneNumber);

  cout << "Please Enter The Teacher Salary : ";
  cin >> salary;
  teacher.setSalary(salary);

  TeacherController teacherController;
  int id = teacherController.addTeacher(teacher);
  if(id != -1){
    cout << "Succes Added Teacher With Id [ " << id << " ]" << endl;
  }else{
    cout << "Failed To Add Teacher, Try Again" << endl;
  }
}

void removeTeacher()
{
}

void editTeacher()
{
  system("cls");
  Teacher teacher;
  string name;
  int age;
  int id;
  string phoneNumber;
  double salary;
  cout << "Please Enter The Teacher Data : " << endl;
  cout << "Please Enter The Teacher Name : ";
  cin >> name;
  teacher.setName(name);

  cout << "Please Enter The Teacher Id : ";
  cin >> id;
  teacher.setId(id);

  cout << "Please Enter The Teacher Age : ";
  cin >> age;
  teacher.setAge(age);

  cout << "Please Enter The Teacher phoneNumber : ";
  cin >> phoneNumber;
  teacher.setphoneNumber(phoneNumber);

  cout << "Please Enter The Teacher Salary : ";
  cin >> salary;
  teacher.setSalary(salary);

  TeacherServiceImp teacherServiceImp;
  int ID = teacherServiceImp.addTeacher(teacher);
  if (ID == -1) {
    cout << "Please Enter A Valid Teacher Data" << endl;
  } else {
  TeacherController teacherController;
  teacherController.editTeacher(teacher);
  }
}

void showTeacherById()
{
  system("cls");
  Teacher teacher;
  int id;
  cout << "Please Enter The Teacher Id \n";
  cin >> id;
  TeacherController teacherController;
  teacher = teacherController.getTeacherById(id);
  if(teacher.getId() != -1){
  cout << "Teacher Data With Id [ " << id << " ] Is : " << endl;
  cout << "Teacher Name         : " << teacher.getName() << endl;
  cout << "Teacher Id           : " << teacher.getId() << endl;
  cout << "Teacher Age          : " << teacher.getAge() << endl;
  cout << "Teacher Salary       : " << teacher.getSalary() << endl;
  cout << "Teacher Phone Number : " << teacher.getphoneNumber() << endl;
  }
  else {
    cout << "Invalid Teacher! \n";
  }
}

void showTeacherByName() {
  system("cls");
  Teacher teacher ;
  string name;
  cout << "Please Enter The Teacher Name \n";
  cin >> name;
  TeacherController teacherController;
  teacher = teacherController.getTeacherByName(name);
  if(teacher.getName() != ""){
  cout << "Teacher Name         : " << teacher.getName() << endl;
  cout << "Teacher Id           : " << teacher.getId() << endl;
  cout << "Teacher Age          : " << teacher.getAge() << endl;
  cout << "Teacher Salary       : " << teacher.getSalary() << endl;
  cout << "Teacher Phone Number : " << teacher.getphoneNumber() << endl;
  }
  else {
    cout << "Invalid Teacher! \n";
  }
}

void showAllTeachers () {
  system("cls");
  TeacherRepositoryImp teacherRepo;
  int result = teacherRepo.showAll();
  if(result == -1){
    cout << "No Teachers Found\n";
  }
}


void switchTeacher()
{
  switch (Process)
  {
  case 1:
    cout << "Add Teacher" << endl;
    addTeacher();
    break;
  case 2:
    cout << "Remove Teacher" << endl;
    removeTeacher();
    break;
  case 3:
    cout << "Edit Teacher" << endl;
    editTeacher();
    break;
  case 4:
    cout << "Show Teacher By Id" << endl;
    showTeacherById();
    break;
  case 5:
    cout << "Show Teacher By Name" << endl;
    showTeacherByName();
    break;
  case 6:
    cout << "Show Teachera All" << endl;
    showAllTeachers();
    break;
  case 7:
    break;
  default:
    cout << "Invalid Choice\n";
  }
}
int main()
{

  short flag = 0;

  while (choice)
  {
    Process = displaySystem();
    switch (Process)
    {
    case 1:
      showList("Student");
      cin >> Process;
      switchStudent();
      break;
    case 2:
      showList("Course");
      cin >> Process;
      switchCourse();
      break;
    case 3:
      showList("Teacher");
      cin >> Process;
      switchTeacher();
      break;
    case 4:
      cout << "\nThank You\n\n";
      flag = 1;
      break;
    default:
      cout << "Invalid Choice\n";
    }
    if (flag == 1)
    {
      break;
    }
    choice = anotherProcess();
  }
}