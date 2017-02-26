This file contains additional implementation details for Binary Search Tree and Kd Tree.

The difference in implementation of BST and KD tree lies in considering the dimension in kd unlike BST.
In BST tree implementation we are free to find the min in right tree or max in left sub tree. We then
replace the root with that node and recursively go for deletion of the root.

In KD tree deletion we have to pass depth parameter for search and deletion operation since we donot
know if the required node lies in the left subtree or right subtree

If the current dimension is same as to be searched node , we are sure that the node only lies to the left of 
the tree. Otherwise we need to traverse in both the directions.
For KD tree deletion we check the min element in the right subtree in the same dimenion.
We then recursively delete the node in the right tree.
If the right tree is null, we find minimum in the left tree , we then swap the left and right trees
We perform the deletion of node in the let subtree and assign it to th right child. We then make
the left child null. This completes the swaping of trees and deletion of nodes if the right child is null.

For searching in the kdtree if the current node is in the same dimension as the node to be searched , we only traversal
in one direction based on key value is greater or less.The bst implementation is straight forward i.e., same as kd tree but just ignore the dimension factor.



