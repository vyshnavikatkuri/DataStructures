#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool isprime(int num){
    if(num<=1) {
        return false; 
    }
    if(num==2){
        return true;
    } 
    if(num%2==0) return false;
    for(int i=3;i<=sqrt(num);i+=2){
       if(num%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){                                //tc:o(sqrt(n)/2);sc=o(1)
        if(isprime(i)) cout<<i<<"is prime"<<endl;
        else cout<<i<<"is not prime"<<endl;
    }
    return 0;
}