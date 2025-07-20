import java.util.ArrayList;

public class Book {
    private String title;
    private String author;
    private long isbn;
    private int totalCopies;
    private int borrowedCopies;

    public Book(String nam, String authr, long isn, int totalcopy,int borrowed){
        this.title=nam;
        this.author=authr;
        this.isbn=isn;
        this.totalCopies=totalcopy;
        this.borrowedCopies=borrowed;
    }

    // Getter and Setter for title
    public String getTitle() {
        return title;
    }
    public void setTitle(String title) {
        this.title = title;
    }

    // Getter and Setter for author
    public String getAuthor() {
        return author;
    }
    public void setAuthor(String author) {
        this.author = author;
    }

    // Getter and Setter for isbn
    public long getIsbn() {
        return isbn;
    }
    public void setIsbn(long isbn) {
        this.isbn = isbn;
    }

    // Getter and Setter for totalCopies
    public int getTotalCopies() {
        return totalCopies;
    }
    public void setTotalCopies(int totalCopies) {
        this.totalCopies = totalCopies;
    }

    // Getter and Setter for borrowedCopies
    public int getBorrowedCopies() {
        return borrowedCopies;
    }
    public void setBorrowedCopies(int borrowedCopies) {
        this.borrowedCopies = borrowedCopies;
    }

    public int availableCopies(){
        if(totalCopies > borrowedCopies) return totalCopies-borrowedCopies;
        return 0;
    }

}
