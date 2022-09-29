#include<iostream>
using namespace std;

int main(){

    int num;
    cout<<"Enter the number you want to multiplication table of"<<endl;
    cin>>num;

    for(int i = 1; i <= 10; i++){
        cout<<num<<" X "<<i<<" = "<<num*i<<endl;
    }

    //int i = 1;
    //while(i <= 10){
    //cout<<num<<" X "<<i<<" = "<<num*i<<endl;
    //      i++;
    //}

    //int i = 1;
    //do{cout<<num<<" X "<<i<<" = "<<num*i<<endl; i++;}
    //while(i <= 10);

    return 0;
}
