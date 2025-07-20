public class Library {
    String name;
    Book[] books;
    int no_of_books;
    int curr=0;
    public Library(String nam, int n){
        name=nam;
        no_of_books=n;
        books = new Book[no_of_books];
    }

    public void addBook(String nam,String aut, long isn, int totalcopy, int borrowed){
        boolean found = false;
        for(int i=0;i<curr;i++){
            if(books[i].getIsbn() == isn){
                found = true;
            }
        }
        if(found){
            System.out.println("Invalid ISBN, Could not add this book");
            return;
        }
        books[curr] = new Book(nam, aut, isn, totalcopy, borrowed);
        curr++;
    }
    void display(){
        System.out.println("Name of library: "+name);
        System.out.println("------All the books------");
        for(int i=0;i<curr;i++){
            System.out.println("Book Title: "+books[i].getTitle());
            System.out.println(" Author: "+books[i].getAuthor());
            System.out.println(" ISBN: "+books[i].getIsbn());
            System.out.println(" Total copies: "+books[i].getTotalCopies());
            System.out.println(" Borrowed: "+books[i].getBorrowedCopies());
        }
    }
}
