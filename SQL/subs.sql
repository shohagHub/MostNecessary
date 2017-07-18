/*Substitution varaible*/
declare
v_first_name varchar(20);
BEGIN
select first_name into v_first_name from employees
where employee_id = &v_employee_id;
dbms_output.put_line('Saleh Enam Shohag');
dbms_output.put_line
	('Employee name ' || v_first_name );
END;
/