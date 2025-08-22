-- Session 1
BEGIN;
UPDATE pizzeria
SET rating = 4
WHERE name = 'Pizza Hut';
UPDATE pizzeria
SET rating = 4
WHERE name = 'Dominos';
COMMIT;
-- Session 2
BEGIN;
UPDATE pizzeria
SET rating = 3
WHERE name = 'Dominos';
UPDATE pizzeria
SET rating = 3
WHERE name = 'Pizza Hut';
COMMIT;