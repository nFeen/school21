SELECT
	pi.name,
	COUNT(*) AS count_of_orders,
	ROUND(AVG(menu.price), 2) AS average_price,
	MAX(menu.price) AS max_price,
	MIN(menu.price) AS min_price
FROM menu
JOIN pizzeria pi ON pi.id = menu.pizzeria_id
JOIN person_order po ON po.menu_id = menu.id
GROUP BY pi.name
ORDER BY pi.name;