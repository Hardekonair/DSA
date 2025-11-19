# Write your MySQL query statement below
-- select a1.machine_id, round(avg(a2.timestamp-a1.timestamp),3) as processing_time
-- from activity a1
-- join activity a2
-- on a1.machine_id=a2.machine_id and a1.process_id=a2.process_id
-- where a1.activity_type='start' and a2.activity_type='end'
-- group by machine_id;
select machine_id,round(avg(diff),3) as processing_time
from(
    select machine_id,process_id,
    sum(case when activity_type='end' then timestamp end)-
    sum(case when activity_type='start' then timestamp END) as diff
    from activity
    group by machine_id,process_id
) x
group by machine_id;