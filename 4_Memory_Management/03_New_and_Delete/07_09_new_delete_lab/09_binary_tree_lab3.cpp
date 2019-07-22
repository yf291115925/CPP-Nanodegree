/*
LAB 3
Objectives 3
Binary tree's are data structures that have a hierarchical form and represent trees
whose elements have a maximum number of two children. These children are called the
left and the right child. The binary tree root represents the top node.
A node that has at least one child is considered a parent of its child.
A leaf is a node that has no children.

Steps 3
    Create class called binary_tree
    Create structure called node
    Declare 4 attributes in structure: integer data, two pointers to the same type of structure,called left and right
    Declare main pointer to structure node type called root
    This pointer is attribute of class binary_tree
    This pointer is going to containt all data related to binary tree trought connectin nodes
    Declare two methods called add and search
    Add needs to have logic which will be dependant from data attribute and check for its place of
        creation on left or right side
    Search needs to be implemented as recursive function
    Check for nullptr in search and call it again on fulfilled condition(< or >)
    First function doesn't have return type
    Second function indicates its success by sending boolean values
    Both class methods are wrappers for two private class method which are going to be implemented recursively for easier usage.
    Private functions are using another input parameter -> node pointer
    This is designed like this for passage of pointers ( left, right)
    Declare two constructors and destructors
    One of the constructor - destructor pair is going to be part of node structure
    Second pair is going to be of class
    Constructors in structure is used to declare new node (Pointers are NULL, data is set)
    Constructor in class is esentially wrapper for stucture constructor
    Structure destructor deletes left and right pointers
    Class destructor deletes root pointer
    Test everything in main
*/

#include <iostream>

class binary_tree{

private:

    struct node{
        int data;
        node *left;
        node *right;

        node(int initdata,node *leftN, node *rightN): left(leftN),right(rightN),data(initdata){}
        ~node(){
            if (left!=nullptr)
                delete left;
            if (right!=nullptr)
                delete right;
        }
    };

    //attribute section
    node *root;


    //function section
    void add(int newdata, node *ptr);
    bool search(int targetdata, node *ptr);


public:

    binary_tree(int rootdata){
        binary_tree::root = new node(rootdata,nullptr,nullptr);
    }

    ~binary_tree() {
        delete binary_tree::root;
    }
    void addData(int inputdata){
        binary_tree::add(inputdata,root);
    }
    bool searchItem(int item) {
        return binary_tree::search(item, binary_tree::root);
    }

    int getroot(){
        return root->data;
    }
};

bool binary_tree::search(int targetdata, node *ptr){


    //如果已經seraching 到 leaf 了還不是, 那就要勝負了
    if (ptr != nullptr && ptr->right ==nullptr && ptr->left==nullptr){
        if (targetdata == ptr->data){
            return true;
        }else{
            return false;
        }

    }

    //一般的node, 左右可能有一個是null 或兩邊都有其他node
    if (targetdata == ptr->data){
        return true;
    }else{
        //not found

        //searching to right
        if (targetdata > ptr->data && ptr->right !=nullptr){
            search(targetdata, ptr->right);
        }else if(targetdata < ptr->data && ptr->left !=nullptr){
            search(targetdata, ptr->left);

        }

    }



}


void binary_tree::add(int newdata, node *ptr){
    //題目沒說是binary SEARCH tree, 自己這邊就隨便訂
    //大於加右邊
    //小於等於加在左邊
    //recursive 往下走, 到底

    //right
    if (newdata > ptr->data){

        //看看是不是到底了
        if(ptr->right == nullptr){
            ptr->right = new node(newdata,nullptr,nullptr);
        }else{
        //右邊是node, 再進來確認一下
            binary_tree::add(newdata,ptr->right);
        }


    }else{
    //left, 上面相反而已
        if(ptr->left == nullptr){
            ptr->left = new node(newdata,nullptr,nullptr);
        }else{
            add(newdata,ptr->left);
        }

    }

}

int main() {
    binary_tree tree(2);
    tree.addData(10);
    tree.addData(1);
    tree.addData(20);
    tree.addData(0);

    std::cout<<tree.searchItem(0)<<std::endl;
    std::cout<<tree.searchItem(9)<<std::endl;
    tree.addData(11);
    std::cout<<tree.searchItem(11)<<std::endl;
    /* OUTPUT:
        1
        0
        1
    */

    std::cout<<tree.getroot()<<std::endl;
    return 0;
}
