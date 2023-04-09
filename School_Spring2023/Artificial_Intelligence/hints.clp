; Define templates to hold the state and path
(deftemplate state
  (slot value))

(deftemplate path
  (slot value)
  (slot coins))

; Clear working memory and assert initial facts
(clear)
(assert (state (value 0)))
(assert (path (value 0) (coins "")))

; Rule to insert a quarter
(defrule insert-quarter
  ?path-fact <- (path (value ?end) (coins ?coins))
  (test (<= (+ ?end 25) 55))
  (not (exists (state (value (+ ?end 25)))))
  =>
  (assert (state (value (+ ?end 25))))
  (modify ?path-fact (value (+ ?end 25)) (coins (str-cat ?coins "quarter, "))))

; Rule to insert a nickel
(defrule insert-nickel
  ?path-fact <- (path (value ?end) (coins ?coins))
  (test (<= (+ ?end 5) 55))
  (not (exists (state (value (+ ?end 5)))))
  =>
  (assert (state (value (+ ?end 5))))
  (modify ?path-fact (value (+ ?end 5)) (coins (str-cat ?coins "nickel, "))))

; Rule to print the result when the state reaches 55 cents
(defrule print-result
  (state (value 55))
  ?path-fact <- (path (value 55) (coins ?coins))
  =>
  (printout t "Optimal way to purchase a soft drink: " crlf)
  (printout t "Insert the coins in the following order: " ?coins crlf))

; Run the rule engine
(reset)
(run)
