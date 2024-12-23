import numpy as np

#创建数组
arr1 = np.array([1, 3, 5])
arr2 = np.array([[3, 5, 7], [2, 4, 6]])
'''arr1是一维数组，arr2是二维数组
可以简单的通过前面有几个方括号来判断
'''

'''np.array([[3, 5], [2, 4, 6]])
会报错
因为不符合二维数组的定义
'''

print(arr1.ndim)
print(arr2.ndim)  #数组的维度
'''...'''
print(arr1.shape)
print(arr2.shape)  #返回一个元组，表示各个维度的元素的个数

print(arr1.size)
print(arr2.size)  #返回数组中元素的总个数

print(arr1.dtype)
print(arr2.dtype)  #返回数组元素的类型  int64 代表六十四位整数

#其他创建数组的方法
print(np.zeros(3))  #返回[0. 0. 0.] 长度为3的0
print(np.ones(5))  #返回[1. 1. 1. 1. 1.] 长度为5的1
'''有小数点是因为类型是浮点数'''

print(np.arange(5, 10, 2))
#可以跟range类比

'''链接数组'''
arr3 = np.arange(3, 10, 2)
arr4 = np.zeros(4)
print(arr3, arr4)
print(np.concatenate([arr3, arr4]))

'''对列表排序有两个选择'''
list1 = [5, 2, 10]
'''函数sorted() 特点是需要赋值给一个新列表 不改变原来的列表'''
list1_sorted = sorted(list1)
'''方法.sort 特点是不返回任何结果 改变原来的列表'''
list1.sort() #此时列表已经被排序

'''与之类似的，numpy库也有这两个选择'''
arr5 = np.array([5, 3, 9, 4])
arr5_sorted = np.sort(arr5)  #函数
arr5.sort()  #方法

