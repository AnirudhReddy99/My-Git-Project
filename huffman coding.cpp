#include<bits/stdc++.h> 
using namespace std; 
struct MinHeapNode {
    char data; 
    unsigned f; 
    MinHeapNode *left, *right; 
    MinHeapNode(char data, unsigned f) { 
        left = right = NULL; 
        this->data = data; 
        this->f = f; 
    } 
}; 

struct compare { 
    bool operator()(MinHeapNode* left, MinHeapNode* right) { 
        return (left->f > right->f); 
    } 
}; 

void printCodes(struct MinHeapNode* root, string str) { 
  
    if (!root) 
        return; 
  
    if (root->data != '$') 
        cout << root->data << ": " << str << endl; 
  
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1"); 
} 
  
void HuffmanCodes(char data[], int f[], int size) { 
    struct MinHeapNode *left, *right, *top; 
  
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 
  
    for (int i = 0; i < size; ++i) 
        minHeap.push(new MinHeapNode(data[i], f[i])); 
  
    while (minHeap.size() != 1) { 
        left = minHeap.top(); 
        minHeap.pop(); 
        right = minHeap.top(); 
        minHeap.pop(); 
        top = new MinHeapNode('$', left->f + right->f); 
        top->left = left; 
        top->right = right; 
        minHeap.push(top); 
    } 
    printCodes(minHeap.top(), ""); 
} 
  
int main() { 
  
    char S[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int f[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(S) / sizeof(S[0]); 
  
    HuffmanCodes(S, f, size); 
  
    return 0; 
}
