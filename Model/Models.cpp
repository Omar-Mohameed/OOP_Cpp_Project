#include <iostream>
#include <string>
using namespace std;

class Course;class Student;class Teacher;


class ShareData
{
private:
  int id;
  string name;
public:
// Setter
  void setId(int id)
  {
    this->id = id;
  }
  void setName(string name)
  {
    this-> name = name;
  }
  // Getter
  int getId()
  {
    return id;
  }
  string getName()
  {
    return name;
  }
};


class BaseEntity : public ShareData
{
private:
  int age;
  string phoneNumber;
public:
  //Setter
  void setAge(int age)
  {
    this-> age = age;
  }
  void setphoneNumber(string phoneNumber)
  {
    this-> phoneNumber = phoneNumber;
  }
  // Getter
  int getAge()
  {
    return age;
  }
  string getphoneNumber()
  {
    return phoneNumber;
  }
};


class Teacher : public BaseEntity
{
  private:
    double salary;
    int studentIds[5];
  public:
  // Setter
    void setSalary(double salary)
    {
      this->salary = salary;
    }
    void setStudentIds(int studentIds[5])
    {
      for(int i = 0 ; i <5 ; i++)
      {
        this-> studentIds[i] = studentIds[i];
      }
    }
    // Getter
    double getSalary()
    {
      return salary;
    }
    int * getstudentIds()
    {
      return studentIds;
    }
};


class Course : public ShareData
{
  private:
    double hour;
    int studentIds[5];
  public:
    // Setter
    void setHour(double hour)
    {
      this-> hour = hour;
    }
    void setStudentIds(int studentIds[5])
    {
      for(int i = 0 ; i < 5 ; i++)
      {
        this-> studentIds[i] = studentIds[i];
      }
    }
    // Getter
    double getHour()
    {
      return hour;
    }
    int * getstudentIds()
    {
      return studentIds;
    }
};

class Student : public BaseEntity
{
private:
  double gpa;
  Teacher teachers[5];
  Course courses[5];
public:
  // Setter
  void setGpa(double gpa)
  {
    this-> gpa = gpa;
  }

  void setTeachers(Teacher teachers[5])
  {
    for(int i = 0; i <5; i++)
    {
      this->teachers[i] = teachers[i];
    }
  }
  
  void setCourses(Course courses[5])
  {
    for(int i = 0; i < 5; i++)
    {
      this->courses[i] = courses[i];
    }
  }
  // Getter
  double getGpa()
  {
    return gpa;
  }

  Teacher * getTeacher()
  {
    return teachers;
  }

  Course * getCourses()
  {
    return courses;
  }

};




