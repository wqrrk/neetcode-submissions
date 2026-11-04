class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result; 
        result.resize(temperatures.size());
        stack<int> seq; 
        for (int i = 0; i < temperatures.size(); i++) { 
            while (!seq.empty() && temperatures[seq.top()] < temperatures[i]) { 
                result[seq.top()] = i - seq.top();
                seq.pop();
            }
            seq.push(i);
        }
        return result;
    }
};