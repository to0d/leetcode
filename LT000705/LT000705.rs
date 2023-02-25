#!/usr/bin/rs

(load "tool")
(load "opt")
(load "limits")
(load "test/pt_help")

(defun my_reverse ((?x int))
    (if (= ?x int_min) (return 0))
    (if (< ?x 0) (return (- 0 (my_reverse (- 0 ?x)))))
    (defvar ?r 0)
    (loop 
        (if (= ?x 0) (break))
        (setq ?r (+ (* 10 ?r) (% ?x 10)))
        (setq ?x (/ ?x 10))
    )
    (return ?r)

)[opt-full]

(defun test ((?x int))
    (print "input: " ?x)
    (defvar ?r  (my_reverse ?x))
    (println "; output: " ?r ";" )
)

(test 12345)

(out_pt_summary)

