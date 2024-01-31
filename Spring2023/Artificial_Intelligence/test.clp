; Given the following family tree:
; Albert is the father of Tony and Andy
; Tony is the father of Allen and Newman
; Andy is the father of Mendy and Nancy
; Please find and display all cousins of a dynamically entered name.

;define templates
(deftemplate name-entered
    (slot name))
    
(deftemplate father-of
    (slot father)
    (slot child))

;the fact base
(deffacts the-family-tree
    (father-of (father Albert) (child Tony))
    (father-of (father Albert) (child Andy))
    (father-of (father Tony) (child Allen))
    (father-of (father Tony) (child Newman))
    (father-of (father Andy) (child Mendy))
    (father-of (father Andy) (child Nancy)))

;the knowledge base
(defrule get-name
    =>
    (printout t "Please enter a name: ")
    (assert (name-entered (name (read)))))
    
(defrule find-cousins
    (name-entered (name ?name))
    (father-of (father ?papa) (child ?name))
    (father-of (father ?grandpa) (child ?papa))
    (father-of (father ?grandpa) (child ?uncle&~?papa))
    (father-of (father ?uncle) (child ?cousin))
    =>
    (printout t ?cousin " is a cousin of " ?name crlf))