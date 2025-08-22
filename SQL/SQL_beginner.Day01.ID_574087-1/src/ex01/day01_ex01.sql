SELECT object_name
FROM (
	SELECT 
		pizza_name AS object_name, 2 AS sort_order
	FROM menu
	UNION ALL
	SELECT
		name AS object_name, 1 AS sort_order
	FROM person
	ORDER BY sort_order, object_name
)