# Write your MySQL query statement below
SELECT employee_id,department_id
from employee
where primary_flag='Y'
group by employee_id

union

SELECT employee_id,department_id
from employee 
group by employee_id
having count(employee_id)=1;