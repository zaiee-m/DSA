class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        for(auto &ticket: tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }

        for (auto& pair : adj) {
            // Sort descending because we pop from the back of the vector in the DFS
            sort(pair.second.begin(), pair.second.end(), greater<string>()); 
        }

        vector<string> path;
        stack<string> st;

        st.push("JFK");

        while(!st.empty()){
            string current = st.top();
            if(!adj[current].empty()){
                st.push(adj[current].back());
                adj[current].pop_back();
            }

            else{
                path.push_back(current);
                st.pop();
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
};