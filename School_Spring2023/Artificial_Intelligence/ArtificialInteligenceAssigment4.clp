; Given the following family tree:
; Albert is the father of Tony and Andy
; Tony is the father of Allen and Newman
; Andy is the father of Mendy and Nancy
; Please find and display all cousins of a dynamically entered name.

(deffacts name-entered-facts)

(deffacts father-of-facts
    (father-of Albert Tony)
    (father-of Albert Andy)
    (father-of Tony Allen)
    (father-of Tony Newman)
    (father-of Andy Mendy)
    (father-of Andy Nancy))

(defrule get-name
  =>
  (printout t "Please enter a name: ")
  (assert (name-entered (read))))

(defrule find-cousins
  ; Match against a name-entered fact with a name slot
  (name-entered (name ?name))
  ; Find the father of the given name
  (father-of ?papa ?name)
  ; Find the grandfather of the given name
  (father-of ?grandpa ?papa)
  ; Find an uncle of the given name who is not the father
  (father-of ?uncle&~?papa ?cousin)
  ; Find the father of the uncle, who is the grandfather of the cousin
  (father-of ?grandpa ?uncle)
  ; Print out the result
  =>
  (printout t ?cousin " is a cousin of " ?name crlf))