vector<bool> answerQueries(vector<int>& arr, vector<vector<int>>& queries, int limit) {
    vector<int> prefix = {arr[0]};
    int sz = queries.size();
    vector<int> ans (sz);
    //prefix has added.
    for(int i = 1 ;i <arr.size();i++){
        int new_var = arr[i] + prefix[i-1];
        prefix.push_back(new_var);
    } 
    for(auto& k : queries){
        int i = k[0], j = k[1];
        bool flg = limit > prefix[j]-prefix[i]+arr[i];
        ans.push_back(flg);
    }
    return ans;
}