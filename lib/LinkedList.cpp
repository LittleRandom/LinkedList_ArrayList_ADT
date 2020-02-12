//
// Class that implements a singly-linked list of Items, with iterator.
// ECE 309 - Spring 2020
//

#include "LinkedList.h"

namespace ece309 {

    // if head is NULL, then list is empty
    bool LinkedList::empty() const {
        return head == nullptr;
    }

    // destructor -- delete all nodes
    LinkedList::~LinkedList() {
        delete_helper();
    }

    // copy constructor
    LinkedList::LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr) {
        copy_helper(other);
    }

    // assignment from another LinkedList
    LinkedList& LinkedList::operator= (const LinkedList& other) {
        // protect against self-assignment
        if (this == &other) return *this;
        // otherwise, delete this list and copy other
        delete_helper();
        copy_helper(other);
        return *this;
    }

    // append an item to the end of the list
    // caller gives pointer to list -- list node is now the owner and will delete when deallocated
    void LinkedList::push_back(const StringItem& a) {
        auto node = new ListNode(a);  // create a new node
        if (head == nullptr) {  // if list is empty, both head and tail point to new node
            head = node;
            tail = node;
        }
        else {  // else, make current tail point to new node
            tail->setNext(node);
            tail = node;  // and update the tail pointer
        }
        ++count;
    }

    // append an item to the front of the list
    // caller gives pointer to list -- list node is now the owner and will delete when deallocated
    void LinkedList::push_front(const StringItem& a) {
        auto node = new ListNode(a);
        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            node->setNext(head);
            head = node;
        }
        ++count;
    }

    // insert item after position indicated by iterator
    // if iterator node is NULL, insert to beginning of list
    // caller gives pointer to list -- list node is now the owner and will delete when deallocated
    void LinkedList::insertAfter(LinkedList::iterator it, const StringItem& item) // pseudocode in zyBook 2.3
    {
        if (it.node==nullptr) { // special case to insert at the head
            push_front(item);  // also increments count
        }
        else // insert after it
        {
            auto node = new ListNode(item,it.node->getNext());
            it.node->setNext(node);
            if (tail==it.node) tail = node;
            ++count;
        }
    }


    // remove first item in list, return false if empty
    bool LinkedList::pop_front(StringItem& a) {
        if (!empty()) {
            a = head->getItem();  // copy first item to a
            auto tmp = head->getNext();  // point to second node
            delete head;  // delete first node
            head = tmp;   // second node becomes head
            if (head == nullptr) {  // if list is now empty...
                tail = nullptr;     // make sure tail is also NULL
            }
            --count;
            return true;   // an item was removed, so return true
        }
        else {
            return false;  // list was empty, nothing removed
        }
    }

    // remove last item in list, return false if empty
    bool LinkedList::pop_back(StringItem& a) {
        ListNode * p = head;
        if (!p) return false;  // empty list
        a = tail->getItem();
        if (p == tail) {
            delete tail;  // remove tail and set to empty list
            head = tail = nullptr;
        }
        else {
            // this is safe because we know p will not be nullptr
            while (p->getNext() != tail) p = p->getNext();
            p->setNext(nullptr);  // remove tail from list
            delete tail;
            tail = p;
        }
        --count;
        return true;
    }

    // remove node after position indicated by iterator
    // if iterator node is NULL, remove head
    bool LinkedList::removeAfter(LinkedList::iterator it, StringItem& item) // pseudocode in zyBook 2.4
    {
        if (!empty()) {
            if (it.node == nullptr) // special case to remove head, it’s not after any node
            {
                pop_front(item);  // also decrements count
            }
            else { // normal case, if not the head, then simply disconnect the node
                ListNode *tmp = it.node;
                ListNode *remove = tmp->getNext(); // next node to be removed
                tmp->setNext(remove->getNext());   // point around node to be removed
                if (tail == remove) tail = tmp;      // if removing tail, update tail
                item = remove->getItem();
                delete remove; // delete node      // delete the removed node
                --count;
            }
            return true;
        }
        else {
            return false;
        }
    }

    // delete all list nodes and make list empty
    void LinkedList::delete_helper() {
        ListNode * p = head;
        ListNode * tmp;
        while (p) {
            tmp = p->getNext();
            delete p;
            p = tmp;
        }
        head = tail = nullptr;
        count = 0;
    }
    // copy all nodes from other list to this one, overwriting head and tail
    void LinkedList::copy_helper(const LinkedList& other) {
        ListNode *op = other.head;  // pointer for other list
        ListNode *p = nullptr;      // tail pointer for new copy list
        ListNode *h = nullptr;      // head pointer for new copy list
        while (op) {
            auto node = new ListNode(op->getItem());
            if (p) {
                p->setNext(node);
                p = node;
            }
            else {
                h = node;  // if first, both head and tail <- node
                p = node;
            }
            op = op->getNext();
        }
        head = h; tail = p;
        count = other.count;
    }

}