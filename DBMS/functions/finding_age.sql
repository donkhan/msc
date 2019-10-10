-- finding leap Year
create or replace function is_leap(y int) returns int begin declare t int; set t = 0; if y%400 =0 then return 1; end if; if y % 100 = 0 then return 0; end if; if y%4 = 0 then return 1; end if; return t; end |

-- Elapsed days between two years (excluding y1 and y2)

create or replace function ydays(y1 int,y2 int) returns int begin declare ydays int; set ydays = 0; set y1 = y1 + 1; set y2 = y2 -1; ll: LOOP if y1 > y2 then leave ll; else if is_leap(y1) = 1 then set ydays = ydays + 366; else set ydays = ydays + 365; end if; set y1 = y1 + 1; iterate ll; end if; END LOOP; return ydays; end |

-- no of days in month

create or replace function no_of_days_in_month(i int,year int) returns int begin if i = 1 or i = 3 or i = 5 or i = 7 or i = 8 or i = 10 or i = 12 then return 31; end if; if i =4 or i = 6 or i = 9 or i = 11 then return 30; end if; if i = 2 and is_leap(year) then return 29; else return 28; end if; end |

create or replace function m_l(d date) returns int begin declare mdays,m int; set m = month(d) + 1; set mdays = 0; ll:LOOP if m > 12 then leave ll; else set mdays = mdays + no_of_days_in_month(m,year(d)); set m = m + 1; iterate ll; end if; END LOOP; return mdays; end |

create or replace function m_s(d date) returns int begin declare mdays,m int; set m = 1; set mdays = day(d);  ll:LOOP if m >= month(d) then leave ll; else set mdays = mdays + no_of_days_in_month(m,year(d)); set m = m + 1; iterate ll; end if; END LOOP; return mdays; end |

--Age Function
create or replace function age(dob date) returns int begin declare now date; set now = now(); return floor( (ydays(year(dob),year(now)) + m_l(dob) + m_s(now)) /365 ); end |



-- Much Simpler Function. Needs to understand looping and declaration

create or replace function age_x(dob date) returns int begin declare n date; declare days int; set days = 0; set n = now(); ll : LOOP if dob > n  then leave ll; else set dob = date_add(dob, INTERVAL 1 day); set days = days + 1; iterate ll;  end if;  END LOOP; return days - 1; end 
