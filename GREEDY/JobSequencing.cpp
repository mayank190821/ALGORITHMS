#include<bits/stdc++.h>
using namespace std;

struct jobs{
    char name;
    int deadline;
    int profit; 
};
bool cmp(jobs j1,jobs j2){
    return j1.profit>j2.profit;
}
void jobSequencing(jobs jb[],int n){
    sort(jb,jb+n,cmp);
    char result[n];
    bool slot[n];
    for(int i=0;i<n;i++){
        slot[i]=false; // All slots are empty
    }
    for(int i=0;i<n;i++){
        for(int j = min(n,jb[i].deadline)-1;j>=0;j--){
            if(slot[j]==false){
                slot[j] =true;
                result[j]=i;
                break;
            }            
        }
    }
    for(int i=0;i<n;i++){
        if(slot[i])
            cout<<jb[result[i]].name<<" ";
    }
}
int main(){
    int n=5;
    jobs jb[n] ={{'a',2,100},{'b',1,19},{'c',2,27},{'d',1,25},{'e',3,15}};
    jobSequencing(jb,n);
    return 0;
}