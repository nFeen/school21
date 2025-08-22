SELECT
	p.address,
	pi.name,
	COUNT(*) AS count_of_orders
FROM person p
JOIN person_order po ON po.person_id = p.id
JOIN menu ON menu.id = po.menu_id
JOIN pizzeria pi ON pi.id = menu.pizzeria_id
GROUP BY p.address, pi.name
ORDER BY p.address, pi.name;