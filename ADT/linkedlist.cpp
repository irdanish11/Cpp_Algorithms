/*
    @author: Danish
    Generalized Singly Linked List Implementation using head & tail pointers, you can it on any Datatype.
*/

#include <iostream>
#include <assert.h>
using namespace std;

template <typename T1>
class Node{
    public:
        T1 data;
        Node* next;
};

template <typename T>
class LinkedList{
    public:
        //T *ptr;
        //holds the number of nodes in the linked list
        int size;
        //current node position of the current pointer.
        int pos;
        Node<T>* current = NULL;
        Node<T>* head = NULL;
        Node<T>* tail = NULL;
        LinkedList(T val);
        void append(T val);
        void insert(int idx, T val);
        void printList();
        void deleteNode(int idx);
        T traverseList(int idx, bool verbose);



    private:
        Node<T>* create_node(T val);
};

//Constructor: adding single node linked list with tail and head
template <typename T>
LinkedList<T>::LinkedList(T val){
    head = new Node<T>;
    current = new Node<T>;
    current->data = val;
    tail = new Node<T>;
    head->next = current;
    current->next = tail;
    //one node is added to the linked list.
    size = 1;
    pos = 0;
}

template <typename T>
Node<T>* LinkedList<T>::create_node(T val){
    Node<T>* node1 = NULL;
    node1 = new Node<T>;
    node1->data=val;
    return node1;
}

template <typename T>
void LinkedList<T>::append(T val){
    Node<T>* node2 = create_node(val);
    node2->next = tail;
    current->next = node2;
    current = node2;
    size++;
    pos = size;
}

template <typename T>
void LinkedList<T>::insert(int idx, T val){
    //Segmentation fault (core dumped): Trying to access memory that does not belong to the program, i.e. insertion index out of bound!
    assert(idx<=size+1);
    //making the head as current pointer.
    current = head;
    for(int i=0; i<idx; i++){
        current = current->next;
    }
    //create the node
    Node<T>* node3 = create_node(val);
    //pointing the next pointer to the location where current node's next pointer was pointing
    node3->next = current->next;
    //joining the old current node with newly created node
    current->next = node3;
    //making newly inserted node as current node
    current = node3;
    size++;
    pos=idx;
}

template <typename T>
void LinkedList<T>::printList(){
    Node<T>* tmp = NULL;
    tmp = head->next;
    cout<<"\n[";
    for(int i=0; i<size; i++){
        cout<<tmp->data;
        if(i+1<size)
            cout<<", ";
        tmp = tmp->next;
    }
    cout<<"]\n"<<endl;
}

template <typename T>
void LinkedList<T>::deleteNode(int idx){
    Node<T>* tmp = NULL;
    Node<T>* tmp1 = NULL;
    tmp1 = head->next;
    int count = 0;
    for(int i=0; i<idx-1; i++){
        tmp1 = tmp1->next;
        count++;
    }
    //this tmp node is the node that we will delete
    tmp = tmp1->next;
    //linking pointer of previous node to the next node, imagine as a skip connection
    tmp1->next = tmp->next;
    //making the node that was behind the node that we are going to delete as current node.
    current = tmp1;
    delete tmp;
    size--;
    pos=count;
}

template <typename T>
T LinkedList<T>::traverseList(int idx, bool verbose){
    current = head->next;
    for(int i=0; i<idx; i++){
        current = current->next;
    }
    if(verbose)
        cout<<"The value at index "<<idx<<" is: "<<current->data<<endl;
    return current->data;
}

int main(){
    //Substiute any data type in place of <string> on line 137-138, e.g to <int>, <bool> etc.
    LinkedList<string>* list; 
    list = new LinkedList<string>("hello");

    //Also chnage the datat according to teh above mentioned datatype.
    //appending to list
    list->append("world");
    list->append("C++");
    cout<<list->current->data<<endl;
    //inserting to list
    list->insert(3, "Python");
    list->insert(2, "C");
    //print the contents of the list.
    list->printList();
    //delete a node
    list->deleteNode(2);
    cout<<"\nSize: "<<list->size<<"\tCurrent Position: "<<list->pos<<endl;
    //print the contents of the list.
    list->printList();
    //reterive an element from the list by index
    string ret = list->traverseList(3, true);
    return 0;
}