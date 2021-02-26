#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//Case 1 : Increasing --> Decreasing --> Increasing
pair<bool,pair<int,int> > isCase1(vector<int>arr,int n){
     
     int i = 0;
     while(i<n-1 && arr[i]<arr[i+1]){
         i++;
     }
     int peak_loc = i;
     while(i<n-1 && arr[i]>arr[i+1]){
         i++;
     }
     int valley_loc = i;
     while(i<n-1 && arr[i]<arr[i+1]){
         i++;
     }
     if(i!=n-1)
        return make_pair(false,make_pair(-1,-1));
     bool res1 = (peak_loc>0) ? arr[valley_loc]>arr[peak_loc-1] : true;
     bool res2 = (valley_loc<n-1) ? arr[peak_loc]<arr[valley_loc+1] : true;
     return make_pair(res1 && res2,make_pair(peak_loc,valley_loc));
}

pair<bool,pair<int,int> > isCase2(vector<int>arr,int n){
     int i = 0;
     while(i<n-1 && arr[i]<arr[i+1]){
         i++;
     }
     int peak1_loc = i;
     while(i<n-1 && arr[i]>arr[i+1]){
         i++;
     }
     int valley1_loc = i;
     while(i<n-1 && arr[i]<arr[i+1]){
         i++;
     }
     int peak2_loc = i;
    //  if(peak2_loc+1!=n-1)
    //     return make_pair(false,make_pair(-1,-1));
    // int valley2_loc = peak2_loc + 1;
    int valley2_loc = peak2_loc + 1;
    i+=1;
    while(i<n-1 && arr[i]<arr[i+1])
        i++;
    if(i!=n-1)
        return make_pair(false,make_pair(-1,-1));
    
    bool ans1 =  (peak1_loc>0) ? (arr[valley2_loc]>arr[peak1_loc-1] && arr[valley2_loc]<arr[valley1_loc]) : true;

    bool ans2 = arr[peak1_loc]>arr[peak2_loc];
    bool ans3 = valley2_loc+1<n-1 ? arr[peak1_loc]<arr[valley2_loc+1] : true;
    // if(ans1&&ans2){
    // cout<<"Peak 1 : "<<peak1_loc<<endl;
    // cout<<"Valley 1 : "<<valley1_loc<<endl;
    // cout<<"Peak 2 : "<<peak2_loc<<endl;
    // cout<<"Valley 2 : "<<valley2_loc<<endl;
    // }
    return make_pair(ans1 && ans2 && ans3,make_pair(peak1_loc,valley2_loc));
}

bool isSorted(vector<int>arr,int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
            return false;
    }
    return true;
}

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
   int n = arr.size();
   if(isSorted(arr,n)){
       cout<<"yes";
       return;
   }
   else if(n==2 && arr[0]>arr[1]){
        cout<<"yes"<<endl;
        cout<<"swap 1 2";
   }
   else if(isCase1(arr,n).first){
        pair<bool,pair<int,int> >ans = isCase1(arr,n);
        if(ans.first){
            cout<<"yes"<<endl;
            int l = (ans.second).first + 1;
            int r = (ans.second).second + 1;
            if(r-l==1){
                cout<<"swap "<<l<<" "<<r;
            }
            else{
                cout<<"reverse "<<l<<" "<<r;
            }
        }
   }
