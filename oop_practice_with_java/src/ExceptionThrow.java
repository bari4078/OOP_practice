public class ExceptionThrow {
    public static void f() throws IllegalAccessException {
        
        //throw new NullPointerException("f null exception");
        try{
            throw new IllegalAccessException("f illegal");
        } catch(IllegalAccessException e){
            System.out.println("Inside f catch "+e);
            throw e;
        }

    }

    public static void main(String[] args) {
        try{
            f();
        } catch(Exception e){
            System.out.println("Inside main catch " +e);
        }
    }
}
