SELECT
	person.name,
	menu.pizza_name,
	menu.price,
	ROUND(menu.price * (100 - pd.discount) / 100, 2) AS discount_price,
	pizzeria.name AS pizzeria_name
FROM person
JOIN person_discounts pd ON pd.person_id = person.id
JOIN pizzeria ON pd.pizzeria_id = pizzeria.id
JOIN menu ON menu.pizzeria_id = pizzeria.id
ORDER BY person.name, menu.pizza_name;
