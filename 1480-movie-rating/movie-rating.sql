# Write your MySQL query statement below
(select a.name as results
from users a
left join movierating b
on a.user_id=b.user_id
group by a.user_id
order by count(b.rating) desc,a.name
limit 1)

union all
(
select a.title as results
from movies a
left join movierating b
on a.movie_id=b.movie_id
where Date_format(b.created_At,'%Y-%m')='2020-02'
group by a.movie_id
order by avg(b.rating) desc,a.title
limit 1)