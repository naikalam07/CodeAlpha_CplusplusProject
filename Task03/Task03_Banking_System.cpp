// Task03 Banking System
#include <iostream>
#include <fstream>

using namespace std;

// Class for Transaction
class Transaction{
    public:
    string type;
    double amount;

    Transaction(){
        type="";
        amount=0;
    }

    Transaction(string t, double a){
        type=t;
        amount=a;
    }
};

//Class for Account
class Account{
    public:
        int accountNumber;
        double balance;
        Transaction transactions[100];
        int transactionCount;
        
        
    Account(){
            accountNumber=0;
            balance=0;
            transactionCount=0;
     }

    Account(int accNo,double bal){
            accountNumber=accNo;
            balance=bal;
            transactionCount=0;
    }

    void Deposit(double amount){
        if(amount<=0){
            cout<<"Invalid amount!"<<endl;
            return;
        }

        balance=balance+amount;

        transactions[transactionCount]=Transaction("Deposit", amount);

        transactionCount++;
        cout<<"Deposit successful!"<<endl;

    }
void withdraw(double amount){
        if (amount<=0){
            cout<<"Invalid amount!" << endl;
            return;
        }

        if (amount > balance){
            cout<<"Insufficient balance!" << endl;
            return;
        }

        balance=balance-amount;

        transactions[transactionCount]=Transaction("Withdrawal", amount);

        transactionCount++;
        cout<<"Withdrawal successful!" << endl;
    }

    // Display account information
    void displayAccount(){
        cout<<"\n===== ACCOUNT INFORMATION =====" << endl;
        cout<<"Account Number: " << accountNumber << endl;
        cout<<"Balance: " << balance << endl;
    }

    // Display transaction history
    void showTransactions(){
        cout<<"\n===TRANSACTION HISTORY==="<<endl;
        if (transactionCount == 0){
            cout<<"No transactions found."<<endl;
            return;
        }

        for (int i=0;i<transactionCount;i++){
            cout<<i+1<<". "<< transactions[i].type<< " : "<<transactions[i].amount<<endl;
        }
    }
};


//CLASS for customer
class Customer
{
public:
    int customerID;
    string name;
    Account account;

    Customer(){
        customerID=0;
        name="";
    }

    Customer(int id, string n, int accountNumber, double balance){
        customerID = id;
        name = n;
        account = Account(accountNumber, balance);
    }

    //Display customer information
    void displayCustomer(){
        cout<<"\n===== CUSTOMER INFORMATION =====" << endl;
        cout<<"Customer ID: " << customerID << endl;
        cout<<"Name: " << name << endl;

        account.displayAccount();
    }
};


//Banking System
void transferMoney(Customer &sender, Customer &receiver, double amount){
    if (amount <= 0){
        cout << "Invalid amount!" << endl;
        return;
    }

    if (amount > sender.account.balance){
        cout << "Insufficient balance!" << endl;
        return;
    }

    // Remove money from sender
    sender.account.balance=sender.account.balance-amount;

    // Add money to receiver
    receiver.account.balance=receiver.account.balance+amount;

    // Add transactions
    sender.account.transactions[sender.account.transactionCount]=Transaction("Transfer Sent", amount);

    sender.account.transactionCount++;

    receiver.account.transactions[receiver.account.transactionCount]=Transaction("Transfer Received", amount);

    receiver.account.transactionCount++;

    cout<<"Transfer successful!"<<endl;
};


int main(){
    Customer customer1;
    Customer customer2;

    int choice;

    cout<<"=== CREATE CUSTOMER 1 ===" << endl;

    int id;
    string name;
    int accountNumber;
    double initialBalance;

    cout<<"Enter Customer ID: ";
    cin>>id;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Account Number: ";
    cin>>accountNumber;
    cout<<"Enter Initial Balance: ";
    cin>>initialBalance;

    customer1=Customer(id, name, accountNumber, initialBalance);


    cout<<"\n=== CREATE CUSTOMER 2 ==="<<endl;

    cout<<"Enter Customer ID: ";
    cin>>id;

    cout<<"Enter Name: ";
    cin>>name;

    cout<<"Enter Account Number: ";
    cin>>accountNumber;

    cout<<"Enter Initial Balance: ";
    cin>>initialBalance;

    customer2=Customer(id, name, accountNumber, initialBalance);


    do
    {
        cout<<"\n=== BANKING SYSTEM ==="<<endl;

        cout<<"1. Display Customer 1"<<endl;
        cout<<"2. Display Customer 2"<<endl;
        cout<<"3. Deposit"<<endl;
        cout<<"4. Withdraw"<<endl;
        cout<<"5. Transfer Money"<<endl;
        cout<<"6. Show Transactions"<<endl;
        cout<<"7. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;


        //Display Customer
        if (choice==1){
            customer1.displayCustomer();
        }

        else if (choice==2){
            customer2.displayCustomer();
        }


        //Deposit
        else if (choice==3){
            int account;
            double amount;

            cout<<"Enter account number: ";
            cin>>account;

            cout<<"Enter amount: ";
            cin>>amount;

            if (account==customer1.account.accountNumber){
                customer1.account.Deposit(amount);
            }
            else if (account==customer2.account.accountNumber){
                customer2.account.Deposit(amount);
            }
            else{
                cout<<"Account not found!"<<endl;
            }
        }


        // Withdraw
        else if (choice==4){
            int account;
            double amount;

            cout<<"Enter account number: ";
            cin>>account;

            cout<<"Enter amount: ";
            cin>>amount;

            if (account==customer1.account.accountNumber){
                customer1.account.withdraw(amount);
            }
            else if (account==customer2.account.accountNumber){
                customer2.account.withdraw(amount);
            }
            else{
                cout<<"Account not found!"<<endl;
            }
        }


        //Transfer
        else if (choice==5){
            int senderAccount;
            int receiverAccount;
            double amount;

            cout<<"Enter sender account number: ";
            cin>>senderAccount;

            cout<<"Enter receiver account number: ";
            cin>>receiverAccount;

            cout<<"Enter amount: ";
            cin>>amount;

            if (senderAccount==customer1.account.accountNumber &&receiverAccount==customer2.account.accountNumber) {
                transferMoney(customer1, customer2, amount);
            }
            else if (senderAccount==customer2.account.accountNumber &&receiverAccount==customer1.account.accountNumber){
                transferMoney(customer2, customer1, amount);
            }
            else{
                cout<<"Invalid account numbers!" << endl;
            }
        }


        // Transactions
        else if (choice==6){
            int account;

            cout<<"Enter account number: ";
            cin>>account;

            if (account==customer1.account.accountNumber){
                customer1.account.showTransactions();
            }
            else if (account==customer2.account.accountNumber){
                customer2.account.showTransactions();
            }
            else{
                cout<<"Account not found!"<<endl;
            }
        }


        // Exit
        else if (choice==7){
            cout<<"Thank you for using the Banking System!"<<endl;
        }

        else{
            cout<<"Invalid choice!"<<endl;
        }

    } while (choice!=7);

    return 0;
}