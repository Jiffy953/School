;A program to calculate the optimal number of nickels and quarters and nickels to get to 55 cents
;Due 4/10/23
;Jared See


;Define the template for the result
(deftemplate result (slot sum) (slot quarter) (slot nickel))

;Define facts and value of each coin
(deffacts coins (coin 25) (coin 5))

;Define rule to find optimal sum of 25 and 5 to reach 55
(defrule calculate-optimal-path
    (coin ?n1)
    (coin ?n2)
    (not (result (sum 55)))
    =>
    (bind ?quarter (div 55 ?n1))
    (bind ?remainder (mod 55 ?n1))
    (bind ?nickel (div ?remainder ?n2))

    (if (and (= ?n1 25) (= ?n2 5))
        then
            (assert (result (sum 55) (quarter ?quarter) (nickel ?nickel)))))

;Define print function
(defrule print-result
    ?r <- (result (sum ?sum) (quarter ?quarter) (nickel ?nickel))
    =>
    (printout t "Number of 25s: " ?quarter crlf)
    (printout t "Number of 5s: " ?nickel crlf)
    (retract ?r)
    (halt))