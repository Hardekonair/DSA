# Write your MySQL query statement below
-- select product_id,new_price as price
select distinct a.product_id,ifnull(b.new_price,10) as price
from products a
left join (
    select product_id,new_price
    from products
    where (product_id,change_date) in (
        select product_id,max(change_date)
        from products
        where change_date<='2019-08-16' 
        group by product_id
    )
) b
on a.product_id=b.product_id