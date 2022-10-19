class Solution {
public:
    static bool cmpfunc1(pair<string, int>& a, pair<string, int>& b){
        if (a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second; // greater to smaller
    }
    void sort(map<string, int>& mp, vector<pair<string, int>>& vpairs){
        for (auto& m:mp){
            vpairs.push_back(m);
        }
        std::sort(vpairs.begin(), vpairs.end(), cmpfunc1);
        // for (auto& it : vpairs) {
        //     cout << it.first << ' '<< it.second << endl;
        // }
    }
    vector<string> solution1(vector<string>& words, int k){
        vector<string>res;
        map<string, int> mp;
        for (string s:words){
            mp[s]++;
        }
        // for (auto m:mp){
        //     cout << m.first << ":" << m.second << endl;
        // }
        vector<pair<string, int>> vpairs;
        sort(mp, vpairs);
        for (int i=0;i<k;i++){
            res.push_back(vpairs[i].first);
        }
        return res;
    }
    struct cmpfunc2{
        bool operator()(pair<int, string>a, pair<int, string>b){
            if (a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    vector<string> solution2(vector<string>& words, int k){
        vector<string>res;
        map<string, int> mp;
        for (string s:words){
            mp[s]++;
        }
        ////Creat max-heap by priority queue.
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmpfunc2> hp;
        for (auto m:mp){
            hp.push({m.second, m.first});
        }
        // while (!hp.empty()){
        //     cout << hp.top().first << ":" << hp.top().second << endl;
        //     hp.pop();
        // }
        for (int i=0;i<k;i++){
            res.push_back(hp.top().second);
            hp.pop();
        }
        return res;
    }
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        // return solution1(words, k);
        return solution2(words, k);
    }
};
