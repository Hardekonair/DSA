# Write your MySQL query statement below
select a.product_name,sum(b.unit) as unit
from products a
join orders b
on a.product_id = b.product_id
where date_format(b.order_date,'%Y%m')='202002'
group by b.product_id
having sum(b.unit)>=100;