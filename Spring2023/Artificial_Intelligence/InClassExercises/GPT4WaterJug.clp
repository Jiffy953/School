; Define the template for the state
(deftemplate state
  (slot jug-x)
  (slot jug-y))

; Define the initial state
(deffacts initial-state
  (state (jug-x 0) (jug-y 0)))

; Rule 1: Fill Jug X
(defrule fill-jug-x
  ?s <- (state (jug-x ?x) (jug-y ?y))
  =>
  (retract ?s)
  (assert (state (jug-x 3) (jug-y ?y))))

; Rule 2: Fill Jug Y
(defrule fill-jug-y
  ?s <- (state (jug-x ?x) (jug-y ?y))
  =>
  (retract ?s)
  (assert (state (jug-x ?x) (jug-y 4))))

; Rule 3: Empty Jug X
(defrule empty-jug-x
  ?s <- (state (jug-x ?x&:(> ?x 0)) (jug-y ?y))
  =>
  (retract ?s)
  (assert (state (jug-x 0) (jug-y ?y))))

; Rule 4: Empty Jug Y
(defrule empty-jug-y
  ?s <- (state (jug-x ?x) (jug-y ?y&:(> ?y 0)))
  =>
  (retract ?s)
  (assert (state (jug-x ?x) (jug-y 0))))

; Rule 5: Pour from Jug X to Jug Y
(defrule pour-from-x-to-y
  ?s <- (state (jug-x ?x&:(> ?x 0)) (jug-y ?y))
  (test (<= (+ ?x ?y) 4))
  =>
  (retract ?s)
  (assert (state (jug-x 0) (jug-y (+ ?x ?y)))))

; Rule 6: Pour from Jug Y to Jug X
(defrule pour-from-y-to-x
  ?s <- (state (jug-x ?x) (jug-y ?y&:(> ?y 0)))
  (test (<= (+ ?x ?y) 3))
  =>
  (retract ?s)
  (assert (state (jug-x (+ ?x ?y)) (jug-y 0))))

; Rule 7: Pour from Jug X to Jug Y, with Jug Y as the limiting factor
(defrule pour-from-x-to-y-limited
  ?s <- (state (jug-x ?x&:(> ?x 0)) (jug-y ?y))
  (test (> (+ ?x ?y) 4))
  =>
  (retract ?s)
  (assert (state (jug-x (- ?x (- 4 ?y))) (jug-y 4))))

; Rule 8: Pour from Jug Y to Jug X, with Jug X as the limiting factor
(defrule pour-from-y-to-x-limited
  ?s <- (state (jug-x ?x) (jug-y ?y&:(> ?y 0)))
  (test (> (+ ?x ?y) 3))
  =>
  (retract ?s)
  (assert (state (jug-x 3) (jug-y (- ?y (- 3 ?x))))))
  
; Rule 9: Print the goal state
(defrule goal-state
  (state (jug-x ?x) (jug-y 2))
  =>
  (printout t "Goal state: (" ?x ", " 2 ")" crlf))

; Run the program
(reset)
(run)