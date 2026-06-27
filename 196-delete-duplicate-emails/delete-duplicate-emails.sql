# Write your MySQL query statement below
delete a
from person a
left join person b
on a.email=b.email where a.id>b.id;
