# Write your MySQL query statement below
select round(count(player_id)/(select count(distinct player_id) from activity),2) as fraction
from activity
where (player_id,date_sub(event_date,Interval 1 day)) IN (select player_id,min(event_date)
from activity
group by player_id);
