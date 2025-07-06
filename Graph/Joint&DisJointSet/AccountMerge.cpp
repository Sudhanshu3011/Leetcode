// Accounts Merge
// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

// Example 1:

// Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email "johnsmith@mail.com".
// The third John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

// Implementation logic:-
// sort the given accounts
// create a map for the mail accounts given, linked with the person considering as a node,
// if the mail is coming more than one time , then link the incoming mail node with the 
// parent of the existing mail node using the Dsu logic
// mailmerge vector merge the correct email with the correct node and collectively shows 
// all the mail for the appropriate node (person)
// Go through the mailmerge if there is a list of mail present for the node, place the 
// person name at the first of the list and append all the other mail with it 
// (after sorting it), and finaly push it to the ans.


class Disjoint {
public:
    vector<int> parent, siz;

    Disjoint(int n) {
        parent.resize(n);
        siz.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int fUpar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = fUpar(parent[node]);
    }

    void Union(int u, int v) {
        int upar = fUpar(u);
        int vpar = fUpar(v);

        if (upar == vpar)
            return;

        if (siz[upar] < siz[vpar]) {
            parent[upar] = vpar;
            siz[vpar] += siz[upar];
        } else {
            parent[vpar] = upar;
            siz[upar] += siz[vpar];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);

        unordered_map<string, int> mailmap;  

        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mailmap.find(mail) == mailmap.end()) {
                    mailmap[mail] = i;
                } else {
                    ds.Union(i, mailmap[mail]);
                }
            }
        }


        vector<vector<string>> mailmerge(n);
        for (auto& it : mailmap) {
            string mail = it.first;
            int node = ds.fUpar(it.second);
            mailmerge[node].push_back(mail);
        }


        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mailmerge[i].empty()) continue;

            sort(mailmerge[i].begin(), mailmerge[i].end());

            vector<string> acc;
            acc.push_back(accounts[i][0]);  
            for (auto& email : mailmerge[i]) {
                acc.push_back(email);
            }

            ans.push_back(acc);
        }

        return ans;
    }
};
