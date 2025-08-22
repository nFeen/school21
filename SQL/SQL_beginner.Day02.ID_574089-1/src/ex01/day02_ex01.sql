SELECT gs.day::date AS missing_date
FROM generate_series(DATE '2022-01-01', DATE '2022-01-10', INTERVAL '1 day') AS gs(day)
LEFT JOIN (
	SELECT visit_date
	FROM person_visits
	WHERE person_id = 1 OR person_id = 2
) AS visits ON gs.day = visit_date
WHERE visit_date IS NULL
ORDER BY visit_date;