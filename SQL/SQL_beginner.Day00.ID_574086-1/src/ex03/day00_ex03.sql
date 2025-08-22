SELECT DISTINCT person_id
FROM person_visits
WHERE visit_date 
BETWEEN DATE '2022-01-06' AND DATE '2022-01-09'
OR pizzeria_id = 2
ORDER BY person_id DESC;