class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res=0,left=0;
        int sumT=0,sumF=0;
        for(int right=0;right<answerKey.size();++right){
            if(answerKey[right]=='T')   sumT++;
            else    sumF++;
            while(min(sumT,sumF)>k){
                if(answerKey[left]=='T')    sumT--;
                else    sumF--;
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};