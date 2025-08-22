SELECT name AS pizzeria_name
FROM pizzeria
WHERE id IN (
	(SELECT pv.pizzeria_id
	FROM person_visits pv
	JOIN person ON pv.person_id = person.id
	WHERE person.gender = 'female'
	EXCEPT ALL
	SELECT pv.pizzeria_id
	FROM person_visits pv
	JOIN person ON pv.person_id = person.id
	WHERE person.gender = 'male')

	UNION ALL

	(SELECT pv.pizzeria_id
	FROM person_visits pv
	JOIN person ON pv.person_id = person.id
	WHERE person.gender = 'male'
	EXCEPT ALL
	SELECT pv.pizzeria_id
	FROM person_visits pv
	JOIN person ON pv.person_id = person.id
	WHERE person.gender = 'female')
)
ORDER BY pizzeria_name;