class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) 
            return false;
      //数组就是一个简单的哈希表
        vector<int>a(26,0);
        for(auto i :s)
            a[i-'a']++;
        for(auto i :t)
            a[i-'a']--;
        for(auto i :a)
            if(i!=0)
                return false;
        return true;
    }
};
