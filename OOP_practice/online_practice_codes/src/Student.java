import java.util.ArrayList;

public class Student {
    private String name;
    private double[] marks;
    private double[] grades;
    private double gpa;

    public Student(String nam){
        this.name=nam;
        int n = Course.getCourses().size();
        marks = new double[n];
        grades= new double[n];
    }

    public void setMark(int ind, double mark){
        marks[ind] = mark;
        grades[ind] = getGradeFromMark(mark);
    }

    private double getGradeFromMark(double mark){
        if(mark >= 80) return 4.0;
        else if(mark >= 75) return 3.75;
        else if(mark >= 70) return 3.5;
        return 0;
    }

    public void calculateGPA(){
        int n= Course.getCourses().size();
        this.gpa=0;
        double totalCred=0;
        for(int i=0;i<n;i++){
            this.gpa += grades[i]*Course.getCourses().get(i).getCredit();
            totalCred += Course.getCourses().get(i).getCredit();
        }
        if(totalCred != 0) this.gpa /= totalCred;
    }

    public void display(){
        int totalCourse=Course.getCourses().size();
        System.out.println("Name of the student: "+this.name);
        System.out.println("Total Courses: "+totalCourse);

        for(int i=0;i<totalCourse;i++){
            System.out.println("Course Name: "+Course.getCourses().get(i).getName()+" Grade: "+grades[i]);
        }

        System.out.println("CGPA: "+gpa);
    }

    public String getName(){
        return this.name;
    }
}
