import xlwt

#使用xlwt模块创建excel文件
workbook = xlwt.Workbook()  #创建工作簿
sheet = workbook.add_sheet('Sheet1')  #创建工作表
sheet.write(0, 0, 'Hello')  #写入数据
workbook.save('new excel.xls')  #保存文件
