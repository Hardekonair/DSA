# Write your MySQL query statement below

select contest_id,round(count(a.contest_id)/(select count(*) from users) *100,2) as percentage
from register as a
left join users as b
on a.user_id=b.user_id
group by a.contest_id
order by percentage desc,a.contest_id asc;