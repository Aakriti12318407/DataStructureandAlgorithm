/* Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        Node *fast = head;
        Node *slow = head;
        
        for(int i = 0; i < k ; i++){
            if(fast == NULL)
                return -1;
                fast= fast->next;
            }
            while (fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        // code here
        return slow->data;
    }
};