(deffacts initilzation
    (state 0)
    (path 0))

(defrule insert-quarter
    ?path-fact <- (path $?begin ?end)
    (test (<= (+ ?end 25) 55))
    (not (exists (state = (+ ?end 25))))
    =>
    (assert (state =(+ ?end 25)))
    (modify ?path-fact (path $?begin ?end = (+ ?end 25))))

(defrule insert-nickel
    ?path-fact <- (path $?begin ?end)
    (test (<= (+ ?end 5) 55))
    (not (exists (state = (+ ?end 25))))
     =>
    (assert (state =(+ ?end 5)))
    (modify ?path-fact (path $?begin ?end = (+ ?end 5))))

(defrule continue-search
  (state ?s)
  (test (neq ?s 55))
  =>
  (focus insert-quarter insert-nickel))

(defrule goal-reached
  (state 55)
  (path $?path)
  =>
  (printout t "Path: " $?path crlf)
  (halt))