#!/usr/bin/rs

(load "opt")
(load "test/pt_help")

(defun isHappy ((?n int))
    
    (if (<= ?n 0) (return false))
    (if (= ?n 1) (return true))

    (defvar ?n2 0)
    (defvar ?x)
    (loop 
        (if (<= ?n 0) 
            (break))
        (setq ?x (% ?n 10))
        (setq ?n (/ ?n 10))
        (setq ?n2 (+ ?n2 (power ?x 2)))
    )
    
    (try 
        (return (isHappy ?n2))
        (catch ?e (return false))
    )
)[opt-full]

(defun test ((?n int))
    (print "input: " ?n)
    (defvar ?r  (isHappy ?n))
    (println "; output: " ?r ";" )
)

(test 19)
(test 1999999999)

(out_pt_summary)

