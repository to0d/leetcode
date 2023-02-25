#!/usr/bin/rs

(load "tool")
(load "opt")
(load "test/pt_help")

(defconst ?blk (str-char-at " " 0))
(defconst ?plus (str-char-at "+" 0))
(defconst ?minus (str-char-at "-" 0))
(defconst ?c0 (str-char-at "0" 0))
(defconst ?c9 (str-char-at "9" 0))

(defun isdigit ((?c int))
    (return (and (>= ?c ?c0) (<= ?c ?c9)))
)

(defun myAtoi ((?str string))

    (defvar ?len (length-of ?str))
    (defvar ?pos 0)
    (defvar ?n 0)
    (defvar ?c 0)
    (defvar ?sign ?plus)
    (defvar ?res 0L)
    (defvar ?over 0L)
    
    ; skip white space
    (loop 
        (if (or (>= ?pos ?len) (!= (str-char-at ?str ?pos) ?blk))
            (break)
        )
        (++ ?pos)
    )
    
    (if (< ?pos ?len) do
        (setq ?c (str-char-at ?str ?pos))
        (if (or (= ?c ?plus) (= ?c ?minus)) do
            (setq ?sign ?c)
            (++ ?pos)
        )
    )

    (if (= ?sign ?plus)
        (setq ?over 2147483647L)    ; INT_MAX (2147483647)
        (setq ?over 2147483648L)    ; INT_MIN (-2147483648)
    )

    (loop 
        (if (>= ?pos ?len)
            (break)
        )

        (setq ?c (str-char-at ?str ?pos))
        (if (not (isdigit ?c))
            (break)
        )
        
        (setq ?res (+ (* ?res 10) (- ?c ?c0)))
        (++ ?n)
        
        (if (> ?res ?over) do
            (if (= ?sign ?plus)
                (return int_max)
                (return int_min)
            )
        )
        
        (++ ?pos)
    )
    
    (if (= ?n 0)
        (return 0)
    )

    (if (= ?sign ?plus)
        (return ?res)
        (return (- 0 ?res))
    )

)[opt-full]

(defun test ((?s string))
    (print "input: " ?s)
    (defvar ?r  (myAtoi ?s))
    (println "; output: " ?r ";" )
)

(test "12345")

(out_pt_summary)
