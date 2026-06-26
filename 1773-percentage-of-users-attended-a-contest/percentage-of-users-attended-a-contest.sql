# Write your MySQL query statement below
select b.contest_id,round(count(contest_id)*100/(select count(*) from users),2) as percentage
from register b
group by b.contest_id
order by percentage desc,contest_id;