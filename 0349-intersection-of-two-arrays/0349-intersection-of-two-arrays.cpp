class Solution {
public:
    vector<int> intersection(vector<int>& set1, vector<int>& joint) {
        vector<int> answer;

        sort(set1.begin(), set1.end());
        sort(joint.begin(), joint.end());

        size_t i = 0;
        size_t j = 0;

        while (i < set1.size() && j < joint.size()) {
            if (set1[i] == joint[j]) {
                if (answer.empty() || answer.back() != set1[i]) {
                    answer.push_back(set1[i]);
                }
                i++;
                j++;
            } 
            else if (set1[i] < joint[j]) {
                i++;
            } 
            else {
                j++;
            }
        }

        return answer;
    }
};