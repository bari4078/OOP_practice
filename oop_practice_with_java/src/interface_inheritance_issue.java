interface Alpha{
    default void reset(){
        System.out.println("Alphas reset");
    }
}

interface Beta extends Alpha{
    default void reset(){
        System.out.println("Beta's reset");
        Alpha.super.reset();
    }
}

class TestClass implements Beta{
    
}


public class interface_inheritance_issue {
    public static void main(String[] args) {
        TestClass obj = new TestClass();

        obj.reset();
    }
}
