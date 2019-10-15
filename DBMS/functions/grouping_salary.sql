create or replace function g(salary int) returns varchar(20) begin if salary < 90000 then return "Group A"; end if; return "Group B"; end |
