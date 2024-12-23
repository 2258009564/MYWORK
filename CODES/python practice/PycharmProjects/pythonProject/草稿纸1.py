import pandas as pd

# 读取Excel文件
# 假设Excel文件名为'data.xlsx'，并且数据在第一个sheet中
df = pd.read_excel('C:\\Users\\22580\\Desktop\\龙凤微讯10-1~12-31.xlsx')

# 使用正则表达式来匹配"源"、"来源"或"供稿"以及它们后面跟随的所有字符
pattern = r'(源：|来源：|供稿/|来源:|源:)\s*(.*)'

# 应用正则表达式到E列，并提取包含关键词在内的文本信息
# 注意：第五列的索引是4，而不是5
df['Extracted'] = df.iloc[:, 4].str.extract(pattern)[0] + df.iloc[:, 4].str.extract(pattern)[1]

# 指定输出文件的路径
output_path = 'a1-666.xlsx'

# 将DataFrame保存到Excel文件
df.to_excel(output_path, index=False)

print(f"Data has been saved to {output_path}")
