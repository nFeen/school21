WITH pizzerias_with_male AS (
	SELECT DISTINCT menu.pizzeria_id
	FROM menu
	JOIN person_order ON menu.id = person_order.menu_id
	JOIN person ON person_order.person_id = person.id
	WHERE person.gender = 'male'
),
pizzerias_with_female AS (
	SELECT DISTINCT menu.pizzeria_id
	FROM menu
	JOIN person_order ON menu.id = person_order.menu_id
	JOIN person ON person_order.person_id = person.id
	WHERE person.gender = 'female'
)

SELECT name AS pizzeria_name
FROM pizzeria
WHERE id IN (SELECT * FROM pizzerias_with_female)
	AND id NOT IN (SELECT * FROM pizzerias_with_male)

UNION

SELECT name AS pizzeria_name
FROM pizzeria
WHERE id IN (SELECT * FROM pizzerias_with_male)
	AND id NOT IN (SELECT * FROM pizzerias_with_female)

ORDER BY pizzeria_name;

