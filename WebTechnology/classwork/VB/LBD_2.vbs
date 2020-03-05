dim Name,GrossMonthlySalary,TaxRate,RetirementContribution
dim MonthlyTaxes,MonthlyRetirementContribution,MonthlyHealthPayment
dim MonthlyNetSalary
GrossMonthlySalary = 60000
TaxRate = 20/100
RetirementContribution = 5/100
MonthlyTaxes = GrossMonthlySalary * TaxRate
MonthlyRetirementContribution = GrossMonthlySalary * RetirementContribution
MonthlyHealthPayment = 200
MonthlyNetSalary = GrossMonthlySalary - MonthlyTaxes - MonthlyRetirementContribution - MonthlyHealthPayment
Name = "Adams"
msg = Name & " receives $" & MonthlyNetSalary & " amount as monthly salary after all deductions"
MsgBox msg,vbOkOnly + vbInformation

