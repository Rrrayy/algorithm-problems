class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2)
            return false;
        vector<int>cnt1(26,0);
        vector<int>cnt2(26,0);
        for(int i=0;i<n1;++i)
            cnt1[s1[i]-'a']++;
        for(int i=0;i<n1;++i)
            cnt2[s2[i]-'a']++;
        if(cnt1==cnt2)
            return true;
        for(int i=1;i<=n2-n1;++i){
            cnt2[s2[i-1]-'a']--;
            cnt2[s2[i+n1-1]-'a']++;
            if(cnt1==cnt2)
                return true;
        }
        return false;
    }
};