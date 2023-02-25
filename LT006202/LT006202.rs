#!/usr/bin/rs

(load "opt")
(load "test/pt_help")

; f(m,n) = f(m-1,n) + f(m,n-1)
; f(m,n) = f(n,m)
; f(1,n) = 1

(defun uniquePaths (m n)
    (if (or (= m 0) (= n 0)) (return 0))
    (if (< m n) (return (uniquePaths n m)))
    (if (= n 1) (return 1))
    (return (+ (uniquePaths (- m 1) n) (uniquePaths m (- n 1))))
)[opt-cco]

(defun test ((?m int) (?n int))
    (print "input: m=" ?m ", n=" ?n)
    (defvar ?r  (uniquePaths ?m ?n))
    (println "; output: " ?r ";" )
)

(test 3 7)
(test 30 30)

(out_pt_summary)

