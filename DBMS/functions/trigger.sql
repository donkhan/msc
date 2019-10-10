create or replace trigger ins_sum after insert on coach for each row set @total = @total + new.salary;



create or replace trigger dec_sum after delete on coach for each row set @total = @total - old.salary;
