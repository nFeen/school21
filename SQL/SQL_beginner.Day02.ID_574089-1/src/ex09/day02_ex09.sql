SELECT name
FROM person
WHERE gender = 'female'
	AND id IN (
		SELECT p1.id
		FROM person p1
		JOIN person_order po1 ON po1.person_id = p1.id
		JOIN menu m1 ON po1.menu_id = m1.id
		WHERE m1.pizza_name ILIKE '%pepperoni%'
		
		INTERSECT
		
		SELECT p2.id
		FROM person p2
		JOIN person_order po2 ON po2.person_id = p2.id
		JOIN menu m2 ON po2.menu_id = m2.id
		WHERE m2.pizza_name ILIKE '%cheese%'
	)
ORDER BY name;