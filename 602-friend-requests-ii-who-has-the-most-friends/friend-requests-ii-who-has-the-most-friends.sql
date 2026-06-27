# Write your MySQL query statement below
select a.id,count(a.id) as num
from (

    select requester_id as id
    from requestaccepted

    union all

    select accepter_id as id
    from requestaccepted
) as a
group by a.id
order by count(a.id ) desc
limit 1;