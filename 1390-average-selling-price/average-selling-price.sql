# Write your MySQL query statement below
select a.product_id,ifnull(round(sum(b.units*a.price)/sum(b.units),2),0) as average_price
from prices a
left join unitssold b
on a.product_id=b.product_id
-- where b.purchase_date between a.start_date and a.end_date
and b.purchase_date between a.start_date and a.end_date
group by a.product_id;