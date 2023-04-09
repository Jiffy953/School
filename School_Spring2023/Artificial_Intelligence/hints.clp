; Define the template for the result
(deftemplate result (slot sum) (slot num25) (slot num5) (slot sequence))

; Add facts about the numbers
(deffacts numbers (number 25) (number 5))

; Define the rule to calculate the optimal sum using the least amount of coins
(defrule calculate-optimal-path
    (number ?n1)
    (number ?n2)
    (not (result (sum 55)))
=>
    (bind ?num25 (div 55 ?n1))
    (bind ?remainder (mod 55 ?n1))
    (bind ?num5 (div ?remainder ?n2))

    (bind ?sum (+ (* ?num25 ?n1) (* ?num5 ?n2)))
    (bind ?sequence "")
    (loop-for-count (?i 1 ?num25)
        (bind ?sequence (str-cat ?sequence "25 "))
    )
    (loop-for-count (?i 1 ?num5)
        (bind ?sequence (str-cat ?sequence "5 "))
    )
    (assert (result (sum ?sum) (num25 ?num25) (num5 ?num5) (sequence ?sequence)))
)

; Print the result
(defrule print-result
    ?r <- (result (sum ?sum) (num25 ?num25) (num5 ?num5) (sequence ?sequence))
=>
    (printout t "Optimal path of adding 25 and 5 using the least amount of coins to reach a total of 55:" crlf)
    (printout t ?sequence crlf)
    (printout t "Number of 25s: " ?num25 crlf)
    (printout t "Number of 5s: " ?num5 crlf)
    (retract ?r)
)
