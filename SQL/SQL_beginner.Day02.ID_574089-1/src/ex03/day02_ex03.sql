WITH day_generator AS (
    SELECT generate_series(DATE '2022-01-01', DATE '2022-01-10', INTERVAL '1 day')::date AS day
),
visits_filtered AS (
    SELECT visit_date
    FROM person_visits
    WHERE person_id = 1 OR person_id = 2
)
SELECT dg.day AS missing_date
FROM day_generator dg
LEFT JOIN visits_filtered v ON dg.day = v.visit_date
WHERE v.visit_date IS NULL
ORDER BY missing_date;
