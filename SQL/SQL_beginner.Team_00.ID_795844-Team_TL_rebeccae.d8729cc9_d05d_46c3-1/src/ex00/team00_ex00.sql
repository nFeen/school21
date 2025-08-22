CREATE TABLE nodes
(
    point1 VARCHAR NOT NULL,
    point2 VARCHAR NOT NULL,
    cost INT NOT NULL
);

INSERT INTO nodes
VALUES ('a', 'b', 10),
       ('b', 'a', 10),
       ('b', 'c', 35),
       ('c', 'b', 35),
       ('a', 'c', 15),
       ('c', 'a', 15),
       ('a', 'd', 20),
       ('d', 'a', 20),
       ('b', 'd', 25),
       ('d', 'b', 25),
       ('d', 'c', 30),
       ('c', 'd', 30);

WITH RECURSIVE paths (path, last_point, total_cost) AS (
	SELECT
		ARRAY['a'] AS path,
		'a'::varchar AS last_point,
		0 AS total_cost
	UNION
	SELECT 
		paths.path || nodes.point2 AS path,
		nodes.point2 AS last_point,
		paths.total_cost + nodes.cost AS total_cost
	FROM paths
	JOIN nodes ON nodes.point1 = paths.last_point
		AND NOT nodes.point2 = ANY(paths.path)
),
full_tours AS (
	SELECT
		paths.total_cost + nodes.cost AS total_cost,
		paths.path || nodes.point2 AS tour
	FROM paths
	JOIN nodes ON nodes.point1 = paths.last_point
		AND nodes.point2 = 'a'
		AND cardinality(paths.path) = 4
)

SELECT * FROM full_tours
WHERE total_cost = (SELECT MIN(total_cost) FROM full_tours)
ORDER BY total_cost, tour;