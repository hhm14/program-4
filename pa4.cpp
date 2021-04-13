class Solution {
public:
    void small2(vector<int> mod, int &f, int &s) {
        int first = INT_MAX;
        int second = INT_MAX;
        for (int i = 0; i < mod.size(); ++i) {
            if (mod[i] < first) {
                second = first;
                first = mod[i];
            }
            else if (mod[i] <= second ) {
                second = mod[i];
            }
        }
        f = first;
        s = second;
    }
    
    int maxSumDivThree(vector<int>& nums) {
        vector<int> mod1;
        vector<int> mod2;
        int f,s,x,y;
        int sum = 0;
        
        vector<int> sumMinus;
        
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (nums[i] %3 == 1) {
                mod1.push_back(nums[i]); // holds all nums with reminder 1
            }
            
            else if (nums[i] %3 == 2) {
                mod2.push_back(nums[i]); // holds all nums with remainder 2
            }
        }
        
        small2(mod1,x,y);
        small2(mod2,f,s);

        if(sum %3 ==0) { // no need to alter so we just return 
            return sum;
        }
        
        if(sum %3 ==1) {
            if(mod1.size() >= 1) {
                sumMinus.push_back(sum - x); // if sum has remainder one we can subtract one element with remainder one 
            }
            if(mod2.size() >= 2) {
                sumMinus.push_back(sum - f - s); // if sum has remainder one we can subtract two elements with remainder two
            }
        }
        
        if(sum %3 ==2) {
            if(mod2.size() >= 1) {
                sumMinus.push_back(sum - f); // if sum has remainder two we can subtract one element with remainder two 
            }
            
            if(mod1.size() >= 2) {
                sumMinus.push_back(sum - x - y); // if sum has remainder two we can subtract two elements with remainder one 
            }
        }
        
        return *max_element(sumMinus.begin(), sumMinus.end()); // return maximum solution where x mod 3 = 0
    }
};
