#include<iostream>
using namespace std;

int main(){
    //Array examples

    int marks[] = {23, 45, 56, 89};
    //cout<<"These are marks"<<endl;
    //cout<<marks[0]<<endl;
    //cout<<marks[1]<<endl;
    //You can change the value of any array
    //marks[2] = 455;
    //cout<<marks[2]<<endl;
    //cout<<marks[3]<<endl;


    //int mathmarks[4];
    //mathmarks[0] = 2278;
    //mathmarks[1] = 738;
    //mathmarks[2] = 378;
    //mathmarks[3] = 578;
    //cout<<"These are math marks"<<endl;
    //cout<<mathmarks[0]<<endl;
    //cout<<mathmarks[1]<<endl;
    //cout<<mathmarks[2]<<endl;
    //cout<<mathmarks[3]<<endl;

    //for(int i=0; i<4; i++){
    //    cout<<"The value of marks "<<i<<" is "<<marks[i]<<endl;
    //}

    //int i = 0;
    //while(i<4){
    //    cout<<"The value of marks "<<i<<" is "<<marks[i]<<endl;
    //    i++;
   //}

    //int i = 0;
    //do{cout<<"The value of marks "<<i<<" is "<<marks[i]<<endl; i++;}
    //while(i<4);

    //Pointers and arrays
    int *p = marks;
    cout<<"The value of *p is "<<*p<<endl;
    cout<<"The value of *(p+1) is "<<*(p+1)<<endl;
    cout<<"The value of *(p+2) is "<<*(p+2)<<endl;
    cout<<"The value of *(p+3) is "<<*(p+3)<<endl;

    cout<<*(p++)<<endl;
    cout<<*(++p)<<endl;
    //return 0;
}
