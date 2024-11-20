/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
#include <climits>
bool isBSTUtil(Node* node, int minVal, int maxVal) {
    if (!node) {
        return true; 
    }

    if (node->data <= minVal || node->data >= maxVal) {
        return false;
    }

    return isBSTUtil(node->left, minVal, node->data) &&
           isBSTUtil(node->right, node->data, maxVal);
}

bool checkBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}