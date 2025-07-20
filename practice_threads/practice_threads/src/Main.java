//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

class myTask implements Runnable {
    public void run() {
        System.out.println("Thread started " +Thread.currentThread().getName());
        try{
            Thread.sleep(2000);

        }
        catch(InterruptedException e){
            System.out.println("Thread interrupted");
        }
        System.out.println("Thread finished " +Thread.currentThread().getName());
    }
}


public class Main {
    public static void main(String[] args) {
        Thread t1 = new Thread(new myTask());
        System.out.println("Before start: "+t1.getState());

        t1.start();
        System.out.println("After start: "+t1.getState());

        try{
            Thread.sleep(1000);
            System.out.println("During Run: "+t1.getState());
            t1.join();
        }catch(InterruptedException e){}

        System.out.println("After Run: "+t1.getState());
    }
}
