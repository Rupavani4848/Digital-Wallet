
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct USER {
    int userID;
    int Bal;
};
int find(USER users[],int num,int userID) {
    for(int i=0;i<num;i++) 
    {
        if(users[i].userID==userID)
        {
            return i;
        }
    }
    return -1;
}
bool compareUsers(USER a,USER b) {
    if(b.Bal==a.Bal)
        return b.userID>a.userID;
    return b.Bal>a.Bal;
}
int main() {
    int num,T;
    cin>>num;
    USER users[num];
    for(int i=0;i<num;i++) {
        cin>>users[i].userID>>users[i].Bal;
    }
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int from_userID,to_userID,AMOUNT;
        cin>>from_userID>>to_userID>>AMOUNT;
        int fromIndex=find(users,num,from_userID);
        int toIndex=find(users,num,to_userID);
        if(users[fromIndex].Bal>=AMOUNT)
        {
            users[fromIndex].Bal-=AMOUNT;
            users[toIndex].Bal+=AMOUNT;
            cout<<"Success"<<endl;
        } 
        else 
        {
            cout<<"Failure"<<endl;
        }
    }
    sort(users,users+num,compareUsers);
    cout<<endl;
    for(int i=0;i<num;i++) 
    {
        cout<<users[i].userID<<" "<<users[i].Bal<<endl;
    }
    return 0;
}
