# Write your MySQL query statement below
-- select a.user_id,round(count(b.action)/count(a.user_id),2) as confirmation_rate
select a.user_id,round(count(case when b.action='confirmed' then 1 end)/count(a.user_id),2) as confirmation_rate
-- select *
from signups a
left join confirmations b
on a.user_id=b.user_id
-- where b.action='confirmed'
group by a.user_id,b.user_id;