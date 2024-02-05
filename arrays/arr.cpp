class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int>temp;
        // int len=nums.size();
        // int j=0;
        // k=k%len;
        // for(int i=0;i<abs(len-k);i++)
        // {
        //     //1,2,3,4
        //     cout<<nums[i]<<" ";
        //     temp.push_back(nums[i]);
        // }
        // cout<<endl;
        // for(int i=abs(len-k);i<len;i++)
        // {
        //     //5,6,7

        //     cout<<nums[i]<<endl;
        //     nums[abs(i-abs(len-k))]=nums[i];
        // }
        // for(int i=k;i<len;i++)
        // {
        //     nums[i]=temp[j];
        //     j++;
        // }
        
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
            
        
        
    }
};

// find duplicates in arr

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        if(nums.empty())return {};
        vector<int>ans;
        sort(begin(nums),end(nums));
        int s = nums[0];
        for(int i=1;i<nums.size();i++){
            if(!(s^nums[i])){
                ans.push_back(nums[i]),i+=1;
                if(i<nums.size())s=nums[i];
                else break;
            }
                else s = nums[i];
        }
        return ans;
        
    }
};

// 2 sum problem

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {};
    }
};

// Sort an arr of 0s 1s & 2s

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n;

        int low =0, mid=0, high= nums.size()-1;
        while (mid <= high) {
            if (nums[mid] ==0) {
                swap (nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid]==1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }

        
    }
};

// Majority Elements in an arr

class Solution {
public:
    int majorityElement(vector<int>& v) {
    	int cnt=0;
	    int el;
        for (int i=0; i<v.size(); i++){
            if (cnt==0){
                cnt =1;
			    el =v[i];
            }
            else if (v[i] ==el){
                cnt ++;
            }
            else {
                cnt--;
            }
        }
        int cnt1=0;
        for (int i=0; i<v.size(); i++){
            if(v[i] == el) cnt1++;
        }
        if (cnt1 >v.size() /2) {
            return el;
        }
        return -1;      
        
    }
};

// Buy and sell STOCKS

int bestTimeToBuyAndSellStock(vector<int>&prices) {
    // Write your code here.
    int maxPro = 0;
    int n = prices.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    
    return maxPro;

}