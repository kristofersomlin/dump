class Student
{
public:
  // add a completed course to the record
  float addCoarse(int hours, float grade)
  {
    // calculate the sum of all courses times
    // the avarage grade
    float weightedGPA;
    weightedGPA = semesterHours * gpa;

    // now add in the new course
    semesterHours += hours;
    weightedGPA += grade * hours;
    gpa = wieghtedGPA / semesterHours;

    // return the new gpa
    return gpa;
  }
  int semesterHours;
  float gpa;
};
