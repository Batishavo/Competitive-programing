/* Write your PL/SQL query statement below */
select 
    v.customer_id , 
    count(v.visit_id) as count_no_trans
from  
    Visits v
LEFT join 
    transactions t
ON 
    v.visit_id = t.visit_id  
where
    t.transaction_id IS NULL 
GROUP BY 
    v.customer_id