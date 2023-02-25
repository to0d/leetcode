#!/usr/bin/rs

(load "tool")
(load "map")
(load "opt")
(load "test/pt_help")

(defun twoSum ((?nums list) (?target int))

    (defvar ?n (size-of ?nums))
    (new map _map)

    (loop for ?i from 0 to (- ?n 1) do

        (defvar ?v (get ?nums ?i))
        
        (if (_map::has-key ?v) 
            (return '((_map::get ?v) ?i))
        )
        
        (_map::put (- ?target ?v) ?i)
    )
    
    (return '())

)[opt-full]

(defun test ((?nums list) (?target int))  
    (print "input: num=" ?nums ", target=" ?target)
    (defvar ?r (twoSum ?nums ?target))
    (println "; output: " ?r ";" )
)

(test '(2 7 11 15) 9)

(out_pt_summary)