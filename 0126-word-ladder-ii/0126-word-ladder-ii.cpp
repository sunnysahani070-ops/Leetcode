#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // If the endWord isn't in the dictionary, no sequence exists.
        if (dict.find(endWord) == dict.end()) {
            return {};
        }

        // Map to store the predecessor of each word to build the path later
        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel;
        currentLevel.insert(beginWord);
        
        bool found = false;
        int wordLen = beginWord.length();

        // Step 1: BFS to build the graph of shortest paths
        while (!currentLevel.empty() && !found) {
            // Remove all words of the current level from the dictionary 
            // to prevent cycles and ensure we only find the *shortest* paths.
            for (const string& word : currentLevel) {
                dict.erase(word);
            }
            
            unordered_set<string> nextLevel;
            for (string word : currentLevel) {
                string original = word;
                
                // Try changing every character of the word
                for (int i = 0; i < wordLen; i++) {
                    char c = word[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        if (c == j) continue;
                        word[i] = j;
                        
                        if (dict.find(word) != dict.end()) {
                            nextLevel.insert(word);
                            parents[word].push_back(original); // Link to parent
                            if (word == endWord) {
                                found = true;
                            }
                        }
                    }
                    word[i] = c; // Revert back to original character
                }
            }
            currentLevel = nextLevel;
        }

        vector<vector<string>> res;
        // Step 2: DFS to reconstruct paths from endWord to beginWord
        if (found) {
            vector<string> path;
            path.push_back(endWord);
            dfs(endWord, beginWord, parents, path, res);
        }
        
        return res;
    }

private:
    void dfs(const string& currentWord, const string& beginWord, 
             unordered_map<string, vector<string>>& parents, 
             vector<string>& path, vector<vector<string>>& res) {
        
        // Base case: we reached the starting word
        if (currentWord == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            res.push_back(validPath);
            return;
        }

        // Backtrack through all parents of the current word
        for (const string& p : parents[currentWord]) {
            path.push_back(p);
            dfs(p, beginWord, parents, path, res);
            path.pop_back(); // Backtrack
        }
    }
};