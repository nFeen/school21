INSERT INTO person_order (id, person_id, menu_id, order_date)
SELECT
    gs.id,
    p.id,
    m.id,
    DATE '2022-02-25'
FROM (
    SELECT 
        generate_series(
            (SELECT MAX(id) + 1 FROM person_order),
            (SELECT MAX(id) + (SELECT COUNT(*) FROM person) FROM person_order)
        ) AS id
) AS gs,
LATERAL (
    SELECT id
    FROM person
    LIMIT 1 OFFSET gs.id - (SELECT MAX(id) + 1 FROM person_order)
) AS p
CROSS JOIN (SELECT id FROM menu WHERE pizza_name = 'greek pizza') AS m;
