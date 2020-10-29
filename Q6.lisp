(defun root (tree)
        (car tree)) ;returns the root node of the binary tree

(defun left-subtree (tree)
    (car (cdr tree))) ;returns left subtree of the binary tree

(defun right-subtree (tree)
    (car (cdr (cdr tree)))) ;returns right subtree of the binary tree

(defun make-tree (root left right)
    (list root left right)) ;create a tree with a root node and with left/right subtrees

(defun insert-node (node tree)
    (cond 
        ((null tree) (make-tree node '() '())) ;if there is only 1 node in list, create a tree with a root node, and empty leafs for left and right of tree
        ((= node (root tree)) tree) ;if current value to insert is the same as the root of the current tree, ignore completely
        ((< node (root tree)) (make-tree (root tree) (insert-node node (left-subtree tree)) (right-subtree tree))) ;if current value is < than value of root of current subtree, create a tree with the current root node and insert into the left subtree, carrying on the right subtree
        ((> node (root tree)) (make-tree (root tree) (left-subtree tree) (insert-node node (right-subtree tree)))))) ;if current value is > than value of root of current subtree, create a tree with the current root node and insert into the right subtree, carrying on the left subtree
    
(defun make-cbtree (list)
    (dolist (node list) ;for each node in list
        (setf tree (insert-node node tree)))) ;set the value of tree to a tree which is going to be recursively created from our nodes
    
(setf tree nil) ;reset values
(make-cbtree '(8 3 10 1)) ;function call
(print tree) ;print result

(setf tree nil) ;reset values
(make-cbtree '(8 3 10 1 6)) ;function call
(print tree) ;print result
