SELECT
	person.name,
	COUNT(*) AS count_of_visits
FROM person_visits pv
JOIN person ON pv.person_id = person.id
GROUP BY person.name
HAVING COUNT(*) > 3;