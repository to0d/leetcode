#!/usr/bin/rs

(load "tool")
(load "opt")
(load "test/pt_help")

; f(n) = max( Vn+f(n-2), f(n-1))
;      = V1                 n = 1
;      = max(V1,V2)         n = 2
; 
; 

(defun rob ((?nums list))

    (defvar ?n (size-of ?nums))
    
    (case ?n
        (0 (return 0))
        (1 (return (get ?nums 0)))
        (2 (return (max (get ?nums 0) (get ?nums 1))))
    )
    
    (defvar ?a (get ?nums 0))
    (defvar ?b (max (get ?nums 0) (get ?nums 1)))
    (defvar ?c)

    (loop for ?i from 2 to (- ?n 1) do
        (setq ?c (max ?b (+ (get ?nums ?i) ?a)))
        (setq ?a ?b)
        (setq ?b ?c)
    )
    
    (return ?b)
 
)[opt-full]

(defun test ((?nums list)) 
    (print "input: " ?nums)
    (defvar ?r  (rob ?nums))
    (println "; output: " ?r ";" )
)

(test '(2 7 9 3 1))

(out_pt_summary)

