SELECT name AS pizzeria_name FROM pizzeria
WHERE id IN (
	SELECT DISTINCT pizzeria_id
	FROM person_visits
	JOIN person ON person.id = person_visits.person_id
	WHERE person.name = 'Andrey'
	
	EXCEPT
	
	SELECT DISTINCT menu.pizzeria_id
	FROM menu
	JOIN person_order ON person_order.menu_id = menu.id
	JOIN person ON person_order.person_id = person.id
	WHERE person.name = 'Andrey'
)
ORDER BY pizzeria_name;
