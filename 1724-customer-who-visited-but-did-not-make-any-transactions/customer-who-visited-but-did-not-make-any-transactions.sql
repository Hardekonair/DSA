# Write your MySQL query statement below

select visits.customer_id,count(*) as count_no_trans
from visits
left join transactions
on visits.visit_id=transactions.visit_id
where transaction_id is null
group by visits.customer_id
order by count_no_trans desc;