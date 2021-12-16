#include<bits/stdc++.h>
using namespace std;

struct knapsack{
    int value;
    int weight;
};
bool comparision(knapsack k1, knapsack k2){
    double r1 = double(k1.value)/k1.weight;
    double r2 = double(k2.value)/k2.weight;
    return r1>r2;
}
int fKnapsack(knapsack kn[],int n,int w){
    sort(kn,kn+n,comparision);
    int curWgh = 0;
    double finalValue=0.0;
    for(int i = 0;i<n;i++){
        if(curWgh + kn[i].weight<=w){
            finalValue += kn[i].value;
            curWgh += kn[i].weight; 
        }
        else{
            int remain = w-curWgh;
            finalValue += kn[i].value*( (double) remain/kn[i].weight); 
            break;
        }
    }
    return finalValue;
}
int main(){
    int n=5;
    int w=50;
    knapsack kn[n] = {{60,10},{100,20},{120,30},{90,40},{50,5}};
    cout<<"Maximum value:  "<<fKnapsack(kn,n,w);
    return 0;
}