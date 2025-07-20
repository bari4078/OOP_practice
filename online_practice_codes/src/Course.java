import java.util.ArrayList;

public class Course {
    private static ArrayList<Course> courses=new ArrayList<>();

    private String name;
    private double credit;

    public Course(String n,double cred){
        this.name = n;
        this.credit=cred;
    }

    public static void addCourse(String name,double credit){
        courses.add(new Course(name,credit));
    }

    public static ArrayList<Course> getCourses(){
        return courses;
    }

    public String getName(){
        return this.name;
    }

    public double getCredit(){
        return this.credit;
    }

}
