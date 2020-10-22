;sub-list function
(defun sub-list (listInput &optional (fromIndex 1) (toIndex (myLength listInput)))   ;default variables with &optional
  (if (null fromIndex) (setq fromIndex 1))                                           ;if fromIndex is null, make it (1)

  (if (or (> fromIndex (myLength listInput)) (> toIndex (myLength listInput))) nil   ;indexes cannot be out of bounds & calling this here because myLength will change in each recursive calls
    (if (> fromIndex toIndex)
        (reverse (assist-sub-list listInput toIndex fromIndex 1)) ;reverse helper function
        (assist-sub-list listInput fromIndex toIndex 1))))  ;helper function               

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

(print (sub-list '(1 6 12) 2 3))         ;from assignment Q1
(print (sub-list '(1 6 12) 2))           ;from assignment Q1 but removed toIndext so defaults to (myLength inputList)
(print (sub-list '(1 6 12) nil 3))       ;from assignment Q1 but removed fromIndex so defaults to (1)
(print (sub-list '(1 6 12)))             ;from assignment Q1 but removed both fromIndex and toIndex so defaults to (1) and (myLength inputList)

(print (sub-list '(1 6 12) 2))          ;from assignment Q2
(print (sub-list '(1 6 12) 3 1))        ;from assignment Q2
(print (sub-list '(1 6 12) nil 1))      ;from assignment Q2

