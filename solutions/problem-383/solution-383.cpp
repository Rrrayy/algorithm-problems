class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        /*map<char,int>mp;
        for(auto i=0;i<magazine.size();++i)
            mp[magazine[i]]++;
        for(auto i=0;i<ransomNote.size();++i){
            mp[ransomNote[i]]--;
            if(mp[ransomNote[i]]<0)
                return false;
        }
        return true;
        */
        //时间优化
        if(ransomNote.size()>magazine.size())
            return false;
        int nums[26]={0};
        for(auto i:magazine)
            nums[i-'a']++;
        for(auto i:ransomNote){
            nums[i-'a']--;
            if(nums[i-'a']<0)
                return false;
        }
        return true;
    }
};
