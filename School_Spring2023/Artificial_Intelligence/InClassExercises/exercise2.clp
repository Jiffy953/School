;fact base
(deffacts the-given-paths
    (path A B)
    (path B C)
    (path B D)
    (path D E)
    (path E F))

;the knowlage base
(defrule infer-indirect-paths
    (path ?begin ?temp)
    (path ?temp ?end)
    =>
    (assert (path ?begin ?end)))

(defrule print
    (path ?begin ?end)
    =>
    (printout t "There is a path from " ?begin " to " ?end crlf))