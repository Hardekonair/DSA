select 
    case
        when id=(select max(id) from seat) and mod(id,2)=1  -- if row number is the last row then no change
        then id

        when mod(id,2)=1    -- meaning the odd row no. becomes even, i.e next
        then id+1

        else                -- if row no. is even, it goes up to make the swap
            id-1
    end as id,student
from seat
order by id