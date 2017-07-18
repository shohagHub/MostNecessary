/*find employee*/
declare
	v_employee_id NUMBER := &v_employee_id;
	v_first_name varchar(20);
	v_last_name varchar(25);

BEGIN
	SELECT first_name, last_name
	INTO v_first_name, v_last_name
	FROM employees
	WHERE employee_id = v_employee_id;
	dbms_output.put_line
	('Employee name ' || v_first_name ||' '||v_last_name);
	
exception
when no_data_found then
	dbms_output.put_line('There is no employee with the id 123');
end;
/