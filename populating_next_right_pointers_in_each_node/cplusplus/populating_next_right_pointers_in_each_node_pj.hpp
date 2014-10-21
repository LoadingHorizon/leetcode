# include "treelinknode.h"

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *pre = NULL;
        TreeLinkNode *cur = NULL;
        
        while (root != NULL) {
			for (cur = root; pre != NULL; cur = cur->next) {
				cur->next = pre->right;
				pre = pre->next;
				cur = cur->next;
                if (pre == NULL) {
					break;
                } 
				cur->next = pre->left;
			}
			cur->next = NULL;
            pre = root;
			root = root->left;
        }
    }
};
