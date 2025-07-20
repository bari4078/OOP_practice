public class Snack extends FoodItem{
    private boolean isSpicy = false;

    public Snack(String name, double price, int quant, boolean spiciness){
        super(name,price,quant);
        isSpicy = spiciness;
    }

    public void displayInfo(){
        super.displayInfo();
        System.out.print("Spicy: ");
        if(isSpicy) System.out.println("Yes");
        else System.out.println("No");
    }

    public void toggleSpiciness(){
        if(isSpicy) isSpicy = false;
        else isSpicy = true;
    }
}
