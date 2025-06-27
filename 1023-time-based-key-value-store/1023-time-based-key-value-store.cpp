class TimeMap {
public:
   private:
    map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timeStamp) {
        mp[key].push_back({timeStamp, value});
    }

    string get(string key, int timeStamp) {
        if (mp.find(key) == mp.end()) return "";

        vector<pair<int, string>>& values = mp[key];
        int left = 0, right = values.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first == timeStamp) {
                return values[mid].second;
            } else if (values[mid].first < timeStamp) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right < 0) return "";
        return values[right].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */