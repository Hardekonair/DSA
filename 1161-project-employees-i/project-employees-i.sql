# Write your MySQL query statement below
select project_id,round(sum(experience_years) /count(a.project_id),2) as average_years
-- select *
from project as a
left join employee as b
on a.employee_id=b.employee_id
group by project_id;