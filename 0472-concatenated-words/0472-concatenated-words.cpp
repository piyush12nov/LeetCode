class Solution {
 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    vector<string> ans;
    set<string> wordSet{begin(words), end(words)};
    map<string, bool> memo;

    for (auto word : words)
      if (isConcat(word, wordSet, memo))
        ans.push_back(word);

    return ans;
  }

  bool isConcat(string& s,  set<string>& wordSet,map<string, bool>& memo) {
    if (memo.count(s))
      return memo[s];

    for (int i = 0; i < s.length(); ++i) {
        string prefix = s.substr(0, i+1);
        string suffix = s.substr(i+1);
      if (wordSet.count(prefix) && (wordSet.count(suffix) || isConcat(suffix, wordSet, memo)))
        return memo[s] = true;
    }

    return memo[s] = false;
  }
};
