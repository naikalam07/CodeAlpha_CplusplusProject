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