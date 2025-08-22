SELECT DISTINCT pizzeria.name AS pizzeria_name
FROM person_visits
JOIN person ON person_visits.person_id = person.id
JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
JOIN menu ON menu.pizzeria_id = pizzeria.id
WHERE person_visits.visit_date = DATE '2022-01-08'
	AND person.name = 'Dmitriy'
	AND menu.price < 800;