# Write your MySQL query statement below
delete b
from person a
join person b
where a.email=b.email and a.id<b.id;