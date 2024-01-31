;CLIPS program that displays all students whos major is CS
;Jared See
;Artifical Inteligence
;Due March 16

(deftemplate student
    (slot name)
    (slot major))

(deffacts students
    (student (name "Albert") (major "CS"))
    (student (name "Henry") (major "EE"))
    (student (name "Tony") (major "CE"))
    (student (name "Rose") (major "CS")))

(defrule find-cs-students
    (student (name ?name)(major "CS"))
    =>
    (printout t ?name " is a CS major" crlf))