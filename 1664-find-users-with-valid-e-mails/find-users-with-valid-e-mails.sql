# Write your MySQL query statement below
select * from users
where regexp_LIKE(mail,'^[a-zA-Z][A-Za-z0-9_\.\-]*@leetcode[.]com$','c')