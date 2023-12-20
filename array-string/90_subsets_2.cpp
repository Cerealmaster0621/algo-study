

#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {10,5,2,6};
    set<vector<int>> subsets;
    int k = 100;
    int n = arr.size(), cnt = 0, product = 1;
    for(int i  = 1; i<(1<<n);i++){
        vector<int> subset;
        for(int j = 0; j<n; j++){
            if((i>>j)&1){
                subset.push_back(arr[j]);
                cnt++;
            }
        }
        sort(subset.begin(),subset.end());
        subsets.insert(subset);
    }
    vector<vector<int>> ans = vector<vector<int>>(subsets.begin(),subsets.end());
    for(int i = 0; i< (1<<n); i++){
        for(int j = 0; j<ans[i].size();j++){
            cout<<"| "<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
    // cout<<"total count : "<<cnt<<endl;
}