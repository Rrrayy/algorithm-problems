//思路是把strs中每个每个元素先排序，然后放在以排序后的字符串为key的数组里，该数组就是字母异位词数组，然后通过move优化拷贝开销

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        for(auto &s:strs){
            string key=s;
            sort(key.begin(),key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>>res;
        for(auto &pair:groups){
            res.push_back(move(pair.second));
        }
        return res;
    }
};
