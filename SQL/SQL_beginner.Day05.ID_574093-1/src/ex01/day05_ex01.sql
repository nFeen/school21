SET enable_seqscan TO OFF;
EXPLAIN ANALYZE
SELECT pizza_name, pizzeria.name AS pizzeria_name
FROM menu
JOIN pizzeria ON pizzeria_id = pizzeria.id;
SET enable_seqscan TO ON;