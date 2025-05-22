#include <bits/stdc++.h>
using namespace std;

class Product{
private:
    string name;
    double price;
public:
    Product() {
        name = "";
        price = 0.0;
    }
    Product(string n,double p){
        name = n;
        price = p;
    }
    ~Product(){}

    void set_name(string s){
        name = s;
    }
    void set_price(double p){
        price = p;
    }
    string get_name(){
        return name;
    }
    double get_price(){
        return price;
    }
    void display(){
        cout<<"Product: "<<name<<"  -Price: $"<<price<<endl;
    }

};

class OnlineStore{
private:
    int max_len;
    int size=0;
    Product *products;
public:
    OnlineStore(int s=100){
        max_len = s;
        products = new Product[max_len];
    }
    ~OnlineStore(){
        delete[] products;
    }

    void addProduct(Product p){
        products[size++]=p;
    }

    void displayProducts(){
        cout<<"Available products:"<<endl;
        int i=0;
        while(i<size){
            cout<<"    ";
            products[i].display();
            i++;
        }
    }


};

class ShoppingCart{
private:
    int max_size;
    int size=0;
    Product *products;
public:
    ShoppingCart(int s=50){
        max_size=s;
        products = new Product[max_size];
    }
    ~ShoppingCart(){
        delete[] products;
    }
    void addProduct(Product p){
        products[size++] = p;
    }
    double total_cost(){
        double total=0;
        for(int i=0;i<size;i++){
            total += products[i].get_price();
        }
        return total;
    }
    void displayCart(){
        cout<<"shopping cart: "<<endl;
        for(int i=0;i<size;i++){
            cout<<" ";
            products[i].display();
        }
        cout<<"Total Cost: "<<total_cost()<<endl;
    }
    
    void removeProduct(const string s){
        for(int i=0;i<size;i++){
            if(s == products[i].get_name()){
                for(int j=i;j<size;j++){
                    products[j]=products[j+1];
                }
                size--;
                return;
            }
        }
    }
};

int main() {
    OnlineStore store;
    // Add products to the online store
    Product product1("Laptop", 999.99);
    Product product2("Smartphone", 699.99);
    Product product3("Headphones", 99.99);
    store.addProduct(product1);
    store.addProduct(product2);
    store.addProduct(product3);
    // Display available products
    store.displayProducts();
    // Create a new shopping cart
    ShoppingCart cart;
    // Add products to the shopping cart
    cart.addProduct(product1);
    cart.addProduct(product2);
    // Display the shopping cart
    cart.displayCart();
    // Add another product to the cart
    cart.addProduct(product3);
    // Display the updated shopping cart
    cart.displayCart();
    // Remove a product from the cart
    cart.removeProduct("Laptop");
    // Display the updated shopping cart
    cart.displayCart();
    return 0;
    }