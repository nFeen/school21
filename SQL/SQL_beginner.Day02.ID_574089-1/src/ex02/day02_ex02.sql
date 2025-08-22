SELECT 
	COALESCE(person.name, '-') AS person_name,
	COALESCE(pv.visit_date, NULL) AS visit_date,
	COALESCE(pizzeria.name, '-') AS pizzeria_name
FROM person
FULL OUTER JOIN (
	SELECT person_id, visit_date, pizzeria_id
	FROM person_visits
	WHERE visit_date BETWEEN DATE '2022-01-01' AND DATE '2022-01-03'
) AS pv ON pv.person_id = person.id
FULL OUTER JOIN pizzeria ON pv.pizzeria_id = pizzeria.id
ORDER BY person_name, pv.visit_date, pizzeria_name;
