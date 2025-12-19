class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        vector<bool> hasSecret(n, false);
        hasSecret[0] = true;
        hasSecret[firstPerson] = true;

        int m = meetings.size();
        int i = 0;

        while (i < m) {
            int j = i;
            int currentTime = meetings[i][2];
            while (j < m && meetings[j][2] == currentTime) {
                j++;
            }

            unordered_map<int, vector<int>> graph;
            unordered_set<int> currentBatchPeople;

            for (int k = i; k < j; ++k) {
                int u = meetings[k][0];
                int v = meetings[k][1];
                graph[u].push_back(v);
                graph[v].push_back(u);
                currentBatchPeople.insert(u);
                currentBatchPeople.insert(v);
            }
            
            queue<int> q;
            for (int person : currentBatchPeople) {
                if (hasSecret[person]) {
                    q.push(person);
                }
            }
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (!hasSecret[v]) {
                        hasSecret[v] = true;
                        q.push(v);
                    }
                }
            }

           
            i = j;
        }

       
        vector<int> result;
        for (int k = 0; k < n; ++k) {
            if (hasSecret[k]) {
                result.push_back(k);
            }
        }

        return result;
    }
};
