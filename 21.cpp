#include <iostream>
#include <vector>
using namespace std;

// list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      
        ListNode* head= nullptr; //head of final linked list
        ListNode* tail= nullptr; //tail of final linked list

        while (list1 != nullptr && list2 != nullptr){

            int val =0;

            if (list1->val < list2->val){
                //insert lower value to val
                //move list1 ptr to next

                val=list1->val;
                list1=list1->next;
            }

            else if(list1->val > list2->val){
                //insert lower value to val
                //move list2 ptr to next

                val=list2->val;
                list2=list2->next;
            }

            else{
                //insert val1 and val 2 in new linked list
                //move list1 and list2 ptr to next
                
                val=list1->val;
                

                ListNode* newNode = new ListNode(list2->val); 

                    if (head==nullptr){
                        head = newNode;
                    }
                    else{
                        tail->next=newNode;
                    }
                    tail = newNode;

                list1= list1->next;
                list2= list2->next;
            }

            ListNode* newNode = new ListNode(val); 

            if (head==nullptr){
                head = newNode;
            }
            else{
                tail->next=newNode;
            }
            tail = newNode;
        }

        while (list1 != nullptr) {
            ListNode* newNode = new ListNode(list1->val);
            if (head == nullptr) {
                head = newNode;
            } else {
                tail->next = newNode;
            }
            tail = newNode;
            list1 = list1->next;
        }

        while (list2 != nullptr) {
            ListNode* newNode = new ListNode(list2->val);
            if (head == nullptr) {
                head = newNode;
            } else {
                tail->next = newNode;
            }
            tail = newNode;
            list2 = list2->next;
        }

        return head; // Return the head of the merged list
    }
};


void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

int main() {
    // Example input lists
    vector<int> list1_values = {1, 2, 4};
    vector<int> list2_values = {1, 3, 4};

    // Create linked lists from the input arrays
    ListNode* list1 = createList(list1_values);
    ListNode* list2 = createList(list2_values);

    // Create a Solution object
    Solution solution;

    // Merge the two lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}