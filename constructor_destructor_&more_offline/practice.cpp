#include <bits/stdc++.h>
using namespace std;

class Fraction{
private:
    int numerator;
    int denominator;
public:
    void round(){
        int a=abs(denominator),b=abs(numerator);
        while(b != 0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        
        if(a!=0){
        this->numerator=numerator/a;
        this->denominator = denominator/a;
        }
        if(denominator < 0){
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    //constructors
    Fraction(){
        numerator=0;
        denominator=1;
    }
    Fraction(int x){
        numerator=x;
        denominator=1;
    }
    Fraction(int x,int y){
        numerator=x;
        denominator=y;
        round();
    }

    //destructor
    ~Fraction(){}
    //getter
    int getNumerator(){
        return numerator;
    }
    int getDenominator(){
        return denominator;
    }

    //setters
    void setNumerator(int n){
        this->numerator = n;
    }
    void setDenominator(int n){
        this->denominator = n;
    }
    //add
    Fraction add(int n){
        Fraction result;
        result.setNumerator(this->numerator + denominator*n);
        result.setDenominator(this->denominator);
        result.round();
        return result;
    }
    Fraction add(Fraction &f){
        Fraction result;
        result.setNumerator(this->denominator*f.numerator + this->numerator*f.denominator);
        result.setDenominator(this->denominator*f.denominator);
        result.round();
        return result;
    }

    //subtract
    Fraction sub(int n){
        Fraction result;
        result.setNumerator(this->numerator - this->denominator*n);
        result.setDenominator(this->denominator);
        result.round();
        return result;
    }
    Fraction sub(Fraction &f){
        Fraction result;
        result.setNumerator(this->numerator*f.denominator-f.numerator*this->denominator);
        result.setDenominator(this->denominator*f.denominator);
        result.round();
        return result;
    }

    //multiplication
    Fraction mul(int n){
        Fraction result;
        result.setNumerator(this->numerator*n);
        result.setDenominator(this->denominator);
        result.round();
        return result;
    }
    Fraction mul(Fraction &f){
        Fraction result;
        result.setNumerator(this->numerator*f.numerator);
        result.setDenominator(this->denominator*f.denominator);
        result.round();
        return result;
    }

    //division
    Fraction div(int n){
        Fraction result;
        if(n==0){
            cout<<"Cannot divide by 0"<<endl;
            result.setDenominator(this->denominator);
        }
        else{
            result.setDenominator((this->denominator)*n);
        }
        result.setNumerator(this->numerator);
        result.round();
        return result;
    }
    Fraction div(Fraction &f){
        Fraction result;
        result.setNumerator(this->numerator*f.denominator);
        int n=f.numerator;
        if(n != 0)
            result.setDenominator(this->denominator*n);
        else{
            cout<<"Cannot divide by 0"<<endl;
            result.setDenominator(this->denominator);
        }
        result.round();
        return result;
    }

    //print
    void print(){
        this->round();
        cout<<numerator<<"/"<<denominator<<endl;
    }

};

class FractionCollection{
private:
    int maxlength;
    int length;
    Fraction* fractions;
public:
    //constructors
    FractionCollection(int size = 10){
        maxlength = size;
        length=0;
        fractions = new Fraction[maxlength];
    }
    ~FractionCollection(){
        delete[] fractions;
    }

    //insertion
    void insert(Fraction f){
        f.round();
        fractions[length].setNumerator(f.getNumerator());
        fractions[length].setDenominator(f.getDenominator());
        fractions[length].round();
        length++;
    }
        
    void insert(int pos,Fraction f){
        f.round();
        for(int i=length;i>pos;i--){
            fractions[i] = Fraction(fractions[i-1]);
        }
        fractions[pos].setNumerator(f.getNumerator());
        fractions[pos].setDenominator(f.getDenominator());
        fractions[pos].round();
        length++;
    }

    //removal
    void remove(){
        length--;
        fractions[length].setNumerator(0);
        fractions[length].setDenominator(1);
    }
    void remove(int pos){
        length--;
        for(int i=pos;i<length;i++){
            fractions[i]= Fraction(fractions[i+1]);
        }
    }
    void remove(Fraction f){
        int idx = -1;
        for(int i = 0; i < length; i++){
            if(fractions[i].getNumerator() == f.getNumerator() &&
               fractions[i].getDenominator() == f.getDenominator()){
                idx = i;
                break;
            }
        }
        if(idx != -1){
            remove(idx); // now shift elements
        }
    }

    //max min
    Fraction getMax(){
        int idx=0;
        double temp;
        double max=fractions[0].getNumerator() / (double) fractions[0].getDenominator();
        for(int i=1;i<length;i++){
            temp = fractions[i].getNumerator() / (double) fractions[i].getDenominator();
            if(max < temp){ 
                idx = i;
                max=temp;
            }
        }
        return fractions[idx];
    }
    Fraction getMin(){
        int idx=0;
        double temp;
        double min=fractions[0].getNumerator() / (double) fractions[0].getDenominator();
        for(int i=1;i<length;i++){
            temp = fractions[i].getNumerator() / (double) fractions[i].getDenominator();
            if(min > temp){
                idx =i;
                min=temp;
            }
        }
        return fractions[idx];
    }

    Fraction add(int start,int end){
        Fraction result;
        int i;
        for(i=start;i<=end;i++){
            result = result.add(fractions[i]);
        }
        result.round();
        return result;
    }

    Fraction mul(int start,int end){
        Fraction result;
        result.setNumerator(1);
        int i;
        for(i=start;i<=end;i++){
            result = result.mul(fractions[i]);
        }
        result.round();
        return result;
    }

    Fraction sub(int pos1,int pos2){
        Fraction result = Fraction(fractions[pos1].sub(fractions[pos2]));
        result.round();
        return result;
    }

    Fraction div(int pos1,int pos2){
        Fraction result;
        result = fractions[pos1].div(fractions[pos2]);
        result.round();
        return result;
    }

    //print
    void print(){
        cout<<"Fractions"<<endl;
        cout<<"-------------------------------"<<endl;
        for(int i=0;i<length;i++){
            cout<<"Fraction "<<i<<":";
            fractions[i].print();
        }
        cout<<"Max: ";getMax().print();
        cout<<"Min: ";getMin().print();
        cout<<"Summation: ";
        add(0,length-1).print();
        cout<<"Multiplication: ";
        mul(0,length-1).print();
        cout<<endl;
    }
};

int main(){ 
    //create Fraction with numerator, denominator 
    Fraction a(5,2),b(7,2),c(9,2),d(28,5); 
    cout<<"Fraction"<<endl; 
    cout<<"-------------------------------"<<endl; 
    cout<<"A: "; 
    a.print(); 
    cout<<"B: "; 
    b.print(); 
    cout<<endl; 
 
    cout<<"Add(a,b): "; 
    a.add(b).print(); 
    cout<<"Add(a,2): "; 
    a.add(2).print(); 
     
    cout<<"Sub(a,b) "; 
    a.sub(b).print(); 
    cout<<"Sub(a,2) "; 
    a.sub(2).print(); 
     
    cout<<"Mul(a,b): "; 
    a.mul(b).print(); 
    cout<<"Mul(a,2): "; 
    a.mul(2).print(); 
     
    cout<<"Div(a,b): "; 
    a.div(b).print(); 
    cout<<"Div(a,2): "; 
    a.div(2).print(); 
    cout<<"Div(a,0): "; 
    a.div(0).print(); 
 
    //Collection of Fractions 
    Fraction e,f(5),g(10); 
    FractionCollection fc(10); 
    fc.insert(a); 
    fc.insert(b); 
    fc.insert(c); 
    fc.print(); 
 
    cout<<"Sub(Pos0, Pos1): "; 
    fc.sub(0,1).print(); //subtracts the fraction at pos1 from fraction at pos0
    cout<<"Div(Pos0, Pos1): "; 
    fc.div(0,1).print(); //divides the fraction at pos0 by the fraction at pos1 
 
    fc.remove(1);  //removed 'b' 
    fc.print();  
 
    fc.remove(a); 
    fc.print();  
 
    fc.insert(d);
    fc.insert(0,e);  //insert at pos0
    fc.insert(f); 
    fc.insert(g); 
    fc.print(); 
 
    fc.remove(); //removed the last fraction 
    fc.print();  //notice the output 
         
    return 0;
}