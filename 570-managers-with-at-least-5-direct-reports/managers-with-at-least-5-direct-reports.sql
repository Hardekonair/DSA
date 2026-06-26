# Write your MySQL query statement below
select b.name
from employee a
left join employee b
on a.managerid=b.id
group by b.id,b.name
having count(b.id)>=5;