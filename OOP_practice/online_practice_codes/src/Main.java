import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Handle missing arguments
        if (args.length < 2) {
            System.out.println("Usage: java Main <numStudents> <numCourses>");
            return;
        }

        int numStudents = Integer.parseInt(args[0]);
        int numCourses = Integer.parseInt(args[1]);

        Scanner sc = new Scanner(System.in);

        System.out.println("Parsing command line arguments...");
        System.out.println("Number of students: " + numStudents);
        System.out.println("Number of courses: " + numCourses);
        System.out.println("---");

        inputCourses(numCourses, sc);
        ArrayList<Student> students = inputStudents(numStudents, sc);

        System.out.println("---");

        processCommands(students, sc);

        sc.close();
    }

    private static void inputCourses(int numCourses, Scanner sc) {
        for (int i = 0; i < numCourses; i++) {
            System.out.println("\nCourse " + (i + 1));
            System.out.print("Enter course name: ");
            String name = sc.nextLine();
            System.out.print("Enter course credit: ");
            double credit = Double.parseDouble(sc.nextLine());
            Course.addCourse(name, credit);
        }
    }

    private static ArrayList<Student> inputStudents(int numStudents, Scanner sc) {
        ArrayList<Student> students = new ArrayList<>();

        for (int i = 0; i < numStudents; i++) {
            System.out.print("\nEnter name of student " + (i + 1) + ": ");
            String name = sc.nextLine();
            Student s = new Student(name);

            ArrayList<Course> courses = Course.getCourses();
            for (int j = 0; j < courses.size(); j++) {
                String courseName = courses.get(j).getName();
                double mark;
                while (true) {
                    System.out.print("Enter marks for " + courseName + ": ");
                    mark = Double.parseDouble(sc.nextLine());
                    if (mark >= 0 && mark <= 100) break;
                    System.out.println("Invalid mark. Try again.");
                }
                s.setMark(j, mark);
            }

            s.calculateGPA();
            students.add(s);
        }

        return students;
    }

    private static void processCommands(ArrayList<Student> students, Scanner sc) {
        while (true) {
            System.out.print("\nEnter command: ");
            String commandLine = sc.nextLine();
            String[] parts = commandLine.split(" ", 2);

            String command = parts[0];

            if (command.equals("exit")) {
                System.out.println("\nTerminating...");
                break;
            }

            if (parts.length < 2) {
                System.out.println("Invalid command.");
                continue;
            }

            String arg = parts[1];

            switch (command) {
                case "display":
                    displayStudent(students, arg);
                    break;
                case "delete":
                    deleteStudent(students, arg);
                    break;
                default:
                    System.out.println("Invalid command.");
            }

            System.out.println("---");
        }
    }

    private static void displayStudent(ArrayList<Student> students, String name) {
        if (name.equals("all")) {
            for (Student s : students) {
                s.display();
            }
            return;
        }

        for (Student s : students) {
            if (s.getName().equals(name)) {
                s.display();
                return;
            }
        }

        System.out.println("Student " + name + " does not exist.");
    }

    private static void deleteStudent(ArrayList<Student> students, String name) {
        boolean removed = students.removeIf(s -> s.getName().equals(name));
        if (removed) {
            System.out.println("Success, student " + name + " deleted.");
        } else {
            System.out.println("Student " + name + " does not exist.");
        }
    }
}
