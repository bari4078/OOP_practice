public class Dessert extends FoodItem{
    private int calories;

    public Dessert(String name, double price, int quant,int cal){
        super(name,price,quant);
        calories = cal;
    }

    public void displayInfo(){
        super.displayInfo();
        System.out.println("Calories: "+calories+" kcal");
    }

    public void halfServing(){
        setQuantity(getQuantity()/2);
        setPrice(getPrice()/2);
    }
}
