class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string result;
        while (true) {
            result = repeat(word, k + 1);
            if (sequence.find(result) == string::npos) {
                return k;
            }
            k++;
        }
        
    }
    
    string repeat(string s, int times) {
        if (times == 0) {
            return NULL;
        }
        string result = s;
        for (int i = 0; i < times - 1; i++) {
            result += s;
        }
        return result;
    }
};
