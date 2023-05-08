#include <iostream>
using namespace std;

class atm{
protected:
    int cash=5000;

public:
    void showBalance();
    void withdraw(int amount);
    void deposit(int amount);
};

void atm::showBalance(){
    cout<<"Your current balance is "<<cash<<endl;
}

void atm::withdraw(int amount){
    if(amount>cash){
        cout<<"Insufficient balance"<<endl;
    }
    else {
        cash=cash-amount;
        cout<<"Withdraw successful. Current balance is "<<cash<<endl;
    }
}

void atm::deposit(int amount){
    if(amount<=0){
        cout<<"Invalid amount"<<endl;
    }
    else {
        cash = cash + amount;
        cout<<"Deposit successful. Current balance is "<<cash<<endl;
    }
}

class userdetails {
private:
    string usernames[5]={"Ajax","gman","dman","kman","belik"};
    int passwords[5]= {1840,1234,5678,9134,2344};
    bool user_active[5]={true,false,true,false};
public:
    bool verifyuser(string username,int password);
    bool isaccountactive(string username);
};

bool userdetails::verifyuser(string username,int password){
    for(int i=0;i<5;i++){
        if(usernames[i]==username && passwords[i]==password && user_active[i]){
            return true;
        }
    }
    return false;
}

bool userdetails::isaccountactive(string name){
    for(int i=0;i<5;i++){
        if(usernames[i]==name && user_active[i]){
            return true;
        }
    }
    return false;
}

class showdetails{
public:
    void showuserdetails(string username,int password);
};

void showdetails::showuserdetails(string username,int password){

    userdetails ud;
    if(ud.verifyuser(username, password)){
        if(ud.isaccountactive(username)){
            cout<<"Account is active"<<endl;
        }
        else {
            cout<<"Account is inactive"<<endl;
        }
    }
    else {
        cout<<"Invalid Username or Password"<<endl;
    }
}

int main(){
    string username;
    int password;
    int option;
    int amount;
    
    atm a;
    showdetails s;
    
    cout<<"Enter username"<<endl;
    cin>>username;
    cout<<"Enter Password"<<endl;
    cin>>password;
    
    if(userdetails().verifyuser(username, password)){
        cout<<"Login Successfull"<<endl;
        while(true){
            cout<<"A. Check Balance"<<endl;
            cout<<"B. Withdraw cash"<<endl;
            cout<<"C. Deposit Cash"<<endl;
            cout<<"D. Exit"<<endl;
            cout<<"Choose an option"<<endl;
            cin>>option;
            switch(option){
                case 1:
                    a.showBalance();
                    break;
                case 2:
                    cout<<"Enter the amount to withdraw"<<endl;
                    cin>>amount;
                    a.withdraw(amount);
                    break;
                case 3:
                    cout<<"Enter the amount to deposit"<<endl;
                    cin>>amount;
                    a.deposit(amount);
                    break;
                case 4:
                cout<<"Thank you for using the service";
                    exit(0);
                    break;
                default :
                    cout<<"Invalid option selected"<<endl;
                    break;
            }
        }
    }
    else {
        cout<<"Invalid username or password"<<endl;
    }
    return 0;
}