# Write your MySQL query statement below
select distinct a.num as ConsecutiveNums
from logs a
left join logs b
on a.id=b.id-1
left join logs c
on c.id=b.id+1
where a.num=b.num and b.num=c.num;