class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> colors;
        int result = 0;
        for (int i = 0; i < answers.size(); i++) {
            if (answers[i] == 0) {
                result++;
                continue;
            }
            if (colors.find(answers[i]) == colors.end()) {
                result += answers[i] + 1;
                colors[answers[i]] = answers[i];
            } else {
                colors[answers[i]] -= 1;
                if (colors[answers[i]] < 0) {
                    colors[answers[i]] = answers[i];
                    result += answers[i] + 1;
                }
                
            }
        }
        return result;
    }
};