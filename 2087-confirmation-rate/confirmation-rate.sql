# Write your MySQL query statement below
select a.user_id,round(count(case when b.action='confirmed' then 1 end)/count(a.user_id),2) as confirmation_rate
from signups a
left join confirmations b
on a.user_id=b.user_id
group by a.user_id;