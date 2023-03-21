(deffacts init)



(defrule op1
    path $?begin [?x ?y])
    (test (< ?x 4))
    (not (exists (state 4 ?y)))
    =>
    (assert (state 4 ?y))
    (assert (path $?begin [?x ?y] [4 ?y])))

(defrule op2
    path $?begin [?x ?y])
    (test (< ?x 3))
    (not (exists (state ?x 3)))
    =>
    (assert (state ?x 3))
    (assert (path $?begin [?x ?y] [?x 3])))

(defrule op3
    (path $?begin [?x ?y])
    (test (< ?x 4))
    (test (>= (+ ?x ?y) 4))
    (not (exists (state 4 =(-(+ ?x ?y)4))))
    =>
    (assert (state 4 =(- (+ ?x ?y)4)))
    (assert (path $?begin [?x ?y] [4 = (- (+ ?x ?y)4)])))
;holy shit why am i typing this out this sucks