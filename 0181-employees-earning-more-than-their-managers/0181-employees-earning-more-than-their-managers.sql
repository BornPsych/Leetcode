select name as Employee from Employee as emp where salary > (select salary from Employee where id = emp.managerId);