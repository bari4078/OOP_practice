
class Animal {
    private String name;
    private int age;
    
    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    // your code
    public void setName(String nam){
        name = nam;
    }
    public String getName(){
        return name;
    }

    public void setAge(int age){
        this.age = age;
    }
    public int getAge(){
        return age;
    }

}

// your code
class Bird extends Animal{
    public Bird(String nam, int a){
        super(nam,a);
    }
}

class Albatross extends Bird{
    public Albatross(String nam,int a){
        super(nam,a);
    }
}



public class Main {
    public static void main(String[] args) {
        Bird alex = new Albatross("Alex", 39);
        Mammal spot = new Dog("Spot", 7);
        Mammal fred = new FruitBat("Fred", 10);
        Reptile steph = new EasternBrownSnake("Steph", 12);
        Fish bruce = new GreatWhiteShark("Bruce", 40);
        Arachnid charlotte = new RedBackSpider("Charlotte", 1);
        Mammal perry = new Platypus("Perry", 5);
        Mammal bob = new Human("Bob", 20);

        Animal[] animals = { alex, spot, fred, steph, bruce, charlotte, perry, bob };
        for (Animal a : animals) {
            System.out.print(a);
            if (a instanceof Mammal) {
                ((Mammal) a).printBloodType();
            }
            if (a.isLethalToAdultHumans()) {
                System.out.print(", and it's lethal!");
            }
            System.out.println();
        }
        System.out.println();
    }
}

/* Output
Alexis a Albatross, aged 39
Spotis a Dog, aged 7, Warm-Blooded!
Fredis a FruitBat, aged 10, Warm-Blooded!
Stephis a EasternBrownSnake, aged 12, and it's lethal!
Bruceis a GreatWhiteShark, aged 40
Charlotteis a RedBackSpider, aged 1, and it's lethal!
Perryis a Platypus, aged 5, Warm-Blooded!
Bobis a Human, aged 20, Warm-Blooded!
*/