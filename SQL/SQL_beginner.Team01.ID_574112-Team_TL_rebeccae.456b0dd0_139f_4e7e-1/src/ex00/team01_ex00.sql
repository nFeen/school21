WITH latest_currency AS (
	SELECT
		c.id,
		c.name,
		c.rate_to_usd,
		c.updated
	FROM currency c
	WHERE c.updated = (SELECT MAX(updated) FROM currency WHERE id = c.id)
)

SELECT
	COALESCE(u.name, 'not defined') AS name,
	COALESCE(u.lastname, 'not defined') AS lastname,
	b.type,
	SUM(b.money) AS volume,
	COALESCE(lc.name, 'not defined') AS currency_name,
	COALESCE(lc.rate_to_usd, 1) AS last_rate_to_usd,
	SUM(b.money) * COALESCE(lc.rate_to_usd, 1) AS total_volume_in_usd
FROM balance b
LEFT JOIN "user" u ON u.id = b.user_id
LEFT JOIN latest_currency lc ON b.currency_id = lc.id
GROUP BY
	u.name,
	u.lastname,
	u.id,
	b.type,
	lc.name,
	lc.rate_to_usd
ORDER BY
	name DESC,
	lastname ASC,
	type ASC;