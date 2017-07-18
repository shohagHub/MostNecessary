declare
v_first_name varchar(35);
v_last_name varchar(35);
v_counter NUMBER := 0;

begin
	select first_name, last_name
		into v_first_name, v_last_name
		from employees
		where email = 'WSMITHss';
dbms_output.put_line('Employee name:' || v_first_name || ' ' || v_last_name);

exception
	when no_data_found then
	dbms_output.put_line('There is no data with employees');
end;
/