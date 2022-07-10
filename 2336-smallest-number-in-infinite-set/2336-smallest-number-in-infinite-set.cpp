class SmallestInfiniteSet {
public:
    set<int> arr;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++)
            arr.insert(i);
    }
    
    int popSmallest() {
        int s = *arr.begin();
        arr.erase(s);
        return s;
    }
    
    void addBack(int num) {
        arr.insert(num);   
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */