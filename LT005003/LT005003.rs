#!/usr/bin/rs

(load "opt")
(load "test/pt_help")

(defun myPow ((?x double) (?n int))
    (if (or (= ?n 0) (= ?x 1d)) (return 1))
    (if (= ?n -2147483648) (return (/ 1.0 (* ?x (myPow ?x 2147483647)))))
    (if (< ?n 0) (return (/ 1.0 (myPow ?x (- 0 ?n)))))
    (return (* ?x (myPow ?x (- ?n 1))))
)[opt-cco]

(defun test ((?x double) (?n int))
    (print "input: x=" ?x ", n=" ?n)
    (defvar ?r  (myPow ?x ?n))
    (println "; output: " ?r ";" )
)

(test 2.0d 10)

(out_pt_summary)

