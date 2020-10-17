; take the list and make a list of only atoms NO nested lists
(defun extract(alist)
    (cond ((null alist) '()) ; if alist is null return empty list
        ((listp (car alist)) (append (extract(car alist)) (extract(cdr alist)))) ; if head of alist is a list append to extract
        (t (cons (car alist)(extract(cdr alist)))) ; else construct list with all elements
    )    
) 

(defun flatten-numbers (alist)
    (setq list1 (extract alist)) ; create list1 with ONLY ELEMENTS
    (setq list2 '()) ; create list2
    (cond ((null list1) '()) ; if alist is empty return empty list
        (t (dotimes (x (length list1) list2) ; dotimes loop where limit is the length of list1 and the result is list2
            (if (or (member (car list1) list2) (not(numberp (car list1))))
                () ; if head is already a member of the list do nothing
                (setf list2 (append list2 (list (car list1))))) ; else put element in list2
            (setf list1 (cdr list1))) ; move on with the tail (take off the head and dotimes loop again)
        ))

)

(print (extract '((1 5) 6 2 4 g 5 h s (7 4) (4) 6))) ;test for extract
(print (flatten-numbers '((1 5) 6 2 4 g 5 h s (7 4) (4) 6))) ;test for flatten-numbers
