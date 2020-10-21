;sub-list function
(defun sub-list (listInput fromIndex toIndex)
  (if (or (> fromIndex (myLength listInput)) (> toIndex (myLength listInput))) nil  ;indexes cannot be out of bounds 
    (assist-sub-list listInput fromIndex toIndex 1))) ;helper function               & calling this here because myLength will change in each recursive calls
    
;user-defined length function
(defun myLength (aList)
  (if aList
    (+ 1 (myLength (cdr aList)))
    0))
  
;helper function
(defun assist-sub-list (listInput fromIndex toIndex position)
  (if (or (< fromIndex 1) (< toIndex 1)) nil ;indexes can't be negative 
      (if (> fromIndex toIndex) nil ;fromIndex can't be higher than toIndex
         (if (< position fromIndex) ;ignores until we reach fromIndex
             (assist-sub-list (cdr listInput) fromIndex toIndex (+ position 1))
             (if (<= position toIndex) ;construct a list from fromIndex to toIndex
                (cons (car listInput) (assist-sub-list (cdr listInput) fromIndex toIndex (+ position 1)))))))) ;recursive call

;test cases
(print (sub-list '(1 6 12) 2 3)) ;from assignment
(print (sub-list '(1 6 12) 1 2)) ;from assignment
(print (sub-list '(1 6 12) 1 3)) ;from assignment
(print (sub-list '(1 6 12) 4 2)) ;from assignment
(print (sub-list '(1 6 12) 0 2)) ;can't be zero
(print (sub-list '(1 6 12) 3 2)) ;fromIndex > toIndex
(print (sub-list  '(1 6 12) -3 3)) ;fromIndex is negative
(print (sub-list '(1 6 12) 4 -2)) ;toIndex is negative
(print (sub-list '(1 6 12) 10 2)) ;fromIndex can't be out of bounds, can't be > 3
(print (sub-list '(1 6 12) 1 10)) ;toIndex can't be out of bounds, can't be > 3
