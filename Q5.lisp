(defun split (aList)
  (list (split-before aList (/ (list-length aList) 2)) (split-after aList (/ (list-length aList) 2)))) ;splits list with split-before and split-after;& takes a position variable depending of the (/ length 2)
  
;split-before function
(defun split-before (aList position)
    (cond
     ((<= position 0) ()) ;base case
     ((null aList) aList)
     (t (cons (car aList) (split-before (cdr aList) (1- position)))))) ;recursively calls the function and (- position 1)

;split-after function
(defun split-after (aList position)
    (cond
     ((<= position 0) aList) ;base case
     ((null aList) ())
     (t (split-after (cdr aList) (1- position))))) ;recursively calls the function and (- position 1)
     
(print (split '(1 2 3 4)))
(print (split '(1 2 3 4 5)))
(print (split '(1 (2 3) 4 5 6)))
