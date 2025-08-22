SELECT 
	person.name,
	COUNT(*) AS count_of_visits
FROM person_visits pv
JOIN person ON person.id = pv.person_id
GROUP BY person.name
ORDER BY count_of_visits DESC, person.name ASC
LIMIT 4;