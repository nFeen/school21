insert into currency values (100, 'EUR', 0.85, '2022-01-01 13:29');
insert into currency values (100, 'EUR', 0.79, '2022-01-08 13:29');

SELECT
  COALESCE(u.name, 'not defined')     AS name,
  COALESCE(u.lastname, 'not defined') AS lastname,
  COALESCE(t1.name, t2.name)          AS currency_name,
  b.money * COALESCE(t1.rate_to_usd, t2.rate_to_usd) AS currency_in_usd
FROM balance b
LEFT JOIN "user" u ON u.id = b.user_id
LEFT JOIN LATERAL (
  SELECT c.name, c.rate_to_usd
  FROM currency c
  WHERE c.id = b.currency_id
    AND c.updated <= b.updated
  ORDER BY c.updated DESC
  LIMIT 1
) t1 ON true
LEFT JOIN LATERAL (
  SELECT c.name, c.rate_to_usd
  FROM currency c
  WHERE c.id = b.currency_id
    AND c.updated > b.updated
  ORDER BY c.updated ASC
  LIMIT 1
) t2 ON t1.rate_to_usd IS NULL
WHERE COALESCE(t1.rate_to_usd, t2.rate_to_usd) IS NOT NULL
ORDER BY name DESC, lastname ASC, currency_name ASC;



