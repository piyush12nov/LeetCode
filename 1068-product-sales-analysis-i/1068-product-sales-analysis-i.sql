select product_name,year,price from Sales s
left join Product ss
on s.product_id=ss.product_id;