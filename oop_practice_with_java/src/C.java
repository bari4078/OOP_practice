
public class C{
    public static void main(String[] args) 
    {
        Thread thread1 = new Thread();
         
        thread1.start();
         
        Thread.currentThread().setPriority(8);
         
        Thread thread2 = new Thread();
         
        thread2.start();
         
        System.out.println(thread1.getPriority());
         
        System.out.println(thread2.getPriority());
    }
}

