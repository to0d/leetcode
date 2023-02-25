#!/usr/bin/rs

(load "tool")
(load "map")
(load "opt")
(load "test/pt_help")

(defun longestPalindrome ((?s string))

    (defvar ?len (length-of ?s))
    (if (= ?len 0) 
        (return ?s)
    )
    
    (defvar ?maxPos 0)
    (defvar ?maxWth 1)
    
    (loop for ?i from 1 to (- ?len 1) do
        (loop for ?j from 0 to 1 do
            (defvar ?d (/ (+ ?maxWth 1) 2))
            (defvar ?lx (- ?i ?d))
            (defvar ?ly)
            
            (if (= ?j 0)
                (setq ?ly (- (+ ?i ?d) 1))  ;  even sequence
                (setq ?ly (+ ?i ?d))        ;  odd sequence
            )

            (if (or (< ?lx 0) (>= ?ly ?len))
                (continue)
            )
            
            (defvar ?llx ?lx)
            (defvar ?lly ?ly)
            
            (loop 
                (if (or (>= ?llx ?lly) (!= (str-char-at ?s ?llx)  (str-char-at ?s ?lly)))
                    (break)
                )
                (++ ?llx)
                (-- ?lly)
            )
            
            (if (< ?llx ?lly)
                (continue)
            )
  
            (setq ?maxPos ?lx)
            (setq ?maxWth (+ (- ?ly ?lx) 1)) 

            (loop 
                (-- ?lx)
                (if (< ?lx 0)
                    (break)
                )
                
                (++ ?ly)
                (if (> ?ly ?len)
                    (break)
                )

                (if (!= (str-char-at ?s ?lx)  (str-char-at ?s ?ly))
                    (break)
                )

                (-- ?maxPos)
                (setq ?maxWth (+ ?maxWth 2)) 
            )
        )
    )       
    
    (return (str-substr ?s ?maxPos ?maxWth))

)[opt-full]

(defun test ((?s string))
    (print "input: " ?s)
    (defvar ?r  (longestPalindrome ?s))
    (println "; output: " ?r ";" )
)

(test "babad")

(out_pt_summary)

