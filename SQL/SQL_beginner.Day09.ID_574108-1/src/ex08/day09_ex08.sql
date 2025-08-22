CREATE FUNCTION fnc_fibonacci(pstop integer DEFAULT 10)
RETURNS SETOF integer AS
$$
	WITH RECURSIVE fibo(one, two) AS (
		SELECT 0, 1
		UNION ALL
		SELECT one + two, one
		FROM fibo
		WHERE one + two < pstop
	)
	SELECT one FROM fibo OFFSET 1;
$$ LANGUAGE sql;

SELECT * FROM fnc_fibonacci(100);
SELECT * FROM fnc_fibonacci();
