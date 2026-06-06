class Twitter {
public:
    int global_time;
    // tweets maps userId -> vector of {tweetId, global_time}
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, set<int>> users;

    Twitter() {
        global_time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, global_time}); // Fixed typo
        global_time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> tweetsof(users[userId].begin(), users[userId].end());
        tweetsof.push_back(userId);

        auto comp = [](pair<int, pair<int,int>>& a, pair<int, pair<int,int>>& b){
            return a.second.second < b.second.second; 
        }; 


        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, decltype(comp)> pq(comp);

        stack<pair<int, pair<int,int>>> buffer;

        for(auto user: tweetsof){
            if(!tweets[user].empty()) {
                pq.push({user, tweets[user].back()});
                buffer.push({user, tweets[user].back()}); 
                tweets[user].pop_back();
            }
        }

        vector<int> feed;
        while(feed.size() < 10 && !pq.empty()){
            auto [currUserId, tweetData] = pq.top(); 
            pq.pop();
            
            feed.push_back(tweetData.first); 
            
            if(!tweets[currUserId].empty()) {
                pq.push({currUserId, tweets[currUserId].back()});
                buffer.push({currUserId, tweets[currUserId].back()});
                tweets[currUserId].pop_back();
            }
        }

        while(!buffer.empty()){
            auto [user, tweet] = buffer.top();
            buffer.pop();
            tweets[user].push_back(tweet);
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].erase(followeeId); 
    }
};