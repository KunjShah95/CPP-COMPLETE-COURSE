#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class Bank{
    private:
    string name;
    long long accnumber;
    char type[10];
    long long amount =0;
    long long tot=0 ;
    public:
    void setvalue(){
        cout<<"Enter your name"<<endl;
        cin.ignore();
        //to use the space in string
        getline(cin,name);
        cout<<"Enter your account number"<<endl;
        cin>>accnumber;
        cout<<"Enter your account type"<<endl;
        cin>>type;
        cout<<"Enter Balance"<<endl;
        cin>>tot;
    }
    void showdata(){
        cout<<"Name : "<<name<<endl;
        cout<<"Account number : "<<accnumber<<endl;
        cout<<"Account type : "<<type<<endl;
        cout<<"Balance : "<<tot<<endl;
    }
    void deposit(){
        cout<<"Enter amount to be deposited\n";
        cin>>amount;
}
    void showbal(){
        tot = tot+amount;
        cout<<"\nTotal balance is: "<<tot;
    }
    void withdraw(){
        int a,avai_balance;
        cout<<"Enter amount to be withdrawn\n";
        cin>>a;
        avai_balance= tot-a;
        cout<<"\nTotal balance  is: "<<avai_balance;
    }
};
int main()
{Bank b;
 
    int choice;
 
    // Infinite while loop to choose
    // options everytime
    while (1) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~WELCOME~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~\n\n";
        cout << "Enter Your Choice\n";
        cout << "\t1. Enter name, Account "
             << "number, Account type\n";
        cout << "\t2. Balance Enquiry\n";
        cout << "\t3. Deposit Money\n";
        cout << "\t4. Show Total balance\n";
        cout << "\t5. Withdraw Money\n";
        cout << "\t6. Cancel\n";
        cin >> choice;
 
        // Choices to select from
        switch (choice) {
        case 1:
            b.setvalue();
            break;
        case 2:
            b.showdata();
            break;
        case 3:
            b.deposit();
            break;
        case 4:
            b.showbal();
            break;
        case 5:
            b.withdraw();
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "\nInvalid choice\n";
        }
    }

    return 0;
}