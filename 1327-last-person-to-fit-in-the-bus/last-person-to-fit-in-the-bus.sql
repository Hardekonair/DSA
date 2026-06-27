-- select * /
select a.person_name as person_name
from queue a
inner join queue b
on a.turn>=b.turn
group by a.person_id
having sum(b.weight)<=1000
order by a.turn desc
limit 1