with visits_and_orders as (
	select
		pizzeria.name,
		count(*)
	from person_order po
	join menu on po.menu_id = menu.id
	join pizzeria on menu.pizzeria_id = pizzeria.id
	group by pizzeria.name
	union all
	select
		pizzeria.name,
		count(*)
	from person_visits pv
	join pizzeria on pizzeria.id = pv.pizzeria_id
	group by pizzeria.name
)

select
	name,
	sum(count) as total_count
from visits_and_orders
group by name
order by total_count desc, name asc;