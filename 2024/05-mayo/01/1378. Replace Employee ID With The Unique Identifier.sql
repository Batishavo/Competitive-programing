/* Write your PL/SQL query statement below */
SELECT 
    epi.unique_id, 
    ep.name
FROM 
    Employees ep 
LEFT JOIN 
    EmployeeUNI epi ON ep.id = epi.id;