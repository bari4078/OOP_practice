

public class Main {
    public static void main(String[] args) {
        // Create instances of Beverage, Snack, and Dessert
        Beverage soda = new Beverage("Soda", 1.99, 2, "Medium"); 
        Snack chips = new Snack("Chips", 2.49, 1, true);          
        Dessert cake = new Dessert("Chocolate Cake", 4.99, 3, 300); 

        // Create a FoodCart object
        FoodCart cart = new FoodCart();

        // Add items to the cart
        cart.addItem(soda);
        cart.addItem(chips);
        cart.addItem(cake);

        // Display the cart contents
        System.out.println("Initial Cart:");
        cart.showCart();

        // Apply unique functionalities
        soda.addIce(true);      // Add ice to soda
        chips.toggleSpiciness(); // Change spiciness of chips
        cake.halfServing();     // Reduce cake serving to half

        // Apply discounts
        soda.applyDiscount(10); // 10% off
        cake.applyDiscount(15); // 15% off

        // Display the updated cart
        System.out.println("Updated Cart After Applying Unique Features and Discounts:");
        cart.showCart();

        // Calculate and display the total price
        double total = cart.calculateTotal();
        System.out.printf("Total Price: $%.2f\n", total);
    }
}


        //Output

        // Initial Cart:
        // --- Food Cart Items ---
        // Name: Soda, Price: $1.99, Quantity: 2
        // Size: Medium, Ice: No Ice
        // --------------------
        // Name: Chips, Price: $2.49, Quantity: 1
        // Spicy: Yes
        // --------------------
        // Name: Chocolate Cake, Price: $4.99, Quantity: 3
        // Calories: 300 kcal
        // --------------------

        // Ice added to Soda
        // Spiciness of Chips is now disabled
        // Half serving applied to Chocolate Cake

        // Updated Cart After Applying Unique Features and Discounts:
        // --- Food Cart Items ---
        // Name: Soda, Price: $1.79, Quantity: 2
        // Size: Medium, Ice: Added
        // --------------------
        // Name: Chips, Price: $2.49, Quantity: 1
        // Spicy: No
        // --------------------
        // Name: Chocolate Cake, Price: $2.12, Quantity: 1
        // Calories: 300 kcal
        // --------------------

        // Total Price: $8.19