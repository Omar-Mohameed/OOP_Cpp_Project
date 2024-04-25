// Service => Receive the data and do the validation on it
#include "../Repo/Repository.cpp"


// *********** Student ***************
// Interface for StudentService
class StudentService
{
public:
  virtual int addStudent(Student student) = 0;
};
class StudentServiceImp
{
private:
  StudentRepositoryImp studentRepository;

public:
  // Add A Student
  int addStudent(Student student)
  {
    // Validation and added the Students
    if(student.getName().size() <= 2 || 
    student.getName().size() >= 10){
      cout << "Invalid Student Name | ";
    }
    else if(student.getAge() >= 30 ||
            student.getAge() < 18){
      cout << "Invalid Student Age | ";
    }
    else if(student.getGpa() < 0 ||
    student.getGpa() > 5){
      cout << "Invalid Student GPA | ";
    }
    else if(student.getphoneNumber()[0] != '0' ||
          (
            student.getphoneNumber()[1] + student.getphoneNumber()[2] != ('1' + '0')&&
            student.getphoneNumber()[1] + student.getphoneNumber()[2] != ('1' + '1')&&
            student.getphoneNumber()[1] + student.getphoneNumber()[2] != ('1' + '2')&&
            student.getphoneNumber()[1] + student.getphoneNumber()[2] != ('1' + '5')
          ) || (student.getphoneNumber().size() != 11) 
            ){// 012    013  
              cout << "Invalid Student Phone Number | ";
            }else{
                return studentRepository.addStudent(student);
            }
            return -1;
    }
  // Show Student By Id 
  Student getStudentById(int id) {
    return studentRepository.getStudentById(id);
  }
  // Show Student By Name 
  Student getStudentByName(string name) {
    return studentRepository.getStudentByName(name);
  }
  // Edit Student
  void editStudent(Student student) {
    int index = studentRepository.editStudent(student);
    if(index == -1) {
      cout << "Student With Id [" <<student.getId()<<" ] Not Founds" << endl;
    } else {
      cout << "Sucess Edit Student With Id [" <<student.getId()<<" ]\n";
    }
  }
};

// *********** Course ***************
// Interface for CourseService
class CourseService
{
public:
  virtual int addCourse(Course course) = 0;
};
class CourseServiceImp
{
private:
  CourseRepositoryImp courseRepository;

public:
  
  int addCourse(Course course)
  {
    if(course.getName().size() < 2 || course.getName().size() >= 50){
      cout << "Invalid Course Name | ";
    }else if (course.getHour() > 3) {
      cout << "Invalid Course Hour | ";
      }else {
      return courseRepository.addCourse(course);
    }
    return -1;
  }
  
  Course getCourseById(int id) {
    return courseRepository.getCourseById(id);
  }

  // Edit Course
  void editCourse(Course course) {
    int index = courseRepository.editCourse(course);
    if(index == -1) {
      cout << "Course With Id [" <<course.getId()<<" ] Not Founds" << endl;
    } else {
      cout << "Sucess Edit Course With Id [" <<course.getId()<<" ]\n";
    }
  }
};
// *********** Teacher ***************
// Interface for TeacherService
class TeacherService
{
public:
  virtual int addTeacher(Teacher teacher) = 0;
};
class TeacherServiceImp
{
private:
  TeacherRepositoryImp teacherRepository;

public:
  int addTeacher(Teacher teacher)
  {
    if(teacher.getName().size() <= 2 || teacher.getName().size() >= 10){
      cout << "Invalid Teacher Name | ";
    }else if(teacher.getAge() >= 60 ||
            teacher.getAge() < 25){
      cout << "Invalid Teacher Age | ";
    }else if(teacher.getphoneNumber()[0] != '0' ||
          (
            teacher.getphoneNumber()[1] + teacher.getphoneNumber()[2] != ('1' + '0')&&
            teacher.getphoneNumber()[1] + teacher.getphoneNumber()[2] != ('1' + '1')&&
            teacher.getphoneNumber()[1] + teacher.getphoneNumber()[2] != ('1' + '2')&&
            teacher.getphoneNumber()[1] + teacher.getphoneNumber()[2] != ('1' + '5')
            ) || (teacher.getphoneNumber().size() != 11) 
          ){// 012    013  
              cout << "Invalid Teacher Phone Number | ";
            }else if (teacher.getSalary() <= 0 || teacher.getSalary() > 100000){
              cout << "Invalid Teacher Salary | ";
            }else{
              return teacherRepository.addTeacher(teacher);
            }
            return -1;
    }
  // Show Teacher By Id 
  Teacher getTeacherById(int id) {
    return teacherRepository.getTeacherById(id);
  }
  // Show Teacher By Name 
  Teacher getTeacherByName(string name) {
    return teacherRepository.getTeacherByName(name);
  }
  // Edit Teacher
  void editTeacher(Teacher teacher) {
    int index = teacherRepository.editTeacher(teacher);
    if(index == -1) {
      cout << "Teacher With Id [" <<teacher.getId()<<" ] Not Founds" << endl;
    } else {
      cout << "Sucess Edit Teacher With Id [" <<teacher.getId()<<" ]\n";
    }
  }
};