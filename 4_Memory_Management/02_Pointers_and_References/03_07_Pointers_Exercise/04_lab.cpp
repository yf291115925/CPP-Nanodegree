/*
Doubly linked lists
Doubly linked list is a type of data structure that is made up of so called objects
that are created using self referential structures. Each of these nodes contain three
attributes, namely the value and the reference to the next list object and the reference
to the previous list object.

Because the list is linked in both directions, any node has the ability to access any
other node. That means that the user of a doubly linked list need only keep track of
a single node.

The last node in the list points forward to nothing, which can be represented by nullptr.
The same is true for the first node in the list, which points backward to nothing.

In this exercise you will create a doubly linked list, which exposes 4 methods:

    push_back(): add values to the end of the list
    push_front(): add values to the beginning to the list
    pop_back(): delete values from the end of the list
    pop_front(): delete values from the front of the list

Also, you will implement a helper function, empty(), which returns whether or not
the list has any nodes.

Steps
    Declare class List to represent the doubly linked list
    Declare struct Node to represent the nodes in the list
    Declare a constructor for struct Node
    Declare a member variable head that belongs to class List and points to the first node in the list
    Declare a member variable head that belongs to class List and points to the first node in the list
    Declare a constructor for the doubly linked list
    Declare a destructor for class List
    Implement the class List destructor to delete all of the nodes in the list
    Declare List::PushFront() to push nodes onto the front of the list
    Declare List::PushBack() to push nodes onto the back of the list
    Declare List::PopFront() to delete nodes from the front of the list
    Declare List::PopBack() to delete nodes from the back of the list
    Declare List::Size() to count the number of nodes in the list
    Test that all member functions in class List behave properly, even if the list is empty

*/
#include <iostream>
#include <assert.h>
#include <string>
//in template


template<class T>
class Node {
public:

    Node(T val, Node *prev_node, Node *next_n):
        value(val), previous_node(prev_node),next_node(next_n){}
//private:
    T value;
    Node *previous_node;
    Node *next_node;
};

template<class T>
class List{

public:
    List(): head(nullptr), tail(nullptr){}
    ~List();

    void PushFront(T);
    void PushBack(T);
    T PopFront();
    T PopBack();
    bool Empty() const { return (head == nullptr);}
    int Size() const;

private:

    Node<T> *head;
    Node<T> *tail;

};

template<class T>
List<T>::~List(){
    //其實可以直接用 head, 不用加 List<T>, 因為是在自己的class function 中
    while ( List<T>::head != nullptr ){
        Node<T> *tmp =  List<T>::head;
        List<T>::head = List<T>::head->next_node;
        delete tmp;
    }

}


template<class T>
void List<T>::PushBack(T val){

     List<T>::tail = new Node<T>(val,List<T>::tail,nullptr);

     if (List<T>::head == nullptr){
         List<T>::head = List<T>::tail;
     }else{
         List<T>::tail->previous_node->next_node = List<T>::tail;
     }

}

template<class T>
void List<T>::PushFront(T val){
    head = new Node<T>(val, nullptr, head);

    if (tail == nullptr){
        tail = head;
    }else{
        head->next_node->previous_node = head;
    }
}

template<class T> int List<T>::Size() const{
    int count = 0;
    Node<T> *tmp = head; // copy head to tmp
    //Node<T> *tmp(List<T>::head);
    //std::cout << "tmp addr:" << &tmp <<", head addr: "<< &head << std::endl;
    std::string rst = "";
    while(tmp !=nullptr){
        rst = rst +  std::to_string(tmp->value) +", ";
        tmp = tmp->next_node;
        count++;
    }
    //std::cout << "End tmp val:" << tmp <<", head val: "<<head << std::endl;
    std::cout << rst << std::endl;
    return count;
}



template<class T>
T List<T> :: PopFront(){

    if (List::Empty())
        throw("Cannot List::PopBack() when List::Empty()");

    Node<T> *tmp = List<T>::head;
    T value = tmp->value;
    //移動head 往右
    head = head ->next_node;

    //如果移動到head 還是在某個node上
    //直接把前面的設成null 即可, 反正等下tmp還指著它, 會被del
    if(head != nullptr){
        head->previous_node = nullptr;
    }else{
    //如果head 移動後現在是 Null, 代表, 剛剛他在tail上
    //且等下這個tail也會被刪除, 因此, 把tail set to Null
        //head at the same place as tail, we del the front
        //which means there are no more node
        tail = nullptr;
    }

    delete tmp;
    return value;

}

template<class T>
T List<T>::PopBack(){

    if (List::Empty())
        throw("Cannot List::PopBack() when List::Empty()");

    Node<T> *tmp = tail;
    T value = tail->value;
    tail = tail->previous_node;

    if (tail != nullptr){
        tail->next_node = nullptr;
    }else{
        head = nullptr;
    }

    delete tmp;
    return value;

}




int main() {
  // Sanity test
  List<int> list1;

  list1.PushBack(9);
  std::cout << "Size() = " << list1.Size() << std::endl;
  assert(list1.Size() == 1);

  // Deeper test
  List<int> list2;
  list2.PushFront(9);
  list2.PushBack(10);
  assert(list2.Size() == 2);

  list2.PushBack(15);
  list2.PushFront(2);
  std::cout << "Size() = " << list2.Size() << std::endl;

  assert(list2.PopFront() == 2);
  std::cout << "list2.PopFront() = " << list2.PopFront() << std::endl;
  std::cout << "Size() = " << list2.Size() << std::endl;


  assert(list2.PopBack() == 15);
  assert(list2.Size() == 1);

}
