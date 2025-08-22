SELECT person.name
FROM person
JOIN person_order ON person_order.person_id = person.id
JOIN menu ON person_order.menu_id = menu.id
WHERE gender = 'male' AND (address = 'Moscow' OR address = 'Samara')
	AND (menu.pizza_name ILIKE '%mushroom%' OR menu.pizza_name ILIKE '%pepperoni%')
ORDER BY person.name DESC;