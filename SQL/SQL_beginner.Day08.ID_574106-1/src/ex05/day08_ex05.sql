-- Session 1
SHOW TRANSACTION ISOLATION LEVEL;
BEGIN;
SELECT SUM(rating) FROM pizzeria;
SELECT SUM(rating) FROM pizzeria;
COMMIT;
SELECT SUM(rating) FROM pizzeria;

-- Session 2
SHOW TRANSACTION ISOLATION LEVEL;
BEGIN;
INSERT INTO pizzeria(id, name, rating)
VALUES (10, 'Kazan Pizza', 5);
COMMIT;
SELECT SUM(rating) FROM pizzeria;