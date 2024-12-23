import xlrd
from xlutils.copy import copy

# 读取excel文件
workbook = xlrd.open_workbook('new excel.xls')
new_workbook = copy(workbook) #复制workbook
sheet1 = new_workbook.get_sheet(0) #获取第一个工作表
# 修改excel文件
sheet1.write(0, 0, '修改后的内容')
new_workbook.save('new excel 1.xls') #保存文件
