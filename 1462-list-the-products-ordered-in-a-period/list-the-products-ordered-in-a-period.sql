# Write your MySQL query statement below
select a.product_name,sum(b.unit) as unit
from products a
join orders b
on a.product_id=b.product_id
where b.order_date between '2020-02-01' and '2020-02-29'
group by b.product_id
having sum(b.unit)>=100;