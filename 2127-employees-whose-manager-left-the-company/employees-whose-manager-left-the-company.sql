# Write your MySQL query statement below
select a.employee_id
from employees a
left join employees b
on a.manager_id=b.employee_id
where b.employee_id is null and a.salary<30000 and a.manager_id is not null
order by employee_id