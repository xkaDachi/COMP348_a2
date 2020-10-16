(defun split (aList)
  (list (split-before aList (/ (list-length aList) 2)) (split-after aList (/ (list-length aList) 2))))
  
(defun split-before (aList position)
    (cond
     ((<= position 0) ())
     ((null aList) aList)
     (t (cons (car aList) (split-before (cdr aList) (1- position))))))
     
(defun split-after (aList position)
    (cond
     ((<= position 0) aList)
     ((null aList) ())
     (t (split-after (cdr aList) (1- position)))))
     
(print (split '(1 2 3 4)))
(print (split '(1 2 3 4 5)))
(print (split '(1 (2 3) 4 5 6)))
