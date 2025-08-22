(select
	pizzeria.name,
	count(*),
	'order' as action_type
from person_order po
join menu on po.menu_id = menu.id
join pizzeria on menu.pizzeria_id = pizzeria.id
group by pizzeria.name
order by count desc
limit 3)

union all

(select
	pizzeria.name,
	count(*),
	'visit' as action_type
from person_visits pv
join pizzeria on pizzeria.id = pv.pizzeria_id
group by pizzeria.name
order by count desc
limit 3)

order by action_type asc, count desc;