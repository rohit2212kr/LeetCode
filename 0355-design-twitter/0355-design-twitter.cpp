class Twitter {
public:

    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<tuple<int, int, int, int>> pq;

        // User follows himself
        following[userId].insert(userId);

        // Put latest tweet of every followed user into heap
        for(int user : following[userId]) {

            if(!tweets[user].empty()) {

                int index = tweets[user].size() - 1;

                pq.push({
                    tweets[user][index].first,
                    tweets[user][index].second,
                    user,
                    index
                });
            }
        }

        vector<int> ans;

        // Get 10 most recent tweets
        while(!pq.empty() && ans.size() < 10) {

            auto [time, tweetId, user, index] = pq.top();
            pq.pop();

            ans.push_back(tweetId);

            // Add previous tweet of this user
            if(index > 0) {

                index--;

                pq.push({
                    tweets[user][index].first,
                    tweets[user][index].second,
                    user,
                    index
                });
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};