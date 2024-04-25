// Controller => Controller The Service (add user , remove , ...)=> in main function
#include "../Service/Service.cpp"
#include <iostream>
using namespace std;

// *********** Student ***************
class StudentController
{
private:
  StudentServiceImp studentService;

public:
  int addStudent(Student student)
  {
    return studentService.addStudent(student);
  }
  // Show Student By Id 
  Student getStudentById(int id) {
    return studentService.getStudentById(id);
  }
  // Show Student By Name 
  Student getStudentByName(string name) {
    return studentService.getStudentByName(name);
  }
  // Edit Student
  void editStudent(Student student) {
    studentService.editStudent(student);
  }
};
// *********** Course ***************
class CourseController
{
private:
  CourseServiceImp courseService;

public:
  int addCourse(Course course)
  {
    return courseService.addCourse(course);
  }
  Course getCourseById(int id) {
    return courseService.getCourseById(id);
  }
  // Edit Course
  void editCourse(Course course) {
    courseService.editCourse(course);
  }
};
// *********** Teacher ***************
class TeacherController
{
private:
  TeacherServiceImp teacherService;

public:
  int addTeacher(Teacher teacher)
  {
    return teacherService.addTeacher(teacher);
  }
  Teacher getTeacherById(int id) {
    return teacherService.getTeacherById(id);
  }
  Teacher getTeacherByName(string name) {
    return teacherService.getTeacherByName(name);
  }
  // Edit Teacher
  void editTeacher(Teacher teacher) {
    teacherService.editTeacher(teacher);
  }
};