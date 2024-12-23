import os
#os模块调用可执行文件
os.system('ping www.baidu.com')
#os模块访问系统信息
print(os.name)  # 返回操作系统的相关信息
print(os.sep)  #  路径分隔符
print(repr(os.linesep))  #  行终止符 repr将对象转化为字符串，并保留原来的格式 包括空格，换行符等。



