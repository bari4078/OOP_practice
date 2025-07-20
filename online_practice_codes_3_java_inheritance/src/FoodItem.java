public class FoodItem {
    private String name;
    double price;
    int quantity;
    public FoodItem(String name, double price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public String getName(){
        return name;
    }
    public void setName(String nam){
        name = nam;
    }
    public double getPrice(){
        return price;
    }
    public void setPrice(double p){
        price = p;
    }

    public int getQuantity(){
        return quantity;
    }
    public void setQuantity(int Q){
        quantity = Q;
    }


    public void displayInfo(){
        System.out.println("Item: "+name+" Price: $" + price + " Available Quantity: "+quantity);
    }

    public void applyDiscount(double percentage){
        price -= price*percentage/100;
    }
}
