(defun binary-search (aList)
    (cond 
        ((null aList) T) ;an empty list is is Binary Search Tree
        ((and (not (null (car (car (cdr aList))))) (< (car aList) (car (car (cdr aList))))) nil) ;the left sub-tree of a node has a key less than or equal to its parent node's key
        ((and (not (null (car (car (cdr (cdr aList)))))) (> (car aList) (car (car (cdr (cdr aList)))))) nil) ;the right sub-tree of a node has a key greater than to its parent node's key
        (t (and (binary-search (car (cdr aList))) (binary-search (car (cdr aList))))))) ;else apply binary-search on left and right subtree
   
(print(binary-search '(8 (3 (1 () ()) (6 (4 () ())(7 () ()))) (10 () (14 (13 () ()) ())))))
