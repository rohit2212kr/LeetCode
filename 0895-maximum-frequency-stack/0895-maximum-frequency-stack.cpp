class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxi = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxi = max(maxi,freq[val]);
        group[freq[val]].push(val);
    }
    
    int pop() {
        int val  = group[maxi].top();
        group[maxi].pop();
        freq[val]--;
        if(group[maxi].empty()) maxi--;
        return val;

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */