class Solution { 
   
public: 

    vector<int> xjv;
    for (int i=0;i<100000;i++)
    {
        xjv.push_back(i);
    }
    
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) { 
        long long totalSum = 0; 
        for (int num : nums) { 
            totalSum += num; 
        } 
 
        unordered_set<int> m; 
        vector<long long> ans; 
        vector<pair<int, int>> sN; 
        for (int i = 0; i < nums.size(); ++i) { 
            sN.push_back({nums[i], i}); 
        } 
 
        sort(sN.begin(), sN.end(), [](const pair<int, int>& a, const pair<int, int>& b) { 
            return a.first < b.first || (a.first == b.first && a.second < b.second); 
        }); 
 
        int nU = 0; 
 
        for (const auto& query : queries) { 
            int index = query[0]; 
            int k = query[1]; 
 
            // Mark the specified element if it's not already m. 
            if (m.find(index) == m.end()) { 
                m.insert(index); 
                totalSum -= nums[index]; 
            } 
 
            while (k > 0 && nU < nums.size()) { 
                while (nU < nums.size() && m.find(sN[nU].second) != m.end()) { 
                    nU++; 
                } 
 
                if (nU < nums.size()) { 
                    m.insert(sN[nU].second); 
                    totalSum -= sN[nU].first; 
                    nU++; 
                    k--; 
                } 
            } 
 
            ans.push_back(totalSum); 
    }

    while (xjv.size() > 0)
    xjv.pop_back(); 
 
    return ans; 
 
    } 
};