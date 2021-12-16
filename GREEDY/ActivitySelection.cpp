// TC = O(nlogn)

#include<bits/stdc++.h>
using namespace std;

struct activity{
    int start;
    int finish;
};
bool activityCompare(activity a1,activity a2){
    return (a1.finish <a2.finish);
}
void maxActivity(activity arr[],int n){
    // sorting activities according to the finish time
    sort(arr,arr+n,activityCompare);
    int j=0;
    for(int i=1;i<n;i++){
        if(arr[i].start >= arr[j].finish ){
            cout<<"("<<arr[j].start<<","<<arr[j].finish<<")"<<endl;
            j=i;
        }
    }
}
int main(){
    int n=5;
    activity arr[n];
    int startTime[n] = {5,1,3,0,5};
    int finishTime[n] ={9,2,4,6,7};
    for(int i=0;i<n;i++){
        arr[i].start = startTime[i];
        arr[i].finish = finishTime[i];
    }
    maxActivity(arr,n);
}