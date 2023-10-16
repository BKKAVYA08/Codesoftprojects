#include<iostream>
using namespace std;
        
        int main(){
            char operation;
            double num1,num2;

            cout<<"Enter the First Number: ";
            cin>>num1;
            cout<<"\nEnter The Second Number: ";
            cin>>num2;
            cout<<"Enter operation(+ For Addition,- For Substraction,* For Multiplication,/ For Division): ";
            cin>>operation;
            switch(operation){
                case '+':
                cout<<"The Addition Of Two Numbers: "<<num1+num2<<endl;
                break;
                case '-':
                cout<<"The Subtraction Of Two Numbers: "<<num1-num2<<endl;
                break;
                case '*':
                cout<<"The Multiplication Of Two Numbers: "<<num1*num2<<endl;
                break;
                case '/':
                if(num2!=0){
                    cout<<"The Division Of Two Numbers: "<<num1/num2<<endl;
                }else{
                    cout<<"Error!!.Division By Zero Is Not Allowed...."<<endl;

                }
                break;
                default:
                cout<<"Invalid Operation......Please Enter Valid Operation."<<endl;
                break;
                
            }
            return 1;
        }