#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head){
	if(!head)
	return nullptr;

	ListNode* l1 = nullptr;
	ListNode* l2 = head;
	while(l2!=nullptr)
	{
		auto l3 = l2->next;
		l2->next = l1;
		l1 = l2;
		l2 = l3;
	}
	return l1;
}


void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void destroyList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(7);

    printList(head);
    head = reverseList(head);
    printList(head);

    destroyList(head);
    return 0;
}