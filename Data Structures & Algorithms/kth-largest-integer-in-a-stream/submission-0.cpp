class KthLargest {
    void sift_down(vector<int> &heap, int i){
        int l = 2*i + 1, r = 2*i + 2;
        int smallest = i;

        if (l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }

        if (r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }

        if(smallest != i){
            swap(heap[i], heap[smallest]);
            sift_down(heap, smallest);
        }
    }

    void sift_up(vector<int> &heap, int i){
        int p = (i-1)/2;
        if(heap[p] > heap[i]){
            swap(heap[p], heap[i]);
            sift_up(heap, p);
        }
    }

    int pop(){
        int val = heap[0];
        heap[0] = heap.back(); heap.pop_back();
        sift_down(heap, 0);
        return val;
    }

    int top(){
        return heap[0];
    }

public:
    vector<int> heap;

    KthLargest(int k, vector<int>& nums) {
        heap = nums;
        while(heap.size() < k) heap.push_back(INT_MIN);
        for(int i = heap.size()/2-1; i >= 0; i--) sift_down(heap, i);
        while(heap.size() > k) pop();
    }
    
    int add(int val) {
        if(heap.empty() || val >= top()){
            heap.push_back(val);
            sift_up(heap, heap.size()-1);
            pop();
        }
        return top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */