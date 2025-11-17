# Write your MySQL query statement below
select tweet_id
from tweets
-- where content LIKE "________________%";
where length(content)>15;