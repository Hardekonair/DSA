# Write your MySQL query statement below
select b.name
from employee a
left join employee b
on a.managerid=b.id
group by a.managerid,b.name
having count(b.id)>=5;