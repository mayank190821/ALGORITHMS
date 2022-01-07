#include<bits/stdc++.h>
using namespace std;

/*
    * Item      I       II      III     IV
    * Weight    5       3       4       2
    * Value     100     60      40      120
    * Ratio     20      20      10      60
    kanpsackCapacity = 10
    Ans = 260
*/
struct kanpsackProblem{
    int value;
    int weight;
};
bool ratioComparision(kanpsackProblem k1,kanpsackProblem k2){
    double r1 = double(k1.value)/double(k1.weight);
    double r2 = double(k2.value)/double(k2.weight);
    return r1>r2;
}

float fKnapsack(kanpsackProblem kn[],int n,int capacity){
    float maxValue=0;
    int curW=0;
    float remain=0;
    sort(kn,kn+n,ratioComparision);
    for(int i=0;i<n;i++){
        if(curW+kn[i].weight<capacity){
            curW +=kn[i].weight;
            maxValue+=kn[i].value;
        }
        else{
            remain=capacity-curW;
            cout<<kn[i].value<< "   "<<remain<<endl;
            maxValue+= kn[i].value * (remain/kn[i].weight);
            break;
        }
    }
    return maxValue;
}

int main(){
    int n;
    int capacity;
    cin>>n;
    cin>>capacity;
    kanpsackProblem kn[n];
    for(int i=0;i<n;i++){
        cin>>kn[i].value;
        cin>>kn[i].weight;
    }
    cout<<"Maximum Value: "<<fKnapsack(kn,n,capacity);
}