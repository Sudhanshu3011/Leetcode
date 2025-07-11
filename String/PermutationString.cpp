// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

//                                                                                  In other words,
//     return true if one of s1's permutations is the substring of s2.

//            Example 1 :

//     Input : s1 = "ab",
//             s2 = "eidbaooo" Output : true Explanation : s2 contains one permutation of s1("ba").Example 2 :

//     Input : s1 = "ab",
//             s2 = "eidboaoo" Output : false

class Solution
{
public:
    bool same_mapping(vector<int> str1, vector<int> str2)
    {

        for (int i = 0; i < 26; i++)
        {
            if (str1[i] != str2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {

        if (s1.size() > s2.size())
            return false;

        vector<int> str1(26, 0), str2(26, 0);

        for (int i = 0; i < s1.size(); i++)
        {

            str1[s1[i] - 'a']++;
        }

        int windsize = s1.size();

        for (int i = 0; i < windsize; i++)
        {
            str2[s2[i] - 'a']++;
        }

        if (same_mapping(str1, str2))
            return true;

        if (windsize < s2.size())
        {

            for (int i = windsize; i < s2.size(); i++)
            {

                str2[s2[i - windsize] - 'a']--;
                str2[s2[i] - 'a']++;

                if (same_mapping(str1, str2))
                    return true;
            }
        }

        return false;
    }
};

//  void permutation(int ind,string &s1,set<string> &permu){

//         if(ind==s1.size()-1){
//             permu.insert(s1);
//         }

//         for(int i=ind;i<s1.size();i++){

//             swap(s1[ind],s1[i]);
//             permutation(ind+1,s1,permu);
//             swap(s1[ind],s1[i]);

//         }
//     }
//     bool checkInclusion(string s1, string s2) {
//         set<string> permutate;
//         permutation(0,s1,permutate);

//         for(auto itr:permutate){

//             if(s2.find(itr)!=string :: npos)return true;
//         }

//         return false;
//     }
