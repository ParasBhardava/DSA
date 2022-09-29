#include<iostream>

using namespace std;

int main(){
    //cout<<"This is tutorial 9";
    int age;
    cout<< "Tell me your age"<<endl;
    cin>>age;

    //Selection control structure: If else-if else ladder
    //if((age<18)&&(age>0)){
    //    cout<<"You can not come to my party"<<endl;
    //}
    //else if(age==18){
    //    cout<<"You are a kid and will get a kid pass to the party"<<endl;
    //}
    //else if(age<1){
    //    cout<<"You are not yet born"<<endl;
    //}
    //else{
    //    cout<<"You can come to the party"<<endl;
    //}

    //Selection control structure: Switch case statement
    switch (age)
    {
    case 18:
        /* code */
        cout<<"You are eligible for Car and Motor cycle with gear Liecense"<<endl;
        break;

    case 20:
        /* code */
        cout<<"You are eligible for Commercial Liecense"<<endl;
        break;

    case 16:

        cout<<"You are eligible for Motor cycle without gear Liecense"<<endl;
        break;

    case 2:
       /* code */
       cout<<"You are 2"<<endl;
       break;

 default:
 cout<<"No special cases"<<endl;
        break;
   }

    return 0;
}
