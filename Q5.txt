(defun binary-search (aList)
    (cond 
        ((null aList) T)
        ((and (not (null (car (car (cdr aList))))) (< (car aList) (car (car (cdr aList))))) nil)
        ((and (not (null (car (car (cdr (cdr aList)))))) (> (car aList) (car (car (cdr (cdr aList)))))) nil)
        (t (and (binary-search (car (cdr aList))) (binary-search (car (cdr aList)))))))
    


(print(binary-search '(8 (3 (1 () ()) (6 (4 () ())( 7 () ()))) (10 (()) (14 (13) ())))))
