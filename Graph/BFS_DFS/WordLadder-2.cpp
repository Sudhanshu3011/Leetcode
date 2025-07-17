// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog"
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

class Solution
{
public:
    void dfs(string beginWord, string word, vector<string> &seq,
             vector<vector<string>> &ans, map<string, int> &mp)
    {

        if (word == beginWord)
        {

            vector<string> temp = seq;
            reverse(temp.begin(), temp.end());
            // for(auto it:temp){
            //     cout<<it<<" ";
            // }
            cout << endl;
            ans.push_back(temp);
            return;
        }

        int order = mp[word];
        for (int i = 0; i < word.size(); i++)
        {
            char ori = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {

                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] < order)
                {

                    seq.push_back(word);
                    dfs(beginWord, word, seq, ans, mp);
                    seq.pop_back();
                }
            }
            word[i] = ori;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList)
    {

        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        map<string, int> mp;

        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);

        while (!q.empty())
        {

            string word = q.front();
            int order = mp[word];
            q.pop();

            for (int i = 0; i < word.size(); i++)
            {
                char ori = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (st.find(word) != st.end())
                    {

                        q.push(word);
                        mp[word] = order + 1;
                        st.erase(word);
                    }
                    word[i] = ori;
                }
            }
        }

        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(beginWord, endWord, seq, ans, mp);
        }
        // for(auto it: mp){
        //     cout<<it.first<<" : "<<it.second<<endl;
        // }

        return ans;

        //BFS aaproach to solve the problem
        // vector<vector<string>> ans;
        // vector<string> path;
        // unordered_set<string> st(wordList.begin(), wordList.end());
        // queue<vector<string>> q;
        // q.push({beginWord});
        // path.push_back(beginWord);
        // int lvl=0;

        // while (!q.empty()) {
        //     vector<string> seq= q.front();
        //     q.pop();

        //     if(seq.size()>lvl){
        //         lvl++;

        //         for(auto it:path){
        //             st.erase(it);
        //         }
        //     }

        //     string word=seq.back();

        //     if(word==endWord){
        //         if(ans.size()==0){
        //             ans.push_back(seq);
        //         }
        //         else if(ans[0].size()==seq.size()){
        //             ans.push_back(seq);
        //         }
        //     }

        //     for(int i=0;i<word.size();i++){

        //         char ori=word[i];
        //         for(char c='a';c<='z';c++){

        //             word[i]=c;
        //             if(st.find(word)!=st.end()){
        //                 seq.push_back(word);
        //                 q.push(seq);

        //                 path.push_back(word);
        //                 seq.pop_back();

        //             }
        //         }
        //         word[i]=ori;

        //     }

        // }
        // return ans;
    }
};