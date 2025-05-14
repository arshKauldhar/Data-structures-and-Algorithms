#include <iostream>
#include<queue>
using namespace std;

class tnode {
public:
    int data;
    tnode* left;
    tnode* right;

    tnode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class qnode {
    public:
        tnode* node;
        qnode* next;

        qnode(tnode* n) {
            node = n;
            next = nullptr;
        }
};

class MyQueue {
private:
    int size;
    // class qnode {
    // public:
    //     tnode* node;
    //     qnode* next;

    //     qnode(tnode* n) {
    //         node = n;
    //         next = nullptr;
    //     }
    // };

    qnode* head;

public:
    MyQueue() {
        size = 0;
        head = nullptr;
    }
    tnode* dequeue() {
        if (!head) {
            return nullptr;
        }
        tnode* node = head->node;
        qnode* tmp = head;
        head = head->next;
        delete tmp;
        size--;
        return node;
    }
      void enqueue(tnode* node) {
        qnode* newNode = new qnode(node);
        if (!head) {
            head = newNode;
        }
        else {
            qnode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }
    int gtSize() {
        return size;
    }
};

class Bnt {
private:
    tnode* root;

    void inst(tnode* node, int data) {
        if (data < node->data) {
            if (node->left) {
                inst(node->left, data);
            }
            else {
                node->left = new tnode(data);
            }
        }
        else {
            if (node->right) {
                inst(node->right, data);
            }
            else {
                node->right = new tnode(data);
            }
        }
    }

    int srch(tnode* node, int data) {
        if (!node) {
            return 0;
        }
        if (node->data == data) {
            return 1;
        }
        if (data < node->data) {
            return srch(node->left, data);
        }
        else {
            return srch(node->right, data);
        }
    }
    void prOder(tnode* node, vector<int>& result) {
        if (node) {
            result.push_back(node->data);
            prOder(node->left, result);
            prOder(node->right, result);
        }
    }

    void iOder(tnode* node, vector<int>& result) {
        if (node) {
            iOder(node->left, result);
            result.push_back(node->data);
            iOder(node->right, result);
        }
    }

    void posOder(tnode* node, vector<int>& result) {
        if (node) {
            posOder(node->left, result);
            posOder(node->right, result);
            result.push_back(node->data);
        }
    }

    int hgt(tnode* node) {
        if (!node) {
            return 0;
        }

        MyQueue queue;
        queue.enqueue(node);
        int height = 0;

        while (queue.gtSize() > 0) {
            int num_of_nodes = queue.gtSize();

            while (num_of_nodes > 0) {
                tnode* current = queue.dequeue();
                if (current->left) {
                    queue.enqueue(current->left);
                }
                if (current->right) {
                    queue.enqueue(current->right);
                }
                num_of_nodes--;
            }

            height++;
        }

        return height - 1;
    }
public:
    Bnt() {
        root = nullptr;
    }

    void tinsert(int data) {
        if (!root) {
            root = new tnode(data);
        }
        else {
            inst(root, data);
        }
    }

    int search(int data) {
        return srch(root, data);
    }

    vector<int> tpreorder() {
        vector<int> result;
        prOder(root, result);
        return result;
    }

    vector<int> tinorder() {
        vector<int> result;
        iOder(root, result);
        return result;
    }

    vector<int> tpostorder() {
        vector<int> result;
        posOder(root, result);
        return result;
    }

    int getHeight() {
        return hgt(root);
    }
};

int main() {
    Bnt tree;
    int val;
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        tree.tinsert(val);
    }

    int value;
    cout << "Enter value to search\n ";
    cin >> value;
    int Result = tree.search(value);
    cout <<Result<< endl;
    int height = tree.getHeight();
    cout <<"height="<< height << endl;

    cout << "preorder traversal:";
    vector<int> preorderResult = tree.tpreorder();
    for (int val : preorderResult) {
        cout << " " << val;
    }
    cout << endl;

    cout << "inorder traversal:";
    vector<int> inorderResult = tree.tinorder();
    for (int val : inorderResult) {
        cout << " " << val;
    }
    cout << endl;

    cout << "postorder traversal:";
    vector<int> postorderResult = tree.tpostorder();
    for (int val : postorderResult) {
        cout << " " << val;
    }
    cout << endl;
return 0;
}