import java.util.*;
public class Main {
    public static void main(String[] args) {
        int nBooks = Integer.parseInt(args[0]);

        System.out.println("Number of books from command line: "+nBooks);
        Library library = new Library("Buet Central Library", nBooks);
        
        Scanner myScanner = new Scanner(System.in);
        for(int i=0;i<nBooks;i++){
            System.out.println("----Book No. "+(i+1)+"-----");

            System.out.print("Enter Title: ");
            String title = myScanner.nextLine();

            System.out.print("Enter author: ");
            String aut = myScanner.nextLine();

            System.out.print("Enter ISBN:");
            long isn = myScanner.nextLong();
            myScanner.nextLine();

            System.out.print("Total copies: ");
            int total = myScanner.nextInt();
            myScanner.nextLine();

            System.out.println("Borrowed copies: ");
            int borr= myScanner.nextInt();
            myScanner.nextLine();

            library.addBook(title, aut, isn, total, borr);
        }

        library.display();
    }
}