class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        if(n < 3){
            return false;
        }

        stack<int> s;
        vector<int> pge(n, INT_MIN), temp(n, INT_MAX);

        temp[1] = nums[0]; 
        for(int i = 2; i < n; i++){
            temp[i] = min(nums[i - 1], temp[i - 1]);
        }
        
        for(int i = 0; i < n; i++){
            
            while(!s.empty() && nums[s.top()] <= nums[i]){
                s.pop();
            }

            if(!s.empty()){
                pge[i] = nums[s.top()];

                int pgeIdx = s.top();

                int x = temp[pgeIdx]; // min element before pge 
                int y = pge[i]; // pge of current element
                int z = nums[i]; // current element

                if(x < z && z < y){
                    return true;
                }
            }

            s.push(i);
        }

        return false;
    }
};