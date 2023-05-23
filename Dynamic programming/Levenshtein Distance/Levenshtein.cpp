#include <iostream>
#include <vector>
using namespace std;

int levenshtein(string str1,string str2){
    int len1 = str1.size(), len2 =str2.size();
    vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));

    for(int i =0;i<=len1;i++){
        for (int j=0; j<=len2; j++) {
            //至少存在一个字符串为空串
            if(i == 0) {dp[0][j] = j; continue;}
            if(j == 0) {dp[i][0] = i; continue;}
            // insert
            int poss1 = dp[i-1][j] + 1;
            // delete
            int poss2 = dp[i][j-1] + 1;
            // change or not
            int poss3 = dp[i-1][j-1];
            if(str1[i-1] != str2[j-1]) poss3++;
            dp[i][j] = min(poss1,min(poss2,poss3));
        }
    }
    return dp[len1][len2];
}
// 64 位输出请用 printf("%lld")