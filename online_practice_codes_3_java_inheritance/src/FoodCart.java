public class FoodCart {
    private FoodItem[] items = new FoodItem[10];
    private static int curr_size = 0;

    public FoodCart(){

    }

    public void addItem(FoodItem item){
        items[curr_size++] = item;
    }

    public void showCart(){
        System.out.println("======== Displaying Cart ========");
        for(int i=0;i<curr_size;i++){
            items[i].displayInfo();
        }
        System.out.println("----------------------------------");
        System.out.println("Cart Total: $"+calculateTotal());
        System.out.println("===============================");
    }

    public double calculateTotal(){
        double total = 0;
        for(int i=0;i<curr_size;i++){
            total += items[i].getPrice()*items[i].getQuantity();
        }
        return total;
    }
}
