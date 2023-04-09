; Given the following family tree:
; Albert is the father of Tony and Andy
; Tony is the father of Allen and Newman
; Andy is the father of Mendy and Nancy
; Please find and display all cousins of a dynamically entered name.
; Jared See
; Assignmet 4
; Due March 28


;define family tree
(deffacts the-family-tree
  (father-of Albert Tony)
  (father-of Albert Andy)
  (father-of Tony Allen)
  (father-of Tony Newman)
  (father-of Andy Mendy)
  (father-of Andy Nancy))

;define get-name
(defrule get-name
  =>
  (printout t "Please enter a name: ")
  (assert (name-entered (read))))

;find the cousins
(defrule find-cousins
  (name-entered ?name)
  (father-of ?papa ?name)
  (father-of ?grandpa ?papa)
  (father-of ?grandpa ?uncle&~?papa)
  (father-of ?uncle ?cousin)
  =>
  (printout t ?cousin " is a cousin of " ?name crlf))