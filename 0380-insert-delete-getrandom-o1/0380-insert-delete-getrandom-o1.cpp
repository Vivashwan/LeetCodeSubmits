class RandomizedSet {
public:
    unordered_map<int, int>mp;
    vector<int>nums;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end())
        {
            nums.push_back(val);
            mp[val] = nums.size()-1;
            return true;
        }
        else return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end())
        {
            int last = nums.back();
            mp[last] = mp[val];
            nums[mp[val]] = last;
            nums.pop_back();
            mp.erase(val);
            
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */