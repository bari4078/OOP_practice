#include <bits/stdc++.h>
using namespace std;

class Course{
private:
    string name;
    float creditHour;
public:
    Course(){
        name="";
        creditHour=0;
    }
    Course(string n,float credit){
        name=n;
        creditHour=credit;
    }
    Course(const Course &c){
        name=c.name;
        creditHour=c.creditHour;
    }

    void setName(string n){
        name =n;
    }
    string getName(){
        return name;
    }

    void setCreditHour(float t){
        creditHour=t;
    }
    float getCreditHour(){
        return creditHour;
    }

    void display(){
        cout<<"Course Name: "<<name<<", Credit Hour: "<<creditHour;
    }
};

class Student{
private:
    string name;
    int id;
    Course *courses;
    int totalCourses;
    int maxCourses;
    float *gradePoints;
public:
    Student(){
        id=0;
        name="";
        totalCourses=0;
        maxCourses=1;
        courses=new Course[maxCourses];
        gradePoints=new float[maxCourses];
    }
    Student(string nam,int i,int maxC){
        name=nam;
        id=i;
        maxCourses=maxC;
        courses=new Course[maxC];
        gradePoints=new float[maxC];
        totalCourses=0;
    }

    Student(const Student &s){
        name = s.name;
        id=s.id;
        maxCourses=s.maxCourses;
        totalCourses=s.totalCourses;
        courses=new Course[maxCourses];
        for(int i=0;i<totalCourses;i++){
            courses[i]=s.courses[i];
        }
        gradePoints=new float[maxCourses];
        for(int i=0;i<totalCourses;i++){
            gradePoints[i]=s.gradePoints[i];
        }
    }

    ~Student(){
        delete[] gradePoints;
        delete[] courses;
    }

    void setName(string n){
        name =n;
    }
    string getName(){
        return name;
    }

    void setId(int i){
        id=i;
    }
    
    void setInfo(string nam,int i){
        name = nam;
        id=i;
    }

    void addCourse(Course c){
        if(totalCourses == maxCourses){
            cout<<"Cannot add more courses to "<<name<<endl;
            return;
        }
        courses[totalCourses]=c;
        gradePoints[totalCourses]=0;
        totalCourses++;
    }

    void addCourse(Course c,float gpa){
        if(totalCourses == maxCourses){
            cout<<"Cannot add more courses to "<<name<<endl;
            return;
        }
        courses[totalCourses]=c;
        gradePoints[totalCourses]=gpa;
        totalCourses++;
    }

    void setGradePoint(Course c,float gpa){
        int idx=-1;
        for(int i=0;i<totalCourses;i++){
            if(courses[i].getName() == c.getName()){
                idx=i;
                break;
            }
        }
        if(idx<0){
            cout<<"Error: Student not enrolled in this course"<<endl;
            return;
        }
        if(idx >= 0) gradePoints[idx]=gpa;
    }

    void setGradePoint(float *inputGradePoints,int n){
        if (n > totalCourses){
            cout<<"Error: numbers of gradePoints to set exceed the total no of courses"<<endl;
            return;
          }          
        for(int i=0;i<n;i++){
            gradePoints[i]= inputGradePoints[i];
        }
    }

    float getCGPA(){
        float gpa=0;
        float total_cred=0;
        for(int i=0;i<totalCourses;i++){
            gpa+=gradePoints[i]*courses[i].getCreditHour();
            total_cred += courses[i].getCreditHour();
        }
        if (total_cred == 0) return 0;
        gpa = gpa/total_cred;
        return gpa;
    }

    float getTotalCreditHours(){
        float out=0;
        for(int i=0;i<totalCourses;i++){
            if(gradePoints[i] >= 2){
                out += courses[i].getCreditHour();
            }
        }
        return out;
    }

    float getGradePoint(Course c){
        int idx=-1;
        for(int i=0;i<totalCourses;i++){
            if(courses[i].getName() == c.getName()){
                idx=i;
                break;
            }
        }
        if(idx<0) return -1;
        return gradePoints[idx];
    }

    int getTotalCourses(){
        return totalCourses;
    }

    Course getMostFavoriteCourse(){
        int max_idx=-1;
        float max=0;
        for(int i=0;i<totalCourses;i++){
            if(max<gradePoints[i]){
                max_idx=i;
                max=gradePoints[i];
            }
        }
        if(max_idx < 0){
            cout<<"Invalid student array"<<endl;
            exit(0);
        }
        return courses[max_idx];
    }

    Course getLeastFavoriteCourse(){
        int min_idx=-1;
        float min=200;
        for(int i=0;i<totalCourses;i++){
            if(min>gradePoints[i]){
                min_idx=i;
                min=gradePoints[i];
            }
        }
        if(min_idx <0){
            cout<<"Invalid student array"<<endl;
            exit(0);
        }
        return courses[min_idx];
    }

    Course *getFailedCourses(int &count){
        count = 0;
        for(int i = 0; i < totalCourses; i++){
            if(gradePoints[i] < 2) count++;
        }
        Course *out=new Course[count];
        int fail_i=0;
        for(int i=0;i<totalCourses;i++){
            if(gradePoints[i] < 2){
                out[fail_i++] = courses[i];
            }
        }
        return out;
    }

    void display(){
        cout<<"=================================="<<endl;
        cout<<"Student Name: "<<name<<", ID: "<<id<<endl;
        for(int i=0;i<totalCourses;i++){
            courses[i].display();
            cout<<", gradePoint: "<<gradePoints[i]<<endl;
        }
        cout<<"CGPA: "<<getCGPA()<<endl;
        cout<<"Total Credit Hours Earned: "<<getTotalCreditHours()<<endl;
        cout<<"Most Favorite Course: "<<getMostFavoriteCourse().getName()<<endl;
        cout<<"Least Favorite Course: "<<getLeastFavoriteCourse().getName()<<endl;
        cout<<"=================================="<<endl;
    }
};

Student* students[100];
int totalStudents=0;

Student getTopper(){
    float max_gpa=0;
    int max_idx=-1;
    for(int i=0;i<totalStudents;i++){
        float st_gpa=students[i]->getCGPA();
        if(st_gpa > max_gpa){
            max_gpa=st_gpa;
            max_idx=i;
        }
    }
    if(max_idx < 0){
        cout<<"No students"<<endl;
        exit(1);
    }
    return *students[max_idx];
}

Student getTopper(Course c){
    int top_idx=-1;
    float max=-1;
    float temp=-1;
    for(int i=0;i<totalStudents;i++){
        temp=students[i]->getGradePoint(c);
        if(temp>max){
            max=temp;
            top_idx=i;
        }
    }
    if(top_idx<0){
        cout<<"Invalid course/student"<<endl;
        exit(1);
    }
    return *students[top_idx];
}

int main() {
    // generate courses
    const int COURSE_COUNT = 6;
    Course courses[COURSE_COUNT] = {
    Course("CSE107", 3),
    Course("CSE105", 3),
    Course("CSE108", 1.5),
    Course("CSE106", 1.5),
    Course("EEE164", 0.75),
    Course("ME174", 0.75),
    };
    float gradePoints[COURSE_COUNT] = {4.0, 4.0, 3.5, 3.5, 4.0, 3.25};
    // generate students
    Student s1 = Student("Sheldon", 1, 5);
    students[totalStudents++] = &s1;
    // add courses to s1
    s1.addCourse(courses[0]);
    s1.addCourse(courses[1]);
    s1.addCourse(courses[2]);
    s1.addCourse(courses[3]);
    s1.addCourse(courses[4]);
    s1.addCourse(courses[5]);
    s1.setGradePoint(gradePoints, s1.getTotalCourses());
    s1.display();
    Student s2 = Student("Penny", 2, 5);
    students[totalStudents++] = &s2;
    s2.addCourse(courses[0]);
    s2.addCourse(courses[2]);
    s2.addCourse(courses[5]);
    s2.setGradePoint(gradePoints, s2.getTotalCourses());
    s2.setGradePoint(courses[0], 3.25);
    s2.display();
    Student s3 = s2;
    students[totalStudents++] = &s3;
    s3.setName("Leonard");
    s3.setId(3);
    s3.setGradePoint(gradePoints, s3.getTotalCourses());
    s3.addCourse(courses[1], 3.75);
    s3.display();
    Student s4 = s3;
    students[totalStudents++] = &s4;
    s4.setInfo("Howard", 4);
    s4.setGradePoint(gradePoints, s4.getTotalCourses());
    s4.addCourse(courses[3], 3.75);
    s4.display();
    Student s5 = s4;
    students[totalStudents++] = &s5;
    s5.setInfo("Raj", 5);
    s5.setGradePoint(gradePoints, s5.getTotalCourses());
    s5.setGradePoint(courses[0], 1.5);
    s5.setGradePoint(courses[2], 2.0);
    s5.setGradePoint(courses[5], 1.75);
    s5.setGradePoint(courses[3], 3.75);
    s5.display();
    int failedCount;
    Course* failedCourses = s5.getFailedCourses(failedCount);
    cout << "Failed Courses for " << s5.getName() << ":" << endl;
    for (int i = 0; i < failedCount; ++i) {
    failedCourses[i].display();
    cout << endl;
    }
    delete[] failedCourses;
    cout << "==================================" << endl;
    Student topper = getTopper();
    cout << "Topper: " << topper.getName() << endl;
    cout << "Topper CGPA: " << topper.getCGPA() << endl;
    cout << "==================================" << endl;
    for (int i = 0; i < COURSE_COUNT; ++i) {
    Course c = courses[i];
    Student topperInCourse = getTopper(c);
    cout << "Topper in " << c.getName() << ": " <<
    topperInCourse.getName() << endl;
    cout << "Topper in " << c.getName() << " gradePoint: " <<
    topperInCourse.getGradePoint(c) << endl;
    cout << "==================================" << endl;
    }
    return 0;
}