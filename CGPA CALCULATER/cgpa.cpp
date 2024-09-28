#include<iostream>
using namespace std;
int main(){
    cout<<"  **    ***    **    ********   **          ******     ******      ***         ***  ********   || "<<endl;
    cout<<"  **   ** **   **    **         **        **          **     **    ** **     ** **  **         || "<<endl;
    cout<<"  **  **   **  **    ********   **        **         **       **   **  **   **  **  ********   || "<<endl;
    cout<<"  ** **     ** **    **         **        **          **     **    **   ** **   **  **         || "<<endl;
    cout<<"  ***        ****    ********   ********    ******     ******      **    **     **  ********   ** "<<endl;
    float n; //number of subjects
    float cgpa=0;// total CGPA 
    float totalgrade;// total Grades of all subjects
    float totalcredit;// total credit hours

    cout<<"Enter number of Subjects:"<<endl;
    cin>>n;
    // a if check is applied because anyone enterd a float value but actually value required in integer 
    if(n!=int(n)){
        cout<<"You are Enetred a float value! => Please Enter a Integer!"<<endl;
        cout<<"Enter Number of Subjects:"<<endl;
        cin>>n;
        
    }
    for(int i=1; i<n+1; i++){
        float grade;//grade in each subject
        float credit;//credit in each subject
        float sub1grade;//this is multiple of (credit and grade) of each subject
        cout<<"Enter your Grade in Subject : "<<i<<endl; 
        cin>>grade;
        cout<<"Enter your Credit Hours of Subject :"<<i<<endl;
        cin>>credit;
        // a if check is applied because anyone enterd a float value but actually value required in integer 
        if( credit!=int(credit)){
            cout<<"You are Enetred a float value! => Please Enter a Integer!"<<endl;
            cout<<"Enter Number Credit Hours of Subject :"<<endl;
            cin>>credit;
        }
        sub1grade=grade*credit;
        totalgrade+=sub1grade;
        totalcredit= totalcredit+credit;
    }
    
    cgpa= (totalgrade)/totalcredit;
    cout<<"Your Total CGPA is :"<<cgpa<<endl;


    return 0;
}