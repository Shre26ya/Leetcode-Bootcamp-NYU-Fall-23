class LRUCache {
public:
//vector<vector<int>> can be used for brute force but it will not pass all the test cases as we will be erasing the components which will again take like O(n) bringing the overall complexity to O(n2)

//DLL and Map data structures will be used

// Implementation heavy question

list<int> dll; // this will work as a double linked list
map<int, pair<list<int>:: iterator, int>> mp; //iterator is how you store the address

int n;

    LRUCache(int capacity) {

        n = capacity;
        
    }

    void makeRecentlyUsed(int key){

        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    
    int get(int key) {

        if(mp.find(key) == mp.end())
        return -1;

        makeRecentlyUsed(key);
        return mp[key].second;
        
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        }

        else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if(n<0){
            int key_tobe_del = dll.back();
            mp.erase(key_tobe_del);
            dll.pop_back();
            n++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
