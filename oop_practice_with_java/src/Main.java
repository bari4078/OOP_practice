class My_class{
    private int a=0;
    My_class(){
        System.out.println("Inside constructor with no arguments");
    }
    My_class(int newA){
        System.out.println("Inside constructor with arguments");
        a=newA;
    }
    public void show(){
        System.out.println("value of a: "+a);
    }
}
class box{
    private double length,width,height;
    public box(double l,double w,double h){
        length=l;
        width=w;
        height=h;
    }
    public box(box ob){
        length=ob.length;
        width=ob.width;
        height=ob.height;
    }
    public double volume(){
        return length*width*height;
    }
}

class Message{
    private String msg;
    public Message(String m){
        msg=m;
    }
    public void updateMessage(String m){
        msg=m;
    }
    String getMessage(){
        return msg;
    }
}
public class Main{
    public static void main(String[] args){
        Message ob1= new Message("hello");
        System.out.println("without change: "+ob1.getMessage());
        ob1.updateMessage("goodbye");
        System.out.println("after change: "+ob1.getMessage());
    }
}