struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};
class MyCircularQueue {
public:
    Node* front;
    Node* rear;
    int count ; 
    int capacity;
    MyCircularQueue(int k) {
        front = NULL;
        rear = NULL;
        count  = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        Node* newNode = new Node(value);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }

        else if(count == 1){
            rear = NULL;
            front = NULL;
        }
        else{
            front = front-> next;
        }
        count--;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        else{
            return front->val;
        }
    }
    
    int Rear() {
         if(isEmpty()){
            return -1;
        }
        else{
            return rear->val;
        }
    }
    
    bool isEmpty() {
        if(count == 0){
            return true;
        }
        else{
            return false;
        }

    }
    
    bool isFull() {
        if(count == capacity){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */