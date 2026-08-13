
// Need a container for value and next
struct Node {
    int val;
    Node* next;

    Node (int x) : val(x), next(nullptr) {}
};

class MinStack {
public:
    stack<int> st;
    Node* head;

    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        // Create new node
        Node* newNode = new Node(val);

        // Set next value to CURRENT head
        newNode->next = head;

        // Update head
        head = newNode;

        // Check & Update Min
        if (st.empty() || head->val <= st.top()) {
            st.push(head->val);
        }
    }
    
    void pop() {
        // Node pointer to help keep track of next Node
        Node* curNode = head->next;

        // Before head gets updated:
        // Check & Update Min
        if (head->val == st.top()) {
            st.pop();
        }

        // Delete head
        delete head;

        // Update head to curNode
        head = curNode;
    }
    
    int top() {
        // Get value of head
        return head->val;
    }
    
    int getMin() {
        // Get class value of min
        return st.top();
    }
};