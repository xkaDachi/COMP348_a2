(defun lucas (n &optional (a 2) (b 1))
  (if (minusp n) ;Lucas Sequence starts at '0'. ***If starts at '1', use (or (zerop n) (minusp n)) instead
      nil
      (cons a (lucas (- n 1) b (+ a b))))) ;construct a list recursively   ***(1- n) equivalent to (- n 1)

(print (lucas -1))
(print (lucas 0))
(print (lucas 1))
(print (lucas 2))
(print (lucas 3))
(print (lucas 4))
(print (lucas 5))
(print (lucas 6))
(print (lucas 7))
(print (lucas 8))
(print (lucas 9))
(print (lucas 10))
