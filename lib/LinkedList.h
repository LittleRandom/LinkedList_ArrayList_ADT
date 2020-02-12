//
// Class that implements a singly-linked list of Items, with iterator.
// ECE 309 - Spring 2020
//

#ifndef ECE309_SPR20_LINKEDLIST_H
#define ECE309_SPR20_LINKEDLIST_H

#include "Item.h"

namespace ece309 {

    class LinkedList {
    private:
        // ListNode class to hold items in the list
        class ListNode {
        private:
            StringItem item;
            ListNode * next;
        public:
            // node takes ownership of a -- will delete in destructor
            ListNode(const StringItem& a, ListNode* n = nullptr) : item(a), next(n) { }
            ListNode * getNext() { return next; }
            void setNext(ListNode *ptr) { next = ptr; }
            StringItem getItem() const { return item; } // returns a copy of the item
        };

        // head and tail pointers
        ListNode* head;
        ListNode* tail;
        size_t count;

    public:
        // iterator class to traverse list nodes
        class iterator {
        private:
            ListNode *node;   // points to a specific node in the list
        public:
            iterator(ListNode* n = nullptr) { node = n; }  // constructor
            StringItem getItem() const { return node->getItem(); }
            void increment() { node = node->getNext(); }
            bool end() { return node == nullptr; }
            friend class LinkedList;
        };

        LinkedList() : head(nullptr), tail(nullptr), count(0) {}
        LinkedList(const LinkedList&);  // copy constructor
        LinkedList& operator=(const LinkedList&);  // assignment
        ~LinkedList();
        bool empty() const;
        size_t size() const { return count; }
        void push_back(const StringItem& a);  // makes a copy of data item
        void push_front(const StringItem& a);
        void insertAfter(iterator, const StringItem&);
        bool pop_back(StringItem& a);  // returns a copy of the item
        bool pop_front(StringItem& a);
        bool removeAfter(iterator, StringItem&);

        iterator begin() { return iterator(head); }

    private:
        void delete_helper();  // helper functions for copy, assign, delete
        void copy_helper(const LinkedList&);
    };

}

#endif //ECE309_SPR20_LINKEDLIST_H
