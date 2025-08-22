SELECT
	person.id AS person_id,
	person.name AS person_name,
	person.age AS person_age,
	person.gender AS person_gender,
	person.address AS person_address,
	pizzeria.id AS pizzeria_id,
	pizzeria.name AS pizzeria_name,
	pizzeria.rating AS pizzeria_rating
FROM person
CROSS JOIN pizzeria
ORDER BY person_id, pizzeria_id;