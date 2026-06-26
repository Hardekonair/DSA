# Write your MySQL query statement below
select b.employee_id, b.name,count(a.reports_to) as reports_count,round(sum(a.age)/count(*)) as average_age
from employees a
left join employees b
on a.reports_to = b.employee_id
group by a.reports_to
having count(a.reports_to)>0
order by employee_id;