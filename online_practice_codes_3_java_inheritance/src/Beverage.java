public class Beverage extends FoodItem{
    private String size;
    private boolean hasIce = false;

    public Beverage(String nam, double price, int quant, String siz){
        super(nam,price,quant);
        this.size = siz;
    }

    public void displayInfo(){
        super.displayInfo();
        System.out.print("Size: "+size + " Ice: "); 
        if(hasIce) System.out.println("Yes");
        else System.out.println("No");
    }

    public void addIce(boolean addice){
        hasIce = addice;
    }
}
