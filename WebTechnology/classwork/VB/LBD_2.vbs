dim a
a = 60000
tax = a * 20/100
r = a * 5/100
a = a - tax - r - 200
msg = "Adams receives $" & a & " amount as monthly salary after all deductions"
MsgBox msg,vbOkOnly + vbInformation

