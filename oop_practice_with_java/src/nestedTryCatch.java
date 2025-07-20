import java.util.Random;

public class nestedTryCatch {
    public static void main(String args[]) {
        int a = 10, b, c;
        Random r = new Random();
        String s = null;
        try{
            System.out.println(s.length());
        } catch(NullPointerException e){
            System.out.println(e);
        } catch(Exception e){
            System.out.println(e);
        }
        finally{
            System.out.println("Always prints");
        }

        /*try {
            for (int i = 1; i <= 32000; i++)
                try {
                    b = r.nextInt();
                    c = r.nextInt();
                    a = 12345 / (b / c);
                } catch (Exception e) {
                    System.out.println(e);
                    a = 0;
                } finally {
                    System.out.println(i + ": " + a);
                }
        } catch (ArithmeticException e) {
            System.out.println(e);
        }*/
    }
}
