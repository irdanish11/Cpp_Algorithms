#include <iostream>
#include <assert.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    public:
        //holds the number of nodes in the linked list
        int size;
        //current node position of the current pointer.
        int pos;
        Node* current = NULL;
        Node* head = NULL;
        Node* tail = NULL;
        void append(int val);
        void insert(int idx, int val);
        void printList();
        void deleteNode(int idx);
        int traverseList(int idx, bool verbose);
    
    //adding single node linked list with tail and head
    LinkedList(int val){
        head = new Node;
        current = new Node;
        current->data = val;
        tail = new Node;
        head->next = current;
        current->next = tail;
        //one node is added to the linked list.
        size = 1;
        pos = 0;
    }

    private:
        Node* create_node(int val);
};

Node* LinkedList::create_node(int val){
    Node* node1 = NULL;
    node1 = new Node;
    node1->data=val;
    return node1;
}

void LinkedList::append(int val){
    Node* node2 = create_node(val);
    node2->next = tail;
    current->next = node2;
    current = node2;
    size++;
    pos = size;
}

void LinkedList::insert(int idx, int val){
    //Segmentation fault (core dumped): Trying to access memory that does not belong to the program, i.e. insertion index out of bound!
    assert(idx<=size+1);
    //making the head as current pointer.
    current = head;
    for(int i=0; i<idx; i++){
        current = current->next;
    }
    //create the node
    Node* node3 = create_node(val);
    //pointing the next pointer to the location where current node's next pointer was pointing
    node3->next = current->next;
    //joining the old current node with newly created node
    current->next = node3;
    //making newly inserted node as current node
    current = node3;
    size++;
    pos=idx;
}

void LinkedList::printList(){
    Node* tmp = NULL;
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

void LinkedList::deleteNode(int idx){
    Node* tmp = NULL;
    Node* tmp1 = NULL;
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

int LinkedList::traverseList(int idx, bool verbose){
    current = head->next;
    for(int i=0; i<idx; i++){
        current = current->next;
    }
    if(verbose)
        cout<<"The value at index "<<idx<<" is: "<<current->data<<endl;
    return current->data;
}

int main(){
    LinkedList* list; 
    list = new LinkedList(18);
    //appending to list
    list->append(5);
    list->append(56);
    //inserting to list
    list->insert(3, 125);
    list->insert(2, 289);
    //print the contents of the list.
    list->printList();
    //delete a node
    list->deleteNode(2);
    cout<<"\nSize: "<<list->size<<"\tCurrent Position: "<<list->pos<<endl;
    //print the contents of the list.
    list->printList();
    //reterive an element from the list by index
    int ret = list->traverseList(3, true);
    return 0;
}