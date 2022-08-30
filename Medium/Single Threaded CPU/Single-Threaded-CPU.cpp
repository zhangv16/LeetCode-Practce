class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> result;
        vector<vector<int>> sorted_tasks; //contains tasks sorted by enqueueTime
        for (int i = 0; i < tasks.size(); i++) {
            sorted_tasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        std::sort(sorted_tasks.begin(), sorted_tasks.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> ready_tasks;
        long long curr_time = 0;
        int curr_index = 0;
        
        // run until we went over all elements in sorted_tasks
        while ((curr_index < tasks.size()) || !ready_tasks.empty()) {
            for (int i = curr_index; i < tasks.size(); i++) {
                // check if this task and ready, or if no tasks are processing
                if ((sorted_tasks[i][0] <= curr_time) || ready_tasks.empty()) {
                    // no tasks are processing
                    if (sorted_tasks[i][0] > curr_time) curr_time = sorted_tasks[i][0];
                    ready_tasks.push({sorted_tasks[i][1], sorted_tasks[i][2]});
                    curr_index++;
                } else {
                    break;
                }
            }
            auto front = ready_tasks.top();
            ready_tasks.pop();
            result.push_back(front.second);
            curr_time += front.first;
        }
        return result;
    }
};