/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/
#include <string.h>

void decode_huff(node * root,string s)
{
    int len = s.length();
    node * cur = new node;
    cur = root;
    for (int i = 0; i < len; i++) {
        if (s[i]) {
            if (s[i] == '1') {
                cur = cur->right;
            }
            if (s[i] == '0') {
                cur = cur->left;
            }
            if (cur->left == NULL && cur->right == NULL) {
                cout << cur->data;
                cur = root;
            }
        }
    }
}
