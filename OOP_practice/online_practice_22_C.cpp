#include <bits/stdc++.h>
using namespace std;

class BankAccount{
private:
    string name;
    string acc_num;
    double balance;
public:
    void set_name(string n){name=n;}
    string get_name(){return name;}
    void set_acc_num(string acc){acc_num=acc;}
    string get_acc_num(){return acc_num;}
    void set_balance(double b){balance = b;}
    double get_balance(){return balance;}
    BankAccount(){
        name="";
        acc_num="00";
        balance=0;
    }

    ~BankAccount(){}
    void deposit(double d){
        balance += d;
    }
    void withdraw(double w){
        balance -= w;
    }
    void display(){
        cout<<" Account Number: "<<acc_num<<endl;
        cout<<" Account Holder: "<<name<<endl;
        cout<<" Balance: "<<balance<<endl;
    }
};

class Bank{
private:
    int max;
    int size=0;
    BankAccount *accounts;
public:
    Bank(){
        max=10;
        accounts=new BankAccount[max];
    }
    Bank(int n){
        max=n;
        accounts=new BankAccount[max];
    }
    ~Bank(){
        delete[] accounts;
    }
    void addAccount(string no,string nam){
        accounts[size].set_acc_num(no);
        accounts[size].set_name(nam);
        size++;
    }
    void displayAllAccounts(){
        cout<<"Registered Accounts: "<<endl;
        for(int i=0;i<size;i++){
            accounts[i].display();
            cout<<endl;
        }
    }
    void removeAccount(string no){
        for(int i=0;i<size;i++){
            if(accounts[i].get_acc_num()==no){
                cout<<"Account '"<<accounts[i].get_name()<<" "<<accounts[i].get_acc_num()<<"' removed successfully"<<endl;
                for(int j=i;j<size;j++){
                    accounts[j]=accounts[j+1];
                }
                size--;
                return;
            }
        }
    }
    void deposit(string no,double amount){
        for(int i=0;i<size;i++){
            if(accounts[i].get_acc_num()==no){
                accounts[i].set_balance(accounts[i].get_balance()+amount);
                return;
            }
        }
    }
    void withdraw(string no,double amount){
        for(int i=0;i<size;i++){
            if(accounts[i].get_acc_num()==no){
                accounts[i].set_balance(accounts[i].get_balance()-amount);
                return;
            }
        }
    }
};

int main() {
Bank bank;
// Add new bank accounts
bank.addAccount("12345", "John Doe");
bank.addAccount("67890", "Jane Smith");
// Perform transactions
bank.deposit("12345", 1000.0);
bank.deposit("67890", 500.0);
// Display account details
bank.displayAllAccounts();
// Perform transactions
bank.withdraw("12345", 200.0);
bank.withdraw("67890", 500.0);
// Display account details after transaction
bank.displayAllAccounts();
// Remove an account
bank.removeAccount("67890");
// Display account details after removal
bank.displayAllAccounts();
// Add more accounts
bank.addAccount("24680", "Sarah Adams");
bank.addAccount("13579", "Michael Lee");
// Perform transactions on the newly added accounts
bank.deposit("24680", 1500.0);
bank.deposit("13579", 200.0);
bank.withdraw("13579", 100.0);
bank.withdraw("24680", 300.0);
// Display all accounts
bank.displayAllAccounts();
return 0;
}