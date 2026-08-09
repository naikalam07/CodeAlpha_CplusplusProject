#include <iostream>
#include <fstream>

using namespace std;


//Username exists check
bool usernameExists(string username){
    ifstream file("users.txt");

    string storedUsername;
    string storedPassword;


    while (file>>storedUsername>>storedPassword){
        if (storedUsername==username){

            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Registering Users
void UserRegister(){
    string username;
    string password;

    cout<<"\n === Registration === "<<endl;

    cout<<"Enter username: ";
    cin>>username;

    if (usernameExists(username)){
        cout<<"Error: Username already exists. \n";
        return;
    }

    cout<<"Enter password: ";
    cin>>password;

    
    ofstream file("users.txt",ios::app);

    file<<username<<" "<<password<<endl;

    file.close();

    cout<<"Registration Successful!"<<endl;

}

//Function for User Login

void UserLogin(){
    string username;
    string password;

    cout<<"\n === Login Page ==="<<endl;

    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream file("users.txt");

    string storedUsername;
    string storedPassword;


    // Checking username and Password to login after validation

    while (file >> storedUsername >> storedPassword){

        if (storedUsername==username && storedPassword==password){
            
            file.close();

            cout<<"  Login Successful! "<<endl;
            cout<<"  Welcome "<<username<<" ! "<<endl;

            return;
        }
    }

    file.close();

    cout<<"Error : Invalid username or password \n please try again ..."<<endl;

}

int main(){

    //task 02 Login And Registration System
    int choice;

    do{
        cout<<"\n === LOGIN AND REGISTRATION SYSTEM ==="<<endl;
        cout<<"1. Register "<<endl;
        cout<<"2. Login "<<endl;
        cout<<"3. Exit "<<endl;

        cout<<"Enter your Choice"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            //calling registration function
            UserRegister();
            break;
        
        case 2:
            //calling Login Function
            UserLogin();
            break;

        case 3:
            cout<<"Exiting Program...."<<endl;
            break;

        default:
            cout<<"Invalid Choice!"<<endl;
            break;
        }

    }while(choice!=3);

    return 0;
}