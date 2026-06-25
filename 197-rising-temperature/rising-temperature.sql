# Write your MySQL query statement below
select a.id
from weather a
left join weather b
on a.recordDate=date_add(b.recordDate,interval 1 day) 
where a.temperature>b.temperature;