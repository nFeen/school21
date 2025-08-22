SELECT 
    po.order_date,
    p.name || ' (age:' || p.age || ')' AS person_information
FROM (
	SELECT id AS person_id, name, age
	FROM person 
) AS p
NATURAL JOIN person_order po
ORDER BY po.order_date ASC, person_information ASC;