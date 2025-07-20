interface I1{
    default public void f1(){
        System.out.println("I1s f1");
    }
}

interface I2 {
    default public void f2(){
        System.out.println("I2s f2");
    }
}

interface I3 extends I1,I2 {
    @Override
    default public void f1(){
        System.out.println("I3s f1");
    }

    @Override
    default public void f2(){
        System.out.println("I3s f2");
    }
    
    default public void f3(){
        System.out.println("I3s f3");
    }

    static int getDefaultNum(){
        return 0;
    }
}

class A implements I1,I2,I3{
    
    static int getDefaultNum(){
        return 5;
    }
};

public class interface_inheritance {
    public static void main(String[] args) {
        A obj = new A();
        I1 ref1 = obj;
        I2 ref2 = obj;
        I3 ref3 = obj;

        obj.f1();
        obj.f2();
        obj.f3();
        System.out.println(A.getDefaultNum());

        ref1.f1();
        
        ref2.f2();

        ref3.f1();
        ref3.f2();
        ref3.f3();
        System.out.println(I3.getDefaultNum());
    }
     
}