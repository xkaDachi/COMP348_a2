(defun triangle(n)
    (if (integerp n) ;if an integer, determine the sign 
          (if (zerop n) ;if this is a zero
              (write-line "invalid number; please enter a positive or a negative integer")
              (if (> n 0) ;if this input is positive
               (loop for a from 1 to n
                   do (loop for b from a to n
                       do (write '*)
                            )
                    (write-line "")) ;new line
                 ;else this input is negative
                (loop for a from n to -1
                   do ;print out the space as one line frist
                     (loop for b from (+ n 1) to a
                       do (princ #\space))
                      ;then print out the stars
                    (loop for b from a to -1
                       do (write '*))
                    (write-line"")) ;new line
                )
         )
         (write-line "invalid number; please enter a positive or a negative integer"))) ;else not an integer

(triangle 7)
(triangle 4)
(triangle -5)
(triangle 1)
(triangle -1)

(triangle 0)
(triangle 2.5)
(triangle '(Hello World!))
