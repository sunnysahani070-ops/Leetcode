#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Twitter {
private:
    int timeStamp;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> vector of {timestamp, tweetId}
    unordered_map<int, unordered_set<int>> follows;   // followerId -> set of followeeIds

public:
    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // Max-heap to sort tweets by timestamp in descending order
        priority_queue<pair<int, int>> pq; // {timestamp, tweetId}

        // 1. Add the user's own tweets
        if (tweets.find(userId) != tweets.end()) {
            for (const auto &tweet : tweets[userId]) {
                pq.push(tweet);
            }
        }

        // 2. Add tweets from users they follow
        if (follows.find(userId) != follows.end()) {
            for (int followee : follows[userId]) {
                if (tweets.find(followee) != tweets.end()) {
                    for (const auto &tweet : tweets[followee]) {
                        pq.push(tweet);
                    }
                }
            }
        }

        // 3. Extract up to top 10 most recent tweets
        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (follows.find(followerId) != follows.end()) {
            follows[followerId].erase(followeeId);
        }
    }
};