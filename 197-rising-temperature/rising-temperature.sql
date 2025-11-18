# Write your MySQL query statement below
select w1.id
from weather as w1 
join weather as w2
on w1.recorddate=DATE_ADD(w2.recorddate,INTERVAL 1 DAY)
where w1.temperature>w2.temperature;