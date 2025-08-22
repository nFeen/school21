SELECT DISTINCT
	person.name
FROM person_order po
JOIN person ON person.id = po.person_id
ORDER BY person.name;