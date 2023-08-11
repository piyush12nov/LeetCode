select uni.unique_id,e.name from  EmployeeUNI uni
right join Employees e
on uni.id=e.id;