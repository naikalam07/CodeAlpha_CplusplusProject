#include <iostream>
using namespace std;


int main(){

    int no_of_Courses;
    string Grade;
    float CreditHours;
    float totalCreditHours=0;
    float GradePoints;
    float totalGradePoints=0;
    float GPA;

    cout<<"Please Enter the Number of Courses You Have Taken : ";
    cin>>no_of_Courses;


    for (int i=0;i<no_of_Courses;i++){
        cout<<"Enter The Grade for Course "<<i+1<<endl;
        cin>>Grade;
        cout<<"Enter The Credit Hours for Course "<<i+1<<endl;
        cin>>CreditHours;
        totalCreditHours+=CreditHours;

        if (Grade=="A"){
            GradePoints= CreditHours * 4;
            totalGradePoints+=GradePoints;
        }
        else if(Grade=="A-"){
            GradePoints=CreditHours * 3.67;
            totalGradePoints+=GradePoints;
        }
        else if (Grade=="B+"){
            GradePoints=CreditHours * 3.33;
            totalGradePoints+=GradePoints;
        }
        else if (Grade=="B"){
            GradePoints=CreditHours * 3.00;
            totalGradePoints+=GradePoints;
        }
        else if (Grade=="B-"){
            GradePoints=CreditHours * 2.67;
            totalGradePoints+=GradePoints;
        }        
        else if (Grade=="C+"){
            GradePoints=CreditHours * 2.33;
            totalGradePoints+=GradePoints;
        }
        else if (Grade=="C"){
            GradePoints=CreditHours * 2.00;
            totalGradePoints+=GradePoints;
        } 
        else if (Grade=="C-"){
            GradePoints=CreditHours * 1.67;
            totalGradePoints+=GradePoints;
        } 
        else if (Grade=="D+"){
            GradePoints=CreditHours * 1.33;
            totalGradePoints+=GradePoints;
        } 
        else if (Grade=="D"){
            GradePoints=CreditHours * 1.00;
            totalGradePoints+=GradePoints;
        } 
        else {
            GradePoints=CreditHours * 0.00;
            totalGradePoints+=GradePoints;
        }    
    }
     
    float CGPA,OldCgpa,totalCreditHoursTillLastSem;
    //Computing GPA

    GPA = totalGradePoints / totalCreditHours;
    cout<<"Please Enter Previous Semester's CGPA (if any): "<<endl;
    cin>>OldCgpa;
    cout<<"Please Enter total Credit Hours Till Your Last Semester: "<<endl;
    cin>>totalCreditHoursTillLastSem;
    CGPA = (( OldCgpa * totalCreditHoursTillLastSem ) + (GPA * totalCreditHours) ) / (totalCreditHours + totalCreditHoursTillLastSem );

    cout<<"\n All Courses Details"<<endl;
    for(int i=0 ; i<no_of_Courses;i++){
        cout<<"======= Course "<<i+1<<" ========"<<endl;
        cout<<"Grade: "<<Grade<<", Credit Hours: "<<CreditHours<<endl;
        cout<<endl;
    }
    cout<<"GPA (Current Semester): "<<GPA<<endl;
    cout<<"CGPA: "<<CGPA<<endl;
    
    return 0;
}